//node list

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//Pointer to first list of 1 to 9
void newFullList(struct node **a)
{

	struct node **n = (struct node**)malloc(sizeof(struct node*) * 9);

	
	n[0]->key = 1;
	n[0]->next = n[1];
	n[1]->key = 2;
	

	a = n;

}


//Print the keys to all the elements in the list
void printList(struct node *n)
{

	printf("%d", n->key);

	while(n->next != NULL)
	{
		
		n = n -> next;
		printf(", %d", n->key);

	}


	printf("\n");

}




















