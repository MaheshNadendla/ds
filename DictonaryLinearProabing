#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 6
typedef struct DICT
{
    int key;
    char name[30];
} d;
d a[n];
void insert(d item);
void deleteing(int k);
void search(int k);
void print(void);
void insiling(void)
{
    for (int i = 0; i < n; i++)
    {
        a[i].key = 0;
        strcpy(a[i].name, "NULL");
    }
}
int hash(int k)
{
    int i = k % 5;
    return i;
}
void insert(d item)
{
    int i = hash(item.key);
    while (i < n)
    {
        if (a[i].key == 0)
        {
            a[i] = item;
            break;
        }
        else
        {
            i++;
        }
    }
}
void deleteing(int k)
{
    int i = hash(k);
    if (a[i].key = k)
    {
        a[i].key = 0;
        strcpy(a[i].name, "NULL");
    }
    else
    {
        int flag = 0;
        while (i < n)
        {
            if (a[i].key = k)
            {
                flag = 1;
                a[i].key = 0;
                strcpy(a[i].name, "NULL");
                break;
            }
            i++;
        }
        if (flag == 0)
        {
            printf("key not found");
        }
    }
}
void search(int k)
{
    int i = hash(k);
    if (a[i].key = k)
    {
        printf("key is %d  : ", a[i].key);
        printf("name is %s \n", a[i].name);
    }
    else
    {
        int flag = 0;
        while (i < n)
        {
            if (a[i].key = k)
            {
                flag = 1;
                printf("key is %d  : ", a[i].key);
                printf("name is %s \n", a[i].name);
                break;
            }
            i++;
        }
        if (flag == 0)
        {
            printf("key not found");
        }
    }
}
void print(void)
{
    for (int i = 0; i < n; i++)
    {
        printf("key is %d  : ", a[i].key);
        printf("name is %s \n", a[i].name);
    }
}
int main()
{
    int test;
    d item;
    printf("\n       <--^^^^^^^      TESTING    ^^^^^^^--> \n");
    insiling();
    while (1)
    {

        printf("\n   <------- Enter Below Option -------> \n");
        printf(".......................................................\n");
        printf(".                                                     .\n");
        printf(".      PRINT  1                 :           -> 1      .\n");
        printf(".      INSERT 2                 :           -> 2      .\n");
        printf(".      SEARCH 3                 :           -> 3      .\n");
        printf(".      DELETE 4                 :           -> 4      .\n");
        printf(".      OPTION EXIT              :           -> ANY     .\n");
        printf(".......................................................\n");
        printf(" OPTION : ");
        scanf("%d", &test);
        if (test == 1)
        {
            print();
        }
        else if (test == 2)
        {
            printf("Enter a key : ");
            scanf("%d", &item.key);
            printf("Enter a name : ");
            scanf("%s", item.name);
            insert(item);
        }
        else if (test == 3)
        {
            printf("Enter a key : ");
            scanf("%d", &item.key);
            search(item.key);
        }
        else if (test == 4)
        {
            printf("Enter a key : ");
            scanf("%d", &item.key);
            deleteing(item.key);
        }
        else
        {
            break;
        }
    }
}
