#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void Insert_end(struct node **head)
{
    int x = 0;
    printf(" End value enter : ");
    scanf("%d", &x);
    struct node *p = *head;
    struct node *q = NULL;
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->link = NULL;
    temp->data = x;
    if (p == NULL)
    {
        *head = temp;
        temp->link = temp;
    }
    else
    {
        while (p->link != *head)
        {
            p = p->link;
        }
        p->link = temp;
        temp->link = *head;
    }
}

void Insert_beg(struct node **head)
{
    int x = 0;
    printf(" fnt value enter : ");
    scanf("%d", &x);
    struct node *p = *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->link = NULL;
    temp->data = x;
    if (p == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->link = p;
        *head = temp;
    }
}

void Insert_pos(struct node **head)
{
    int x = 0;
    printf(" pos value enter : ");
    scanf("%d", &x);
    struct node *p = *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->link = NULL;
    temp->data = x;
    if (p == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->link = p;
        *head = temp;
    }
}

void Display(struct node **head)
{
    struct node *p = *head;
    if (p == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (p->link != *head)
        {
            printf("%d ", p->data);
            p = p->link;
        }
        printf("%d ", p->data);
    }
}
int main()
{
    int test;
    struct node *head = NULL;
    printf("\n       <--^^^^^^^      TESTING    ^^^^^^^--> \n");
    while (1)
    {

        printf("\n   <------- Enter Below Option -------> \n");
        printf(".......................................................\n");
        printf(".                                                     .\n");
        printf(".      OPTION 1                 :           -> 1      .\n");
        printf(".      OPTION 2                 :           -> 2      .\n");
        printf(".      OPTION 3                 :           -> 3      .\n");
        printf(".      OPTION 4                 :           -> 4      .\n");
        printf(".      OPTION 5                 :           -> 5      .\n");
        printf(".      OPTION 6                 :           -> 6      .\n");
        printf(".      OPTION 7                 :           -> 7      .\n");
        printf(".......................................................\n");
        printf(" OPTION : ");
        scanf("%d", &test);
        if (test == 1)
        {
            Insert_end(&head);
        }
        else if (test == 2)
        {
            Insert_beg(&head);
        }
        else if (test == 3)
        {
            Display(&head);
        }
        else
        {
            break;
        }
    }
}
