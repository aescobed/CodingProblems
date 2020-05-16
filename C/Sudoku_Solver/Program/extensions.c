#include <stdio.h>
#include <stdlib.h>


void printAll(int* sud)
{

	//For all the numbers on the board
	for(int i = 0; i < 81; i++)
	{
		
		//print vertical divider
		if(i%9 == 0 && i > 0)
			printf("|\n"); 

		//Print horizontal divider
		if(i % 27 == 0)
		{
			for(int i = 0; i < 25; i++)
				printf("-");

			printf("\n");

		}

		//Print vertical divider
		if(i%3 == 0)
			printf("| ");

		//Print the value
		printf("%d ", sud[i]);


	}

	printf("|\n");

	//Print ending horizontal divider
	for(int i = 0; i < 25; i++)
		printf("-");

	printf("\n");

}

