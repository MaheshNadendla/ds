#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void insertbegin()
{
    int a;
    printf("Enter data:");
    scanf("%d", &a);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;

    node *p = head;
    if (p == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = p;
        head = temp;
    }
}

void insertend()
{
    int a;
    printf("Enter data:");
    scanf("%d", &a);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;

    node *p = head;

    if (p == NULL)
    {
        head = temp;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void deletebegin()
{
    node *p = head;
    if (p == NULL)
    {
        printf("cant delete");
    }
    else
    {
        head = head->next;
        p->next = NULL;
        free(p);
    }
    
}

void deleteend()
{

    node *p = head;
    node *q = head;
    if (p == NULL)
    {
        printf("cant delete");
    }
    else
    {
        while (p->next != NULL)
        {
            q=p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
    }
}

void display()
{
    printf("\n");
    node *p = head;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL \n");
}

int main()
{
    int test;
    printf("\n       <--^^^^^^^      TESTING    ^^^^^^^--> \n");
    while (1)
    {

        printf("\n   <------- Enter Below Option -------> \n");
        printf("................................................................\n");
        printf(".                                                     .\n");
        printf(".      OPTION 1                 :           -> Insert_beg      .\n");
        printf(".      OPTION 2                 :           -> Insert_end      .\n");
        printf(".      OPTION 3                 :           -> delete_beg      .\n");
        printf(".      OPTION 4                 :           -> delete_end      .\n");
        printf(".      OPTION 5                 :           -> display         .\n");
        printf(".      Exit                     :           -> Any             .\n");
        printf("................................................................\n");
        printf(" OPTION : ");
        scanf("%d", &test);
        if (test == 1)
        {
            insertbegin();
        }
        else if (test == 2)
        {
            insertend();
        }
        else if (test == 3)
        {
            deletebegin();
        }
        else if (test == 4)
        {
            deleteend();
        }
        else if (test == 5)
        {
            display();
        }
        else
        {
            break;
        }
    }
}
