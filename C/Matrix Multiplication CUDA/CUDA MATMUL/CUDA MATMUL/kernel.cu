
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include <math.h>

void MatMulNoTiling(float* A, int Ax, int Ay, float* B, int Bx, int By);
void MatMulWithTiling(float* A, int Ax, int Ay, float* B, int Bx, int By);
void printValues(float* A, int Ax, int Ay);
__global__ void MatMulNoTilingKer(float* d_A, float* d_B, float* d_res, int Bx, int Ay, int Ax);
__global__ void MatMulWithTilingKer(float* d_A, float* d_B, float* d_res, int Bx, int Ay, int Ax);

int main()
{

	//Initialize dimensions of input arrays
	int Ax = 3;
	int Ay = 2;

	int Bx = 4;
	int By = 3;

	if (Ax != By)
		printf("Ax must be equal to By");

	float* A = (float*)malloc((Ax * Ay) * sizeof(float));

	float* B = (float*)malloc((Bx * By) * sizeof(float));

	//Initialize values of A sequentially
	if (A != NULL) {
		for (int i = 0; i < (Ax * Ay); i++)
		{
			//Enter the numbers into A and B's elements
			A[i] = i + 1;
			
		}

	}

	//Initialize values of B sequentially
	if (B != NULL) {
		for (int i = 0; i < (Bx * By); i++)
		{
			//Enter the numbers into A and B's elements
			B[i] = i + 1;

		}

	}

	printValues(A, Ax, Ay);

	printf("\n Multiplied By \n\n");

	printValues(B, Bx, By);

	printf("\n");

	time_t start = clock();

	/*

	MatMulNoTiling(A, Ax, Ay, B, Bx, By);

	time_t passed = 1000 * (clock() - start) / CLOCKS_PER_SEC;

	printf("\nExecution time (ms) without tiling: %d", passed);

	*/

	start = clock();

	MatMulWithTiling(A, Ax, Ay, B, Bx, By);

	time_t passed = 1000 * (clock() - start) / CLOCKS_PER_SEC;

	printf("\nExecution time (ms) with tiling: %d", passed);

	free(A);
	free(B);

	return 0;

}


void printValues(float* A, int Ax, int Ay) {

	for (int y = 0; y < Ay; y++)
	{
		for (int x = 0; x < Ax; x++)
			printf("%9.6f \t", A[x + y * Ax]);


		printf("\n");

	}

}




void MatMulNoTiling(float* A, int Ax, int Ay, float* B, int Bx, int By) 
{

	//Declare result matrix
	float* res = (float*)malloc((Ay * Bx) * sizeof(float));

	//Allocate memory on device
	float* d_res, *d_A, *d_B;
	cudaMalloc(&d_res, Ay * Bx * sizeof(float));
	cudaMalloc(&d_A, Ax * Ay * sizeof(float));
	cudaMalloc(&d_B, Bx * By * sizeof(float));

	//Copy values to device memory
	cudaMemcpy(d_A, A, Ax * Ay * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, B, Bx * By * sizeof(float), cudaMemcpyHostToDevice);



	//Get number of blocks in x direction
	int n_blocksx = ceil((double)Bx / 1024);

	int n_blocksy = Ay;

	const dim3 blockSize(1024, 1, 1);

	const dim3 gridSize(n_blocksx, n_blocksy, 1);


	MatMulNoTilingKer << <gridSize, blockSize >> > (d_A, d_B, d_res, Bx, Ay, Ax);
	

	cudaMemcpy(res, d_res, Ay * Bx * sizeof(float), cudaMemcpyDeviceToHost);

	printValues(res, Bx, Ay);

	free(res);

}


//Kernel function for matrix multiplication without tiling
__global__ void MatMulNoTilingKer(float* d_A, float* d_B, float* d_res, int Bx, int Ay, int Ax) {

	//Ax = By

	//Index in res
	int x = threadIdx.x + blockIdx.x * blockDim.x;

	int y = blockIdx.y;

	if (x < Bx && y < Ay)
	{

	float sum = 0;

	//Each thread calculate summation
	for (int i = 0; i < Ax; i++)
	{

		printf("(%d, %d) * (%d, %d) = %9.6f * %9.6f \n", y + 1, i + 1, i + 1, x + 1, d_A[i + y * Ax], d_B[x + Bx * i]);

		sum += d_A[i + y * Ax] * d_B[x + Bx * i];
	}

	d_res[x + y * Bx] = sum;

	}

}



void MatMulWithTiling(float* A, int Ax, int Ay, float* B, int Bx, int By) {



	//Declare result matrix
	float* res = (float*)malloc((Ay * Bx) * sizeof(float));

	//Allocate memory on device
	float* d_res, * d_A, * d_B;
	cudaMalloc(&d_res, Ay * Bx * sizeof(float));
	cudaMalloc(&d_A, Ax * Ay * sizeof(float));
	cudaMalloc(&d_B, Bx * By * sizeof(float));

	//Copy values to device memory
	cudaMemcpy(d_A, A, Ax * Ay * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, B, Bx * By * sizeof(float), cudaMemcpyHostToDevice);



	//Get number of blocks in x direction
	int n_blocksx = ceil((double)Bx / 32);

	int n_blocksy = Ay/32;

	const dim3 blockSize(32, 32, 1);

	const dim3 gridSize(n_blocksx, n_blocksy, 1);


	MatMulWithTilingKer << <gridSize, blockSize >> > (d_A, d_B, d_res, Bx, Ay, Ax);

	cudaMemcpy(res, d_res, Ay * Bx * sizeof(float), cudaMemcpyDeviceToHost);

	printValues(res, Bx, Ay);

	free(res);

}






//Kernel function for matrix multiplication with tiling
__global__ void MatMulWithTilingKer(float* d_A, float* d_B, float* d_res, int Bx, int Ay, int Ax) {

	//Ax = By

	//Shared memory fits 2000 floats
	__shared__ float TileA[32][32];
	__shared__ float TileB[32][32];
	
	//Index in res
	int x = threadIdx.x + blockIdx.x * blockDim.x;
	int y = blockIdx.y * blockDim.y + threadIdx.y;

	//Index for shared memory
	int my_x = threadIdx.x;
	int my_y = threadIdx.y;


	//Initialize tiles for A and B matrices
	if (x < Ax && y < Ay)
		TileA[my_x][my_y] = d_A[x + y * Ax];


	if (x < Bx && y < Ax)
		TileB[my_x][my_y] = d_B[y + x * Bx];

	__syncthreads();

	if (x < Bx && y < Ay)
	{

		float sum = 0;

		//Each thread calculate summation
		for (int i = 0; i < blockDim.x; i++)
		{

			printf("(%d, %d) * (%d, %d) = %9.6f * %9.6f \n", my_y + 1, i + 1, i + 1, my_x + 1, TileA[i][my_y], TileB[my_x][i]);

			sum += TileA[i][my_y] * TileB[my_x][i];

			//printf("(%d, %d) * (%d, %d) = %9.6f * %9.6f \n", y + 1, i + 1, i + 1, x + 1, d_A[i + y * Ax], d_B[x + Bx * i]);

			//sum += d_A[i + y * Ax] * d_B[x + Bx * i];


		}


		d_res[x + y * Bx] = sum;

	}



}