#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "lab13.h"

State** readRecord(FILE* fp)
{
	if (!fp) // if the file pointer is empty
	{
		return NULL;
	}
	else
	{
		int size = 0;
		fscanf(fp, "%d\n", &size);  // scan in the size of the array
		State** statearr = malloc(sizeof(State*)*size); // malloc the memory size of the array
		if (statearr == NULL) // if malloc fails, return null
		{
			printf("malloc failure in readRecord!");
			return NULL;
		}
		for (int i = 0; i < size; i++) // for all elements of the array
		{
			statearr[i] = malloc(sizeof(State*)); //malloc that element
			if (statearr[i] == NULL) //check for malloc errors
			{
				printf("Malloc error in readRecord!"); 
				freeArr(statearr, i); // free all previously allocated elements
				return NULL;
				
			}
			fscanf(fp, "%f,%f\n", &statearr[i]->populationInMillion, &statearr[i]->area); //scan in member values 
		}
		fclose(fp); //close file and return completed array
		return statearr;
	}
	
}
int comparison(void* a, void* b) // comparison function from the prelab document
{
	State* query, * state; // declare new pointers of state type
	query = a; state = b; // set them to point with the passed pointers
	if (query->area < state->area) return -1; // if query is less than the other, return -1
	if (query->area > state->area) return 1;  // if query is less than the other, return 1
	return 0; // else the two match and return 0
}
int binarySearch(void** arr, int low, int high, void* find)
{
	State** array; //declare type casted pointer of state** type
	array = (State**)arr; // and set it to parameter pointer
	if (high > low) // if value is not in list
	{
		return -1;
	}
	int mid = (high + low) / 2; //set mid index
	if (comparison(find, array[mid]) == 1) // if the value is bigger than the mid index value
	{
		return binarySearch(arr, mid-1, high, find); // recursion to only the upper half of the array
	}
	if (comparison(find, array[mid]) == -1) // if the value is smaller than the mid index value
	{
		return binarySearch(arr, low, mid + 1, find); // recursion to only the lower half of the array
	}
	return mid; // return mid index if the find pointer is at the mid index
}
void freeArr(State** arr, int size)
{
	for (int i = 0; i < size; i++) // free all allocated states in the loop
	{
		free(arr[i]);
	}
	free(arr); // free the array itself
}