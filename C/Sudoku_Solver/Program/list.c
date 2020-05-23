//node list

#include <stdio.h>
#include <stdlib.h>


struct node
{
	int key;
	struct node *next;
};


//Pointer to first list of 1 to 9
struct node *newFullList()
{

	struct node *n = malloc(sizeof(struct node));
	n->key = 1;


	return n;

}



void printList(struct node *n)
{

	printf("%d", n -> key);

	while(n -> next != NULL)
	{
		printf(", %d", n -> next -> key);
		n = n -> next;
	}

	printf("\n");

}

