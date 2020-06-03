//sudoku solver

#include <stdio.h>
#include <stdlib.h>
#include "extensions.h"
#include "problems.h"
#include "list.h"
#include "node.h"




int main(void)
{

	//Declare problem
	int *sud = (int *) malloc(9*9*sizeof(int));
	
	//Initialize problem
	example1(sud);

	//Print the initial problem
	printAll(sud);

	
	//Create 


	//array of pointers - each to a list of all the possible entries in the respective index
	struct node **list = (struct node**)malloc(sizeof(struct node*) * 81);

	//Initialize the list of possible entries
	for(int i = 0; i < 81; i++)
	{
		
		//Create a full list from 1-9 because the entry could be anything at that index
		if(sud[i] == 0)
			newFullList(list, i);
		//Add a single value list to the main list because the entry is already known at that index
		else
			newSingleList(list, i, sud[i]);

	}

/*

	printList(list[10]);

	removeValue(list, 10, 6);
	removeValue(list, 10, 4);
	removeValue(list, 10, 9);
	removeValue(list, 10, 9);
	removeValue(list, 10, 1);
	removeValue(list, 10, 4);

	printList(list[10]);

*/



	int j = 1;

	int x = j%9;
	int y = j/9;

	printList(list[j]);

printf("(%d, %d)", x, y);

	for(int i=0; i < 9; i++)
	{
		

		if(sud[(y*9) + i] != 0)
		{

			printf("%d", sud[(y*9) + i]);
			removeValue(list, j, sud[(y*9) + i]);

		}
		
	}
printf("\n");
printList(list[j]);


printf("\n(%d, %d)", x, y);

	for(int i=0; i < 9; i++)
	{
		

		if(sud[(i*9) + x] != 0)
		{
			printf("%d", sud[(i*9) + x]);
			removeValue(list, j, sud[(i*9) + x]);
		}
	}

printf("\n");

	printList(list[j]);



	return 0;

}
