#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab12.h"

PQueue initPQueue()
{
    PQueue q; //declare and initialize the priority queue
    q.list = malloc(sizeof(StateList));
    if (q.list == NULL) // if malloc fails, return the uninitialized priority queue
    {
        printf("Malloc Failure in initPQueue!");
        return q;
    }
    q.list->head = NULL; //initialize the member variables of q.list
    q.list->tail = NULL;
    q.list->numOfItems = 0;
    return q;
}
State* createNode(float prio, float pop)
{
    State* newNode = malloc(sizeof(State)); // declare and initialize the newNode
    if (newNode == NULL) // in case of malloc failure, return null
    {
        printf("Malloc Failure in createNode!");
        return NULL;
    }
    newNode->populationInMillion = pop; //initialize member variables of the newNode
    newNode->priority = prio;
    newNode->nextState = NULL;
    newNode->previousState = NULL;
    return newNode;
}
int insertPQ(float prio, float pop, PQueue q)
{
    State* newNode = createNode(prio, pop); //call create Node
    if (newNode == NULL) // if createNode has a malloc error
    {
        printf("Malloc Failure in createNode!");
        return -1; // return -1 for failure
    }
    if (q.list->numOfItems == 0) // if the list is empty
    {
        q.list->head = newNode; // set new node as being the head and tail of the list
        q.list->tail = newNode;
        q.list->numOfItems++; //increment the number of items
        return 1;
    }
    if (newNode->priority > q.list->head->priority) // if the priority is larger than the largest priority in the list
    {
        newNode->nextState = q.list->head; // new node points to the head as its next state
        q.list->head->previousState = newNode; //head points its previous node to newnode
        q.list->head = newNode; // the list head pointer points to newnode
        q.list->numOfItems++; //increment the number of items
        return 1;// insertion success
    }
    if (newNode->priority < q.list->tail->priority) // if the priority is smaller than the smallest priority in the list
    {
        newNode->previousState = q.list->tail;  // new node points to the tail as its previous state
        q.list->tail->nextState = newNode; //tail points its next node to newnode
        q.list->tail = newNode; // the list tail pointer points to newnode
        q.list->numOfItems++; //increment the number of items
        return 1;// insertion success
    }

    State* temp = q.list->head; // temporary pointer to iterate through the list
    while (newNode->priority < temp->priority) // while the new node has lower priority of the temp item in the list, keep iterating
    {
        temp = temp->nextState;
    }
    // temp is now the state that will follow new node in the list
    temp->previousState->nextState = newNode; //set the state before newNode in the list to point to newNode
    newNode->previousState = temp->previousState; // set newNode to point to its higher priority neighbor
    temp->previousState = newNode; //set temp to point to the higher priority new node
    newNode->nextState = temp; // set new node to point to the lower priority temp node
    q.list->numOfItems++; //increment the number of items
    return 1; // insertion success


}
State* deleteMin(PQueue q)
{
    if (q.list->tail == NULL)
    {
        return NULL;
    }


    State* deQueue = q.list->tail;
    if (q.list->numOfItems == 1) // if there will be no items in the list after deletion, clear the head and tail pointers
    {
        q.list->head = NULL;
        q.list->tail = NULL;
    }
    else
    {
        q.list->tail = q.list->tail->previousState; // set the tail to point to the new tail, which is the old tail's previous state pointer
        q.list->tail->nextState = NULL; // set the tail Node to have no value in its next state pointer
    }
    q.list->numOfItems--; //decrement the number of items
    return deQueue;
}
State* deleteMax(PQueue q)
{

    if (q.list->head == NULL)
    {
        return NULL;
    }


    State* deQueue = q.list->head;
    if (q.list->numOfItems == 1) // if there will be no items in the list after deletion, clear the head and tail pointers
    {
        q.list->head = NULL;
        q.list->tail = NULL;
    }
    else
    {
        q.list->head = q.list->head->nextState; // set the head to point to the new head, which is the old head's next state pointer
        q.list->head->previousState = NULL; // set the head node to have no value in its previous state pointer
    }
    q.list->numOfItems--; //decrement the number of items
    return deQueue;
}
State* returnMin(PQueue q) // returns but does not delete
{
    if (q.list->numOfItems == 0)
    {
        return NULL;
    }
    return q.list->tail; // returns the min
}
State* returnMax(PQueue q) // returns but does not delete
{
    if (q.list->numOfItems == 0)
    {
        return NULL;
    }
    return q.list->head; // returns the max
}
void freePQueue(PQueue q) // Free all malloced space
{
    while (q.list->head != NULL) // while there is items in the queue
    {
        free(deleteMax(q)); // free items off of the queue from the head
    }
    free(q.list); // free the list itself
    q.list = NULL; // set it to null to stop some knuckle-headed programmer
}
void printPQueue(PQueue q)
{
    State* temp = q.list->head; // temp value to iterate through queue
    for (int i = 0; i < q.list->numOfItems; i++) // for loop goes from 0 to the total size of the queue
    {
        printf("%f (%f) --> ", temp->priority, temp->populationInMillion); // print values
        temp = temp->nextState; // iterate the temp pointer
    }
    printf(" end\n"); // end of print statement
}
