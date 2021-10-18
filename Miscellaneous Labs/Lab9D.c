#include <stdio.h>
#include <stdlib.h>
#include "lab9.h"

State* initListWithDummyNode()
{
	State* dummyHead,* dummyTail; //initialize and declare head and tail nodes
	dummyHead = malloc(sizeof(State));
	dummyTail = malloc(sizeof(State));
	dummyHead->nextState = dummyTail; //point head node to tail
	dummyHead->populationInMillion = -1; //set values for purely debugging
	dummyTail->populationInMillion = -2;
	return dummyHead; //return the head pointer
}
int insertToHead(State* head, float pop)
{
	State* newNode; //declare and initialize the new node
	newNode = malloc(sizeof(State));
	if (newNode == NULL) //check for malloc failure
	{
		printf("Malloc Failure in insertToHead!");
		return 0; //return for failure
	}
	newNode->populationInMillion = pop; //set incoming float to the new node
	newNode->nextState = head->nextState; // set the newnodes pointer to the next item in the list
	head->nextState = newNode; // set the head pointer to the newnode
	return 1; //return for success
}
int insertToTail(State* head, float pop)
{
	State* newNode; //declare and initialize the new node
	newNode = malloc(sizeof(State));
	if (newNode == NULL) //check for malloc failure
	{
		printf("Malloc Failure in insertToTail!");
		return 0; //return for failure
	}
	newNode->populationInMillion = pop;

	while( head->nextState->nextState != NULL) //while the headptr is not pointing to the last real node in the list
	{
		head = head->nextState; //iterate the head pointer through the list
	}
	newNode->nextState = head->nextState; // set the newnodes pointer to the next item in the list (the tail pointer)
	head->nextState = newNode; // set the head pointer to the newnode
	return 1; //return for success
}
void printList(State* head)
{
	if (head->nextState->nextState == NULL) //Error check to see if list is empty
	{
		printf("The list is empty\n");
	}
	while (head->nextState->nextState != NULL) //while the headptr is not pointing to the last real node in the list
	{
		head = head->nextState; //iterate the head pointer through the list
		printf("%f\n", head->populationInMillion); //print out the population number of each real node
	}
}
void emptyList(State* head)
{
	State* temp = head; //save the head pointer for the end of the function
	head = head->nextState; //move the head pointer off of the dummy node to the first real node
	if (head->nextState == NULL) //if there is no real nodes, stop this fuction immediately
	{
		return;
	}
	while (head->nextState != NULL) //while there is still real nodes in the list
	{
		State* dummy = head->nextState; //set a temp value to the next node
		free(head); //free the real node
		head = dummy; //set the iterating-through-the-list pointer to the next node stored in the temp value
	}
	temp->nextState = head; // set the headpointer(still in temp) to point to the tail(stored in the inconveniently named head)
}
void freeList(State* head)
{
	emptyList(head); //clear all real nodes from the list with emptyList!
	free(head->nextState); //free the tail dummy node
	free(head); //free the head dummy node
	//while (head != NULL)
	//{
	//	State* dummy = head->nextState;
	//	free(head);
	//	head = dummy;
	//}
}