#define _CRT_SECURE_NO_WARNINGS
//nst9fk
// program is efficent as it is dependant on Theta*(V+3E)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int vertex1;
	int vertex2;
	struct node* next;
} Node;

Node* newNode(int v1, int v2) //create a new Node for the priority queue
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) //in case of malloc failure, return NULL
	{
		printf("Malloc Failure in Node Creation!");
		return NULL;
	}
	else
	{
		//set node variables
		temp->vertex1 = v1;
		temp->vertex2 = v2;
		temp->next = NULL;
		return temp;
	}
}
// peek returns the second vertex of the edge at the front of the queue
int peek(Node** head)
{
	return (*head)->vertex2;
}
// peekPrio returns the first vertex of the edge at the front of the queue
int peekPrio(Node** head)
{
	return (*head)->vertex1;
}
// pop removes the head node and frees allocated memory
void pop(Node** head)
{
	Node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}
//push Adds a new edge to the queue that connects vertices v1 and v2
void push(Node** head, int v1, int v2)
{
	Node* start = (*head);
	Node* temp = newNode(v1, v2);
	//check if the node should replace the head node
	//first check if it has a higher first numbered vertex, then check if its second vertex is a lower number should the first vertex numbers match
	if ((*head)->vertex1 > v1 || ((*head)->vertex1 ==v1 && (*head)->vertex2 > v2)) 
	{
		temp->next = *head;
		(*head) = temp;
	}
	else
	{
		//while not at the end of the queue, or while the temp edge has lower priority than the current edge,  move through the priority queue until the new edge can be placed in the queue
		while (start->next != NULL && (start->next->vertex1 < v1 || (start->next->vertex1 == v1 && start->next->vertex2 < v2)))
		{
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
	}
}
//Returns NULL if the queue is empty
int isEmpty(Node** head) 
{
	return (*head) == NULL;
}

int main(void)
{
	//scan in the file name to create into a adjacency list
	FILE* fp = NULL;
	printf("What is the name of the file to be read: ");
	char filename[128];
	scanf("%s",&filename);
	fp = fopen(filename, "r");
	if (!fp)
	{
		printf("Error processing file!");
	}
	else
	{
		int largestVert = 0;
		int numberEdges = 0;

		//This loop runtime is O(E)
		//Find the largest numbered vertex, while also counting the total edges in the graph

		while (!feof(fp))
		{
			int temp1 = 0;
			int temp2=0;
			fscanf(fp, "%d %d", &temp1, &temp2);
			if (temp1 > largestVert) //if temp1 vertex is a higher number than the current largest number vertex, replace it.
				largestVert = temp1;
			if (temp2 > largestVert) //if temp2 vertex is a higher number than the current largest number vertex, replace it.
				largestVert = temp2;
			numberEdges++; //count the total edges in the graph
		}
		fclose(fp);
		fp = NULL;
		fp = fopen(filename, "r");
		if (!fp)
		{
			printf("Error processing file!");
		}
		else
		{
			int firstTime = 1;
			Node* graph;

			//This loop runtime is O(E)
			//read all of the edges into the priority queue
			while (!feof(fp))
			{
				int temp1 = 0;
				int temp2 = 0;
				fscanf(fp, "%d %d", &temp1, &temp2); //read in data from file
				if (firstTime) //if it is the first node, the graph pointer needs to be initialized.
				{
					firstTime = 0; //disable the first time if statement
					graph = newNode(temp1, temp2); //create the graph priority queue
					push(&graph, temp2, temp1); //add the edge in the other direction to the queue
				}
				else
				{
					push(&graph, temp1, temp2); //add the read edge to the queue
					push(&graph, temp2, temp1); //add the read edge in the opposite direction to the queue
				}
			}
			fclose(fp);

			int previousvertex1 = 0;

			//This Loop runtime is o(V+E)

			while (!isEmpty(&graph)) //loop until the queue is emptied
			{
				//if a vertex has no edges, then this loop will make sure a blank line is left for that vertex
				while (previousvertex1 != peekPrio(&graph)) //text formatting so that each vertex's adjacency list is on a different line
				{
					printf("\n");
					previousvertex1++;
				}
				printf("%d ", peek(&graph)); //print out adjacent vertices to the current vertex
				pop(&graph);
			}
			free(graph); //free graph pointer so all malloc'd memory is returned to system
		}
	}
}