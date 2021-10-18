#define _CRT_SECURE_NO_WARNINGS
//nst9fk
#include <stdio.h>
#include <stdlib.h>

//void build_max_heap(int[],int[],int);
//void insert(int[],int);
//void max_heapify(int[], int, int);
//void heap_change_key(int[],int,int);
//void delete_key(int[],int,int);

//function loops through the heap and prints all values in heap
void print_heap(int heap[1001])
{
	for (int i = 1; i <= heap[0]; i++)
	{
		printf("%d ", heap[i]);
	}
}

//function works through each node's left and right child nodes and sees if both nodes are smaller than it. If not, switch the parent node with the largest child node
void max_heapify(int heap[1001], int index)
{
	int left = 2 * index;
	int right = 2 * index + 1;
	int largest;
	if (left <= heap[0] && heap[left] > heap[index]) largest = left;
	else largest = index;
	if (right <= heap[0] && heap[right] > heap[largest]) largest = right;
	if (largest != index)
	{
		int temp = heap[index];
		heap[index] = heap[largest];
		heap[largest] = temp;
		max_heapify(heap, largest);
	}
}
//call max_heapify to reaffirm that the heap follows the rules about being a heap. max heapify is called for every node in the heap
void build_max_heap(int heap[1001])
{
	for (int i = heap[0]; i>0; i--)
	{
		max_heapify(heap, i);
	}
	
}
//sets the new value for the heap node, then runs build_max_heap to maintain heap integrity
void heap_change_key(int heap[1001], int index, int key)
{
	heap[index] = key;
	build_max_heap(heap);
}
//adds a new node to the end of the heap and runs build_max_heap to maintain heap integrity
void insert(int heap[1001], int key)
{
	heap[0]++;
	heap[heap[0]] = key;
	build_max_heap(heap);
}
//code is implemented from given sudocode from assignment. sets the last element in the heap to be the node to be removed, then runs buildd_max_heap without the last node
//to maintain heap integrity
void delete_key(int heap[1001], int index)
{
	int key = heap[heap[0]];
	heap[0]--;
	heap_change_key(heap, index, key);
}

int main(void)
{
	//scan in the file name to create heap
	FILE* fp = NULL;
	printf("What is the name of the file to be read: ");
	char filename[128];
	scanf("%c", &filename);
	fp = fopen(filename, "r");
	fp = fopen("text.txt", "r");
	if (!fp)
	{
		printf("Error processing file!");
	}
	else
	{
		int heap[1001];
		for (int i = 0; i < 1001; i++)
		{
			heap[i] = 0;
		}

		fscanf(fp, "%d", &heap[0]);
		for (int i = 1; i <= heap[0]; i++)
		{
			fscanf(fp, "%d", &heap[i]);
		}
		build_max_heap(heap);
		while (!feof(fp))
		{
			char choice;
			fscanf(fp, "%c", &choice);
			int key=0;
			int replacement = 0;
			switch (choice) {
				case 'I':
					fscanf(fp, "%d", &key);
					insert(heap, key);
					break;
				case 'E':
					delete_key(heap, 1);
					break;
				case 'C':
					fscanf(fp, "%d %d", &key, &replacement);
					heap_change_key(heap, key, replacement);
					break;
				case 'D':
					fscanf(fp, "%d", &key);
					delete_key(heap, key);
					break;
			}
		}
		print_heap(heap);
	}
}