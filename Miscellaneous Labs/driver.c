#include <stdio.h>
#include <stdlib.h>
#include "lab9.h"

int main(void)
{
	State* states;
	states = initListWithDummyNode();

	if (insertToHead(states,12.0) == 0)
	{
		printf("Insertion Failure at head!\n");
	}
	if (insertToHead(states, 13.0) == 0)
	{
		printf("Insertion Failure at head!\n");
	}
	if (insertToHead(states, 14.0) == 0)
	{
		printf("Insertion Failure at head!\n");
	}
	if (insertToHead(states, 15.0) == 0)
	{
		printf("Insertion Failure at head!\n");
	}
	if (insertToTail(states, 11.0) == 0)
	{
		printf("Insertion Failure at tail!\n");
	}
	if (insertToTail(states, 10.0) == 0)
	{
		printf("Insertion Failure at tail!\n");
	}
	if (insertToTail(states, 9.0) == 0)
	{
		printf("Insertion Failure at tail!\n");
	}
	if (insertToTail(states, 8.0) == 0)
	{
		printf("Insertion Failure at tail!\n");
	}
	
	printList(states);
	emptyList(states);
	printList(states);
	freeList(states);
}