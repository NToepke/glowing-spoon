#include <stdio.h>
#include <stdlib.h>
#include "lab14.h"

int binarySearch(State** array, int low, int high, float area);

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
		State** statearr = malloc(sizeof(State*) * size); // malloc the memory size of the array
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
				return NULL;
			}
			fscanf(fp, "%f,%f\n", &statearr[i]->populationInMillion, &statearr[i]->area); //scan in member values 
		}
		fclose(fp); //close file and return completed array
		return statearr;
	}
}
StateDB createDatabase(State** db, int size)
{
	StateDB newDB; //create new StateDB
	

	for (int i = 1; i < size; i++)  //insertion sort the array
		//insertion sort works by working from array element 0 up and 
		//sorting the current element into the previously sorted elements
		//at the front of the array.
	{
		State* key = db[i];  //pull out a key value
		int j = i - 1;
		while (j >= 0 && key->area < db[j]->area) { //iterate through each value that has already been sorted
			//these values are at lower indexes than the current key
			db[j + 1] = db[j]; //move each sorted value up in the array as the key passes it
			--j; //increment j down to move through the array 
		}
		db[j + 1] = key; //put the key in front of db[j], which is smaller than key
	}
	newDB.array = db; // set member variables of StateDB
	newDB.sizeOfDB = size;
	return newDB; // and return it
}
int binarySearch(State** array, int low, int high, float area)
{
	if (high < low) // if value is not in list
	{
		return -1;
	}
	int mid = (high + low) / 2; //set mid index
	if (array[mid]->area < area) // if the value is bigger than the mid index value
	{
		return binarySearch(array, mid - 1, high, area); // recursion to only the upper half of the array
	}
	if (area < array[mid]->area) // if the value is smaller than the mid index value
	{
		return binarySearch(array, low, mid + 1, area); // recursion to only the lower half of the array
	}
	return mid; // return mid index if the find pointer is at the mid index
}
State* findStateByArea(StateDB db, float area)
{
	int index = binarySearch(db.array,0, db.sizeOfDB, area); // call the recursive binary search function
	if (index == -1) //if binary search returns a negative, return null
	{
		return NULL;
	}
	else // otherwise return the pointer to the found state with specified area
	{
		return db.array[index];
	}
}
void freeDatabase(StateDB db)
{
	for (int i = 0; i < db.sizeOfDB; i++) // free all allocated states in the loop
	{
		free(db.array[i]);
	}
	free(db.array); // free the array itself
}