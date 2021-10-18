#include <stdio.h>
#include <stdlib.h>
#include "lab15.h"


Node* createNode(Employee*);

Employee** readRecord(FILE* fp)
{
	if (!fp) // if the file pointer is empty
	{
		return NULL;
	}
	else
	{
		int size = 0;
		fscanf(fp, "%d\n", &size);  // scan in the size of the array
		Employee** emparr = malloc(sizeof(Employee*) * size); // malloc the memory size of the array
		if (emparr == NULL) // if malloc fails, return null
		{
			printf("malloc failure in readRecord!");
			return NULL;
		}
		for (int i = 0; i < size; i++) // for all elements of the array
		{
			emparr[i] = malloc(sizeof(Employee)); //malloc that element
			if (emparr[i] == NULL) //check for malloc errors
			{
				printf("Malloc error in readRecord!");
				return NULL;
			}
			fscanf(fp, "%d,%f,%d\n", &emparr[i]->ID, &emparr[i]->salary, &emparr[i]->ssn); //scan in member values 
		}
		fclose(fp); //close file and return completed array
		return emparr;
	}
}
int comparison(void* compare, void* found)
{
	Employee* a = (Employee*)compare; // type cast the incoming void pointers so we can use them
	Employee* b = (Employee*)found;
	if (a->salary > b->salary) // if the first one is larger, return 1
	{
		return 1;
	}
	if (a->salary < b->salary) // if the second one is larger, return -1
	{
		return -1;
	}
	return 0; // both must be equal if it reaches this line, so return 0
}
Node* createNode(Employee* newEmp) //this method creates a new node with the employee pointer from insertBST
{
	Node* newNode = malloc(sizeof(Node));// the node is initialized and malloced
	if (newNode == NULL) // in case of malloc failure
	{
		printf("Malloc failure in createNode!");
		return NULL; //return null if malloc fails
	}
	newNode->data = newEmp; //set the member variables to defaults
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode; //return created node
}
Node* insertBST(Node* root, Employee* newEmp)
{
	if (root == NULL) // if the BST is empty, set the root node to the newEmp's node
	{
		root=createNode(newEmp);
	}
	else //The BST is not empty
	{
		if (comparison(newEmp, root->data) == 1)  // if the newEmp->salary is greater than the current root node's salary, go right
		{
			if (root->right == NULL) // if there is nothing else on the right, put the newEmp on the right
			{
				root->right = createNode(newEmp); //by creating a new node and putting it in the right pointer
				return root; //return to go up the recursion
			}
			else
			{
				insertBST(root->right, newEmp); //recursively go through the tree down the right side
			}
		}
		if (comparison(newEmp, root->data) == -1) // if the newEmp->salary is less than the current root node's salary, go left
		{
			if (root->left == NULL) // if there is nothing else on the left, put the newEmp on the left
			{
				root->left = createNode(newEmp); //by creating a new node and putting it in the left pointer
				return root; //return to go up the recursion
			}
			else
			{
				insertBST(root->left, newEmp); //recursively go through the tree down the right side
			}
		}
		if (comparison(newEmp, root->data) == 0) // if the newEmp->salary is equal to the current root node's salary, go left
		{
			if (root->left == NULL) // if there is nothing else on the left, put the newEmp on the left
			{
				root->left = createNode(newEmp); //by creating a new node and putting it in the left pointer
				return root; //return to go up the recursion
			}
			else
			{
				insertBST(root->left, newEmp); //recursively go through the tree down the left side
			}
		}
	}
	return root; // at the end of all recursion, return the top node of the binary tree

}
Employee* searchBST(Node* root, float salary)
{
	if (root == NULL) // if the tree is empty or the Employee does not exist with that salary, return NULL
	{
		return NULL;
	}
	if (root->data->salary == salary) // if the root is the employee searched for, return it
		return root->data;
	if (root->data->salary > salary) // if the salary is lower than the current root, go left
		return searchBST(root->left, salary);
	else
		return searchBST(root->right, salary); // if the salary is higher than the current root, go right
	
}
void deleteTree(Node* root)
{
	if (root->left != NULL) //if there is a left node
	{
		Node* left = root->left; //recursively go down that branch and delete all nodes
		deleteTree(left);
	}
	if (root->right != NULL) //if there is a right node
	{
		Node* right = root->right;  //recursively go down that branch and delete all nodes
		deleteTree(right);
	}
	free(root); //free the root pointer at the top of the tree
	root = NULL; //set root to NULL so nobody accesses it anyways
}
