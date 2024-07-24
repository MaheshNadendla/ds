#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

void push()
{

    int data;
    printf("Enter data for push :  ");
    scanf("%d", &data);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("empty\n");
    }
    else
    {
        node *p = top;
        top = top->next;
        p->next = NULL;
        free(p);
    }
}

void display()
{
    node *p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int option = 0;
    while (1)
    {
        printf(" PUSH    :->  1\n");
        printf(" POP     :->  2\n");
        printf(" DISPLAY :->  3\n");
        printf(" EXIT    :-> ANY\n");
        printf("OPTION : ");
        scanf("%d", &option);
        if (option == 1)
        {
            push();
        }
        else if (option == 2)
        {
            pop();
        }
        else if (option == 3)
        {
            display();
        }
        else
        {
            break;
        }
    }
}
