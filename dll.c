#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node * head = NULL;
void ptlst()
{
    struct node *p = head;
    if (p == NULL)
    {
        printf("   ------------------------->  :  EMPTY");
    }
    else
    {
        printf("   ------------------------->  :  ");
        while (p != NULL)
        {
            printf(" -> %d ", p->data);
            p = p->right;
        }
    }
}
void printlst()
{
    printf(" <- SELECTED : Printing the List ->\n");
    struct node *p = head;
    printf("\n Elements are : ");
    while (p != NULL)
    {
        printf(" %d  ", p->data);
        p = p->right;
    }
    printf("\nMESSAGE : Elements are Printed Sucessfully");
    printf("\n");
}
void add_end()
{
    printf(" <- SELECTED : Insert at Ending ->\n");
    int value = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value inserting Ending  : ");
    scanf("%d", &value);
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    struct node *p = head;
    if (p == NULL)
    {
        head = temp;
    }
    else
    {
        while (p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
    printf(" MESSAGE : Inserted at end Sucessfully ");
}

void add_beg()
{
    printf(" <- SELECTED : Insert at Begining ->\n");
    int value = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value inserting begining : ");
    scanf("%d", &value);
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    struct node *p = head;
    if (p == NULL)
    {
        head = temp;
    }
    else
    {
        temp->right = p;
        p->left = temp;
        head = temp;
    }
    printf(" MESSAGE : value is inserted at begining sucessfully");
}

void add_pos()
{
    printf(" <- SELECTED : Insert at Position ->\n");
    int value = 0;
    int pos = 0;
    int count = 2;
    int cnt = 1;
    printf("Enter the position for Element Inserting: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        add_beg(head);
    }
    else
    {
        struct node *p = head;
        struct node *q = head;
        while (p != NULL)
        {
            if (count == pos)
            {
                break;
            }
            p = p->right;
            count++;
        }
        while (q != NULL)
        {
            q = q->right;
            cnt++;
        }
        if (p == NULL)
        {
            printf("invalid position");
        }
        else if (count == cnt)
        {
            printf("this");
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value : ");
            scanf("%d", &value);
            temp->data = value;
            temp->right = NULL;
            p->right = temp;
            temp->left = p;
            printf(" MESSAGE : Element is inserted at spesified position sucessfully");
        }
        else
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value : ");
            scanf("%d", &value);
            temp->data = value;
            temp->right = p->right;
            p->right = temp;
            temp->right->left = temp;
            temp->left = p;
            printf(" MESSAGE : Element is inserted at spesified position sucessfully");
        }
    }
}

void del_elmt()
{
    printf(" <- SELECTED : Deleting of Element ->\n");
    int value = 0, m = 1, n = 0;
    printf("Enter the target value : ");
    scanf("%d", &value);
    struct node *p = head;
    struct node *r = head;
    struct node *q = NULL;
    while (p != NULL)
    {
        if (p->data == value)
        {
            break;
        }
        m++;
        q = p;
        p = p->right;
    }
    while (r != NULL)
    {
        n++;
        r = r->right;
    }
    if (p == NULL)
    {
        printf(" Element is not Present in the List");
    }
    else if (q == NULL)
    {
        head = p->right;
        printf("Begining Element is deleted Sucessfully ");
    }
    else
    {
        if (m == n)
        {
            q->right = NULL;
            p->left = NULL;
            p->right = NULL;
            free(p);
        }
        else
        {

            q->right = p->right;
            p->right->left = q;
            p->left = NULL;
            p->right = NULL;
            free(p);
            printf("Targeted Element is deleted Sucessfully ");
        }
    }
}
void search()
{
    printf(" <- SELECTED : Searching of Element ->\n");
    int value = 0, cnt = 1;
    printf("Enter the scanimg Element in List : ");
    scanf("%d", &value);
    struct node *p = head;
    while (p != NULL)
    {
        if (p->data == value)
        {
            break;
        }
        p = p->right;
        cnt++;
    }
    if (p == NULL)
    {
        printf("Element is not found in the List");
    }
    else
    {
        printf("Element is found at %d position in List", cnt);
    }
}
int main()
{
    int test;
    struct node *head = NULL;
    while (1)
    {

        printf("\n<------ Enter the Option -------> ");
        printf("\n..................................\n");
        printf(".                                .\n");
        printf(".           End -> 1             .  \n.           Beg -> 2             .   \n.           Pos -> 3             . \n.           delete -> 4          . ");
        ptlst(&head);
        printf("\n.           print -> 5           . \n.           search -> 6          . \n.           exit -> Any          .\n");
        // printf(".                                .\n");
        printf("..................................\n");
        printf(" OPTION : ");
        scanf("%d", &test);
        if (test == 1)
        {
            add_end();
        }
        else if (test == 2)
        {
            add_beg();
        }
        else if (test == 3)
        {
            add_pos();
        }
        else if (test == 4)
        {
            del_elmt();
        }
        else if (test == 5)
        {
            printlst();
        }
        else if (test == 6)
        {
            search();
        }
        else
        {
            break;
        }
    }
}
