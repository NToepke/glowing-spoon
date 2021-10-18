#define _CRT_SECURE_NO_WARNINGS


//nst9fk
// program is efficent as it is dependant on Theta*(V+3E)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int vertex; //number assigned by DFS
	int lowlink; //lowest vertex found by DFS that can be reached, used for Tarjan's algorithm, default to vertex number
	int onStack; // -1 means unvisited by DFS, 0 means not on stack, 1 means on stack
	int scc; //component the node belongs to, default -1
	int degree;
	int* adjlist;

} Node;

Node* newNode(int v, int largest) //create a new Node for the priority queue
{
	Node* temp = (Node*)malloc(sizeof(Node));
	int* adjlist = malloc(sizeof(int) * (largest - 1));
	if (temp == NULL || adjlist == NULL) //in case of malloc failure, return NULL
	{
		printf("Malloc Failure in Node Creation!");
		return NULL;
	}
	else
	{
		temp->vertex = v;
		temp->lowlink = v;
		temp->onStack = -1;
		temp->scc = -1;
		temp->degree = 0;
		temp->adjlist = adjlist;
		return temp;
	}
}

int minInt(int a, int b)
{
	return (a < b ? a : b);
}

void DFS(Node** graph, int node, int* stack, int* emptySCC)
{
	graph[node - 1]->onStack = 1;
	//add node to the stack
	stack[0]++;
	stack[stack[0]] = node;
	//for all edges from v to w(another vertex), do
	for (int i = 0; i < graph[node - 1]->degree; i++)
	{
		if (graph[(graph[node - 1]->adjlist[i]) - 1]->onStack == 1) //if already found, begin to link back to create SCC's
		{
			graph[node - 1]->lowlink = minInt(graph[node - 1]->lowlink, graph[graph[node - 1]->adjlist[i] - 1]->lowlink); //change the low link to reflect which node has lower value
			break;
		}
		else if (graph[(graph[node - 1]->adjlist[i]) - 1]->onStack == -1) // otherwise, keep scouting Vertices
		{
			DFS(graph, graph[node - 1]->adjlist[i], stack, emptySCC);
			graph[node - 1]->lowlink = minInt(graph[node - 1]->lowlink, graph[graph[node - 1]->adjlist[i] - 1]->lowlink); //change the low link to reflect which node has lower value
		}

	}
	//if this node is a root node, clear the stack and call it a SCC
	if (graph[node - 1]->lowlink == node && graph[node - 1]->onStack == 1) // this may be a problem later
	{
		printf("\nStrongly Connected Component %d:\n", *emptySCC);
		while (stack[0] > 0)
		{
			graph[stack[stack[0]] - 1]->scc = *emptySCC;
			printf("%d ", stack[stack[0]]);
			graph[stack[stack[0]] - 1]->onStack = 0;
			stack[stack[0]--] = 0;
		}
		*emptySCC += 1;
	}
}

int main(void)
{
	//scan in the file name to create into a adjacency list
	FILE* fp = NULL;
	printf("What is the name of the file to be read: ");
	char filename[128];
	scanf("%s", &filename);
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
			int temp2 = 0;
			fscanf(fp, "%d %d", &temp1, &temp2);
			if (temp1 > largestVert) //if temp1 vertex is a higher number than the current largest number vertex, replace it.
				largestVert = temp1;
			if (temp2 > largestVert) //if temp2 vertex is a higher number than the current largest number vertex, replace it.
				largestVert = temp2;
			numberEdges++; //count the total edges in the graph
		}
		fclose(fp);
		fp = NULL;


		Node** graph = malloc(sizeof(Node*) * largestVert);
		for (int i = 0; i < largestVert; i++)
		{
			graph[i] = newNode(i + 1, largestVert);
		}

		fp = fopen(filename, "r");
		if (!fp)
		{
			printf("Error processing file!");
		}
		else
		{
			//This loop runtime is O(E)
			//read all of the edges into the graph
			while (!feof(fp))
			{
				int temp1 = 0;
				int temp2 = 0;
				fscanf(fp, "%d %d", &temp1, &temp2); //read in data from file
				graph[temp1 - 1]->adjlist[graph[temp1 - 1]->degree++] = temp2;
			}
			fclose(fp);
			int* stack = malloc(sizeof(int) * (largestVert + 1));
			//loop runs in O(V) time
			for (int i = 0; i < largestVert; i++)
			{
				stack[i] = 0;
			}
			int* emptySCC = (int*)malloc(sizeof(int));
			if (emptySCC == NULL) //in case of malloc failure, return NULL
			{
				printf("Malloc Failure before DFS!");
				return 0;
			}
			else
			{
				*emptySCC = 1;
				for (int i = 1; i <= largestVert; i++)
				{
					if (graph[i - 1]->onStack == -1)
						DFS(graph, i, stack, emptySCC);
				}

				int* outSCC = malloc(sizeof(int) * (*emptySCC - 1));
				if (outSCC == NULL) //in case of malloc failure, return NULL
				{
					printf("Malloc Failure after DFS!");
					return 0;
				}
				else
				{
					for (int i = 0; i < *emptySCC - 1; i++)
					{
						outSCC[i] = 0;
					}
					//These nested FOR LOOPS ONLY RUN IN O(E) TIME as all degrees added together equals total edges
					int* alloutedges = malloc(sizeof(int) * (numberEdges));
					if (outSCC == NULL) //in case of malloc failure, return NULL
					{
						printf("Malloc Failure after DFS!");
						return 0;
					}
					int k = 0;
					int badflag = 0;
					for (int i = 0; i < largestVert; i++)
					{
						for (int j = 0; j < graph[i]->degree; j++)
						{
							if (graph[i]->scc != graph[graph[i]->adjlist[j] - 1]->scc)
							{
								for (int l = 0; l < k; l++)
								{
									if (alloutedges[l] == graph[i]->scc * 1000 + graph[graph[i]->adjlist[j] - 1]->scc || alloutedges[l] == graph[i]->scc + graph[graph[i]->adjlist[j] - 1]->scc * 1000)
									{
										badflag = 1;
									}
								}
								if (badflag == 0)
								{
									alloutedges[k] = graph[i]->scc * 1000 + graph[graph[i]->adjlist[j] - 1]->scc;
									k++;
									outSCC[(graph[i]->scc - 1)] += 1;
								}
								else
								{
									badflag = 0;
								}
							}
						}
					}
					printf("\n\n");
					for (int i = 0; i < *emptySCC - 1; i++)
					{
						printf("%d ", outSCC[i]);
					}
				}
			}
		}
	}
}