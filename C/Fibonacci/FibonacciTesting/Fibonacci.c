#include<stdio.h>

int fibonacciDynamic(int n);
void fibonacciRecurseDynamic(int n, int* arr);
int fibonacci(int n);
int fibonacci2(int n);

void main()
{


	int n = 10;

	printf("The %dth fibonacci number is: %d \n", n, fibonacci(n));
	printf("The %dth fibonacci number is: %d \n", n, fibonacciDynamic(n));


}




//Returns the nth fibonacci and keeps the results in the array in case you need to use it many times
int fibonacciDynamic(int n)
{

	if (n < 2)
		return 0;
	else if (n < 4)
		return 1;


	//Initialize array of 0's - no number after the 3rd fibonacci number should be 1
	int* arr = (int*)calloc((n - 1) * sizeof(int));

	arr[1] = 1;
	arr[2] = 1;

	fibonacciRecurseDynamic(n, arr);

	return arr[n - 1];

}

//Sets the numbers in the array to the correct value
void fibonacciRecurseDynamic(int n, int* arr)
{

	if (arr[n - 2] == 0 && n - 2 > 2)
		fibonacciRecurseDynamic(n - 1, arr);

	else if ((arr[n - 3] == 0 && n - 3 > 2))
		fibonacciRecurseDynamic(n - 2, arr);


	arr[n - 1] = arr[n - 2] + arr[n - 3];

}


//Fibonacci recursively
int fibonacci(int n)
{

	if (n < 1)
		return 0;
	if (n == 1)
		return 0;
	else if (n < 4)
		return 1;

	else
		return fibonacci(n - 1) + fibonacci(n - 2);

}

//Fibonacci with array - not dynamic
int fibonacci2(int n)
{

	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 1;

	int* arr = malloc((n - 1) * sizeof(int));

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;


	for (int i = 3; i <= n - 1; i++)
	{

		arr[i] = arr[i - 1] + arr[i - 2];

	}

	return arr[n - 1];

}