#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void beg_ins(int val);
void beg_del();
void display();

void main()
{
    int choice = 0, val;
    while (choice != 9)
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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = item;
    struct node *temp = head;

    if (head == NULL)
    {
        head = ptr;
        head->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
    }
}

void beg_del()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        if (head->next == head)
        {
            head = NULL;
            free(head);
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    }
}

void display()
{
    struct node *temp; //= (struct node *)malloc(sizeof(struct node));
    temp = head;
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
