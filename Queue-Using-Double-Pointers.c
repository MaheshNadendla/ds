#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void push(struct node **front, struct node **rear)
{
        int x;
        struct node *p = *front;
        struct node *q = *rear;
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data Push : ");
        scanf("%d", &x);
        temp->data = x;
        temp->link = NULL;
        if (p == NULL && q == NULL)
        {
            *front = temp;
            *rear = temp;
        }
        else
        {
            q->link=temp;
            *rear=temp;
        }
}

void pop(struct node **front, struct node **rear)
{
    struct node *p = *front;
    struct node *q = *rear;
    if (p == NULL && q == NULL)
    {
        printf("Empty");
    }
    else
    {
        if (p == q)
        {
            *rear = NULL;
        }
        *front = p->link;
        p->link = NULL;
        free(p);
    }
}

void display(struct node **front, struct node **rear)
{
    struct node *p = *front;
    struct node *q = *rear;
    if (p == NULL && q == NULL)
    {
        printf("Empty not display");
    }
    else
    {
        printf("Data : ");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->link;
        }
    }
}

int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;
    int c;
    while (1)
    {
        printf("\n\nPUSH    : 1\n");
        printf("POP     : 2\n");
        printf("DISPLAY : 3\n");
        printf("EXIT    : X\n");
        printf("Enter Choice : ");
        scanf("%d", &c);
        if (c == 1)
        {
            push(&front, &rear);
        }
        else if (c == 2)
        {
            pop(&front, &rear);
        }
        else if (c == 3)
        {
            display(&front, &rear);
        }
        else
        {
            break;
        }
        // printf("\n front : %d rear : %d\n", front, rear);
    }
}
