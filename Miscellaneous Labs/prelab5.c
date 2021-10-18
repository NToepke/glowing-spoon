#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int rows;
    int cols;
} ArrayData;

void ** createTable(int,int,int);
int getRowSize(void **);
int getColSize(void **);
void freeArray(void **);

int main(void)
{
    float **p;
    p=(float**)createTable(10,10,sizeof(float));
    int counter=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            p[i][j]=counter++;
        }
    }
    int n,m;
    n=getRowSize((void**)p);
    m=getColSize((void**)p);
    m+=n;
    printf("Here's a magical number that is hopefully 200: %d",m);
    printf("\nHere is a zero! %f\n",p[0][0]);
    printf("\nHere is a 12! %f\n",p[1][2]);
    freeArray((void**)p);
    return 0;
}

void ** createTable(int numRows, int numCols, int elemSize)
{
    int ** array= (int**)malloc(sizeof(void*)*numRows + sizeof(ArrayData));
    if (array==NULL)
        {
            printf("Malloc Failure Line 34!\n");
            return NULL;
        }
    
    ((ArrayData*)array)[0].rows = numRows; // size
    ((ArrayData*)array)[0].cols = numCols; // size

	array = (int**)((ArrayData*)array + 1);
    
    for(int i=0;i<numRows;i++)
    {
        array[i]=malloc(numCols*elemSize);
        if (array[i]==NULL)
        {
            printf("Malloc Failure Line 45!\n");
            for(i=i;i>0;i--)
            {
                free(array[i]);
                array[i]=NULL;
            }
            free(array);
            array=NULL;
        }
    }

    return (void**)array;
}

int getRowSize(void ** array)
{
    return ((ArrayData*)array)[-1].rows;
}
int getColSize(void ** array)
{
    return ((ArrayData*)array)[-1].cols;
}

void freeArray(void** array)
{
    for(int i=9;i>=0;i--)
    {
        free(array[i]);
        *(array+i)=NULL;
    }
    array=(void**)((ArrayData*)array-1);
    free(array);
}