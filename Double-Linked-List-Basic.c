#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
void beg_ins(int val);
void beg_del();
void display();

void main()
{
    int choice = 0, val;
    while (10)
    {
        printf("1.insertbeg\n2.deletebeg\n3.display\n4.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter:");
            scanf("%d", &val);
            beg_ins(val);
            break;
        case 2:
            beg_del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}

void beg_ins(int val)
{
    int item = val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node ));
    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->data = item;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void beg_del()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            head = temp->next;
            head->prev = NULL;
            free(temp);
        }
    }
}

void display()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp = head;
    if (temp == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
