//sudoku solver

#include <stdio.h>
#include <stdlib.h>
#include "extensions.h"
#include "problems.h"
#include "list.h"




int main(void)
{

	//Declare problem
	int *sud = (int *) malloc(9*9*sizeof(int));
	
	//Initialize problem
	example1(sud);

	//Print the initial problem
	//printAll(sud);

	
	//Create 
	struct node *a;
	


	struct node** d = newFullList(a);
	
	//printList(a);

	return 0;

}
