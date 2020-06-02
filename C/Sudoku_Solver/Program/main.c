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
	//printAll(sud);

	
	//Create 


	//array of pointers - each to a list of all the possible entries in the respective index
	struct node **list = (struct node**)malloc(sizeof(struct node*) * 81);

	newFullList(list, 0);

	printList(list[0]);




	//struct node** d;
	//newFullList(d);
	
	//printList(a);

	return 0;

}
