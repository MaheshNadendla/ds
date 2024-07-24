#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue()
{
    int data;
    printf("Enter data for enqueue: ");
    scanf("%d", &data);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *p = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        free(p);
    }
}

void display()
{
    node *p = front;
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
        printf(" ENQUEUE :->  1\n");
        printf(" DEQUEUE :->  2\n");
        printf(" DISPLAY :->  3\n");
        printf(" EXIT    :-> ANY\n");
        printf("OPTION : ");
        scanf("%d", &option);
        if (option == 1)
        {
            enqueue();
        }
        else if (option == 2)
        {
            dequeue();
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
    return 0;
}
