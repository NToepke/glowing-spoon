#include <stdio.h>
#include <stdlib.h>

typedef struct emp {
	int id;
	int ssn;
}Employee;

typedef struct database {
	Employee** byID;
    Employee** bySSN;
    int size;
}empDatabase;

void quickSort(Employee**, int, int);
int binarySearch(empDatabase, int, int, int, int);
empDatabase createSearchableEmployeeDB(Employee**, int);
Employee* findEmpBySSN(int, empDatabase);
Employee* findEmpByID(int, empDatabase);
void freeEmpDatabase(empDatabase);

void quickSort(empDatabase db, int low, int high)
{
    int i, j, pivot;
    Employee* temp;
    if (low < high) {
        pivot = low;
        i = low;
        j = high;

        while (i < j) {
            while (db.byID[i]->id <= db.byID[pivot]->id && i < high)
                i++;
            while (db.byID[j]->id > db.byID[pivot]->id)
                j--;
            if (i < j) {
                temp = db.byID[i];
                db.byID[i] = db.byID[j];
                db.byID[j] = temp;
            }
        }

        temp = db.byID[pivot];
        db.byID[pivot] = db.byID[j];
        db.byID[j] = temp;

        pivot = low;
        i = low;
        j = high;

        while (i < j) {
            while (db.bySSN[i]->ssn <= db.bySSN[pivot]->ssn && i < high)
                i++;
            while (db.bySSN[j]->ssn > db.bySSN[pivot]->ssn)
                j--;
            if (i < j) {
                temp = db.bySSN[i];
                db.bySSN[i] = db.bySSN[j];
                db.bySSN[j] = temp;
            }
        }

        temp = db.bySSN[pivot];
        db.bySSN[pivot] = db.bySSN[j];
        db.bySSN[j] = temp;
        quickSort(db, low, j - 1);
        quickSort(db, j + 1, high);
    }
}
int binarySearch(empDatabase, int find, int high, int low, int ssn)
{
    int mid = (db.size + 1) / 2;
    



}
empDatabase createSearchableEmployeeDB(Employee **db, int n)
{
    empDatabase newDB;
    newDB.byID = db;
    newDB.bySSN = db;
    newDB.size = n;
    quickSort(newDB, 0, n);
    return newDB;
}
Employee* findEmpBySSN(int ssn, empDatabase db)
{

}
Employee* findEmpByID(int id, empDatabase db)
{

}
void freeEmpDatabase(empDatabase db)
{

}