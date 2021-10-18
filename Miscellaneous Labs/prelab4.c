#include <stdio.h>
#include <stdlib.h>

void * createArray(int,int);
int getArraySize(void *);
void freeArray(void *);

int main(void)
{
	float * array = createArray(10,sizeof(float));
	
	int size = getArraySize(array);
	size+=0;
	printf("The Array is %d indexes large\n",size);
	
	freeArray(array);
}

void * createArray(int indexes,int dataTypeSize)
{
	int * array;
	array = malloc(dataTypeSize * indexes + sizeof(int));
	array[0]=indexes;
	return ((void*)(array+1));
}

int getArraySize(void * array)
{
	
	return ((int*)array)[-1];
	
}

void freeArray(void * array)
{
	free((int*)array-1);
	
}