
#include <stdlib.h>

void example1(int* sud)
{
	
	//Initialize all the values to 0 (not a valid number in sudoku)
	for(int i = 0; i < 81; i ++)
		sud[i] = 0;
	
	//Set the rest of the numbers in the problem
	int width = 9;
	sud[3] = 2;
	sud[4] = 6;
	sud[6] = 7;
	sud[8] = 1;

	sud[0 + 1*width] = 6;
	sud[1 + 1*width] = 8;
	sud[4 + 1*width] = 7;
	sud[8 + 1*width] = 9;

	sud[0 + 2*width] = 1;
	sud[1 + 2*width] = 9;
	sud[5 + 2*width] = 4;
	sud[6 + 2*width] = 5;

	sud[0 + 3*width] = 8;
	sud[1 + 3*width] = 2;
	sud[3 + 3*width] = 1;
	sud[7 + 3*width] = 4;

	sud[2 + 4*width] = 4;
	sud[3 + 4*width] = 6;
	sud[5 + 4*width] = 2;
	sud[6 + 4*width] = 9;
	
	sud[1 + 5*width] = 5;
	sud[5 + 5*width] = 3;
	sud[7 + 5*width] = 2;
	sud[8 + 5*width] = 8;

	sud[2 + 6*width] = 9;
	sud[3 + 6*width] = 3;
	sud[7 + 6*width] = 7;
	sud[8 + 6*width] = 4;

	sud[1 + 7*width] = 4;
	sud[4 + 7*width] = 5;
	sud[7 + 7*width] = 3;
	sud[8 + 7*width] = 6;

	sud[0 + 8*width] = 7;
	sud[2 + 8*width] = 3;
	sud[4 + 8*width] = 1;
	sud[5 + 8*width] = 8;
}


