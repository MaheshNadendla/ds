#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head1 = NULL;
node *head2 = NULL;
node *ans = NULL;

void insertsll1()
{

    int a;
    printf("No of numbers in SLL-1 : ");
    scanf("%d", &a);
    int z[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &z[i]);
    }

    for (int i = 0; i < a; i++)
    {
        node *p = head1;
        node *temp = (node *)malloc(sizeof(node));
        temp->data = z[i];
        temp->next = NULL;

        if (p == NULL)
        {
            head1 = temp;
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
    printf("Inserted Sucess \n");
}

void insertsll2()
{

    int a;
    printf("No of numbers in SLL-2 : ");
    scanf("%d", &a);
    int z[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &z[i]);
    }

    for (int i = 0; i < a; i++)
    {
        node *p = head2;
        node *temp = (node *)malloc(sizeof(node));
        temp->data = z[i];
        temp->next = NULL;

        if (p == NULL)
        {
            head2 = temp;
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
    printf("Inserted Sucess \n");
}

void display()
{
    node *p = head1;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    node *q = head2;
    while (q != NULL)
    {
        printf("%d -> ", q->data);
        q = q->next;
    }
    printf("NULL\n");

    node *r = ans;
    while (r != NULL)
    {
        printf("%d -> ", r->data);
        r = r->next;
    }
    printf("NULL\n");
}

void merge() {
    if (head1 == NULL && head2 == NULL) {
        return;  
    }
    
    if (head1 == NULL) {
        ans = head2;  
        return;
    }

    if (head2 == NULL) {
        ans = head1;  
        return;
    }

    
    node *first = head1;
    node *second = head2;
    node *last = NULL;

    
    if (first->data <= second->data) {
        ans = first;
        first = first->next;
    } else {
        ans = second;
        second = second->next;
    }
    last = ans;

    
    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            last->next = first;
            first = first->next;
        } else {
            last->next = second;
            second = second->next;
        }
        last = last->next;
    }

    if (first != NULL) {
        last->next = first;
    } else {
        last->next = second;
    }
}


int main()
{
    int test;
    printf("\n       <--^^^^^^^      TESTING    ^^^^^^^--> \n");
    while (1)
    {
        printf("\n   <------- Enter Below Option -------> \n");
        printf("........................................... .\n");
        printf(".      OPTION 1 : Insert_sll1               .\n");
        printf(".      OPTION 2 : Insert_sll2               .\n");
        printf(".      OPTION 3 : display                   .\n");
        printf(".      OPTION 4 : Merge SLLs                .\n");
        printf(".      Exit     : Any other key             .\n");
        printf(".............................................\n");
        printf(" OPTION : ");
        scanf("%d", &test);

        if (test == 1)
        {
            insertsll1();
        }
        else if (test == 2)
        {
            insertsll2();
        }
        else if (test == 3)
        {
            display();
        }
        else if (test == 4)
        {
            merge();
        }
        else
        {
            break;
        }
    }

    return 0;
}
