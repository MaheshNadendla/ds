#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void push(struct node **top)
{
    int x;
    struct node *p = *top;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data Push : ");
    scanf("%d", &x);
    temp->data = x;
    temp->link = NULL;
    if (p == NULL)
    {
        *top = temp;
    }
    else
    {
        temp->link = p;
        *top = temp;
    }
}

void pop(struct node **top)
{
    struct node *p = *top;
    *top = p->link;
    p->link = NULL;
    free(p);
}

void display(struct node **top)
{
    struct node *p = *top;
    if (p == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->link;
        }
    }
}

int main()
{
    int c;
    struct node *top = NULL;
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
            push(&top);
        }
        else if (c == 2)
        {
            pop(&top);
        }
        else if (c == 3)
        {
            display(&top);
        }
        else
        {
            break;
        }
    }
}
