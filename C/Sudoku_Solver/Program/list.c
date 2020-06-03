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


//Removes the specified value from the list at the given index
void removeValue(struct node **n, int idx, int value)
{

	//If there is only one item in the list
	if(n[idx]->next == NULL)
		return;


	struct node *hold = n[idx];

	//If the first node is the key
	if(hold->key == value)
	{
		
		n[idx] = hold->next;
		free(hold);
	}
	else
	
	//Scan throught the list
	while(hold->next != NULL)
	{

		//If the value is found within the list
		if(hold->next->key == value)
		{
			//Hold the node to be freed
			struct node *hold2 = hold->next;
			
			//Skip over the node to be deleted
			hold->next = hold->next->next;

			free(hold2);
			return;

		}

		hold = hold->next;

	}

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




















