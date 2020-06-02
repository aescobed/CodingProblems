//node list

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//Creates pointer to first in list of 1 to 9 at the input index
void newFullList(struct node **n, int idx)
{

	//New head node in the main list
	n[idx] = (struct node*)malloc(sizeof(struct node));

	//iterator
	struct node *hold = (struct node*)malloc(sizeof(struct node));
	hold = n[idx];

	for(int i = 1; i < 9; i++)
	{

		struct node *t = (struct node*)malloc(sizeof(struct node));		
		hold->next = t;
		hold->key = i;
		hold = t;
	
	}

	hold->key = 9;

}


//Creates a single item list at the input index
void newSingleList(struct node **n, int idx, int value)
{

	n[idx] = (struct node*)malloc(sizeof(struct node));

	n[idx]->key = value;

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




















