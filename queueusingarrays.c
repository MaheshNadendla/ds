#include <stdio.h>
#include <stdlib.h>
#define size 10
int a[size];
int front = 0;
int rear = -1;

void enque()
{
    int x;
    if (rear == size - 1)
    {
        printf("full");
    }
    else
    {
        printf("Enter Data Push : ");
        scanf("%d", &x);
        rear++;
        a[rear] = x;
    }
}

void deque()
{
    if (front == rear + 1)
    {
        printf("Empty");
        front = 0;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == rear + 1)
    {
        printf("Empty not display");
    }
    else
    {
        printf("Data : ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", a[i]);
        }
    }
}

int main()
{
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
            enque();
        }
        else if (c == 2)
        {
            deque();
        }
        else if (c == 3)
        {
            display();
        }
        else
        {
            break;
        }
        printf("\n front : %d rear : %d\n", front, rear);
    }
}
