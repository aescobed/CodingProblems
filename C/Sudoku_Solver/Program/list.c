//node list

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//Pointer to first in list of 1 to 9
void newFullList(struct node **n, int idx)
{

	n[idx] = (struct node*)malloc(sizeof(struct node));

	struct node *hold = (struct node*)malloc(sizeof(struct node));

	hold = n[idx];

	for(int i = 0; i < 9; i++)
	{

		struct node *t = (struct node*)malloc(sizeof(struct node));
		
		hold->next = t;

		hold->key = i;

		hold = t;
	
	}

	hold->key = 9;

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




















