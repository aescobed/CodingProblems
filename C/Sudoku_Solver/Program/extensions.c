#include <stdio.h>
#include <stdlib.h>


void printAll(int* sud)
{

	for(int i = 0; i < 81; i++)
	{

		if(i%9 == 0)
			printf("\n"); 

		printf("%d \t", sud[i]);

	}


}

