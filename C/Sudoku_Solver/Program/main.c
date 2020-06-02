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


	struct node *n = (struct node*)malloc(sizeof(struct node));

	newFullList2(n);

	printList(n);

	
/*
	printf("%d", n->key);

	while(n->next != NULL)
	{
		
		n = n -> next;
		printf(", %d", n->key);

	}


	printf("\n");
*/	



	//struct node** d;
	//newFullList(d);
	
	//printList(a);

	return 0;

}
