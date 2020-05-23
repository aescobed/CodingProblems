//node list

#include <stdio.h>
#include <stdlib.h>


struct node
{
	int key;
	struct node *next;
};


//Pointer to first list of 1 to 9
struct node** newFullList(struct node *a)
{

	struct node **n = (struct node**)malloc(sizeof(struct node*) * 9);
	n[0]->key = 1;
	n[0]->next = n[1];
	n[1]->key = 2;


	a = n[0];

	return n;
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




















