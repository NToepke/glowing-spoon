#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "lab15.h"

int main(void)
{
	FILE* fp;
	fp = fopen("employee.csv", "r");
	Employee** bigboi; //= malloc(sizeof(Employee*) * 10000);
	bigboi = readRecord(fp);
	Node* tree = malloc(sizeof(Node*));
	tree = NULL;
	for (int i = 0; i < 10000; i++)
	{
		tree = insertBST(tree, bigboi[i]);
	}
	Employee* jimR;
	jimR = searchBST(tree, 1404.34);
	printf("%f",jimR->salary);
	deleteTree(tree);
}