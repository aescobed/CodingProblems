//sudoku solver

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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


	printf("initial problem\n");

	//Print the initial problem
	printAll(sud);

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

	bool solved = false;
	int pass = 1;

	while(!solved)
	{

		for(int j = 0; j < 81; j++)
		{

		//If we have already found the solution for this entry - go on to the next one
		if(sud[j] != 0)
			continue;

		int x = j%9;
		int y = j/9;

		
		//Iterate through horizontal
		for(int i=0; i < 9; i++)
		{
			
			if(sud[(y*9) + i] != 0)
				removeValue(list, j, sud[(y*9) + i]);


			//If we have found the solution to the entry (last possible option) - update the sud matrix
			if(list[j]->next == NULL)
			{
				
				sud[j] = list[j]->key;
				continue;

			}
			
		}

		//Iterate through vertical
		for(int i=0; i < 9; i++)
		{
			
			if(sud[(i*9) + x] != 0)
				removeValue(list, j, sud[(i*9) + x]);


			//If we have found the solution to the entry (last possible option) - update the sud matrix
			if(list[j]->next == NULL)
			{
				
				sud[j] = list[j]->key;
				continue;

			}

		}

		//Y quadrant
		int YQ = y/3;
		
		//X quadrant;
		int XQ = x/3;

		for(int jump=0; jump<3; jump++)
			for(int i=0; i < 3; i++)
			{

				if(sud[XQ*3 + YQ*27 + i + jump*9] != 0)
					removeValue(list, j, sud[XQ*3 + YQ*27 + i + jump*9]);


				//If we have found the solution to the entry (last possible option) - update the sud matrix
				if(list[j]->next == NULL)
				{
					
					sud[j] = list[j]->key;
					continue;

				}

			}

		}


	printf("pass %d\n", pass);
	printAll(sud);
	pass++;

	//Scan through all the entries to see if they have all been filled in
	for(int iter = 0; iter < 81; iter++)
		if(sud[iter] == 0)
		{
			solved = false;
			break;
		}
		else
			solved = true;

	}


	return 0;

}
