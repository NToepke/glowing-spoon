#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 10
typedef struct { 
    int id, jobType;
    float salary;
} Employee;

Employee * readEmployeeInfo(FILE *fp, int *numElems);
Employee * getEmployeeByID(Employee *p, int numEmps, int ID);

void setID(Employee *p, int id);
int getID(Employee *p);
void setjobType(Employee *p, int jobType);
int getjobType(Employee *p);
void setSalary(Employee *p, float salary);
float getSalary(Employee *p);

int main (void)
{
FILE *fp;
if((fp=fopen("testdata.txt","r"))==NULL)
{
    printf("ERROR: OOBA\n");
    fclose(fp);
    return 0;
}
else
{
    int size = ARRSIZE;
    Employee * array=readEmployeeInfo(fp,&size);
    fclose(fp);

    Employee *jptr=NULL;
    jptr = getEmployeeByID(array,size,2);

    if(jptr!=NULL)
    {
    setID(jptr,7);
    setSalary(jptr,500.00);
    setjobType(jptr,2);

    int a=0,b=0;
    float c=0;
    a=getID(jptr);
    b=getjobType(jptr);
    c=getSalary(jptr);
    a+=7;
    b+=7;
    c+=7;
    printf("%d %d %f",a,b,c);
    }
    free(array);

}
}

Employee * readEmployeeInfo(FILE *fp, int *numElems)
{
    fscanf(fp,"%d", numElems);
    Employee * array=NULL;

    if((array = malloc(*numElems * sizeof(Employee)))==NULL)
    {
        printf("Memory Allocation Failure!");
        return NULL;
    }
    else
    {
        for(int i=0;i<*numElems;i++)
        {
            fscanf(fp,"%d %d %f", &array[i].id, &array[i].jobType, &array[i].salary);
        }
    }
    return array;
}

Employee * getEmployeeByID(Employee *p, int numEmps, int ID)
{
    for(int i=0;i<numEmps;i++)
    {
        if(ID==getID(&p[i]))
            return p; 

    }
    return NULL;
}

void setID(Employee *p, int ids)
{
    p->id = ids;
}
int getID(Employee *p)
{
    return p->id;
}
void setjobType(Employee *p, int jobType)
{
    p->jobType=jobType;
}
int getjobType(Employee *p)
{
    return p->jobType;
}
void setSalary(Employee *p, float salary)
{
    p->salary=salary;
}
float getSalary(Employee *p)
{
    return p->salary;
}