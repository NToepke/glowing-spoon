#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab11.h"

Queue initQueue()
{
    Queue newQueue; // create the Queue value
    StateList* dummy = malloc(sizeof(StateList)); // create the list pointer
    newQueue.list = dummy; //initialize all the elements in the list pointer
    newQueue.list->head = NULL;
    newQueue.list->tail = NULL;
    newQueue.list->numOfItems = 0;
    newQueue.list->totalPopulationInMillion = 0;
    return newQueue; // return the queue
}
int enQueue(float pop, Queue q)
{
    State* newState = malloc(sizeof(State));  //malloc the new state
    if (newState == NULL) // if malloc fails, insertion fails
    {
        return -1;
    }
    newState->populationInMillion = pop; // initialize member variables
    newState->nextState = NULL;
    if (q.list->head == NULL) //if list is empty, set head and tail pointers to new state
    {
        q.list->head = newState;
        q.list->tail = newState;
    }
    else
    {
        q.list->tail->nextState = newState; //put new state at the tail of the list
        q.list->tail = newState; // set the tail to the new end of the list
    }
    q.list->numOfItems++; // modify member variables of the list by adding to numOfItems and totalPopulationInMillion
    q.list->totalPopulationInMillion += pop;
    return 1;


}
State* deQueue(Queue q)
{
    State* head = q.list->head; //pointer to state that will be removed
    if (head == NULL) //if list is empty, return NULL
    {
        return NULL;
    }
    if (head->nextState == NULL) //if there is only one thing in the list, set list member variables to NULL or zero
    {
        q.list->tail = NULL;
        q.list->head = NULL;
        q.list->numOfItems = 0;
        q.list->totalPopulationInMillion = 0;
        return head; //return deQueued state
    }
    q.list->head = head->nextState; //move head pointer to new head of list
    head->nextState = NULL; // remove the dequeued state from the list
    q.list->numOfItems--; //modify numOfItems and totalpopulationinmillion dude to the removal of a state
    q.list->totalPopulationInMillion -= head->populationInMillion;
    return head; // return dequeued state
}
int getQsize(Queue q)
{
    return q.list->numOfItems; //return the member variable holding the size of the list
}
float getTotal(Queue q)
{
    return q.list->totalPopulationInMillion; //return the member variable holding the total population of the list
}
void printQueue(Queue q)
{
    State* temp = q.list->head; //temp state pointer to move through the list
    for (int i = 0; i < getQsize(q); i++) //iterate through the list up to its size value
    {
        printf("%d. %f\n", i + 1, temp->populationInMillion); //print out pertinent information about the states in the queue
        temp = temp->nextState; //move the temp state pointer to the next item in the list
    }
}
void emptyQueue(Queue q)
{
    int size = getQsize(q); // temp value to hold the total size of the list
    for (int i = 0; i < size; i++)
    {
        State* temp; // temp state pointer to hold the dequeued states
        temp = deQueue(q); // dequeue into the temp value
        free(temp); // free the dequeued states
    }
    free(q.list); //free the dummy node holding pertinent information
    q.list = NULL; //set it to null to prevent stupid user error accessing stuff they shouldn't
}
