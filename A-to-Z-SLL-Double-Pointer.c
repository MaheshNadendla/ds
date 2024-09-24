 #include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void ptlst(struct node **head)
{
    struct node *p = *head;
    if (p == NULL)
    {
        printf("   -------[EMPTY]------->   :  HEAD ");
    }
    else
    {
        printf("   --------------------->  :  HEAD ");
        while (p != NULL)
        {
            printf(" -> %d ", p->data);
            p = p->link;
        }
    }
    printf("-> NULL");
}
void printlst(struct node **head)
{
    printf(" <- SELECTED : Printing the List ->\n");
    struct node *p = *head;
    printf("\n Elements are in the LIst : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\nMESSAGE : Elements are Printed Sucessfully");
    printf("\n");
}
void add_end(struct node **head)
{
    printf(" <- SELECTED : Insert at Ending ->\n");
    int value = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value inserting Ending  : ");
    scanf("%d", &value);
    temp->data = value;
    temp->link = NULL;
    struct node *p = *head;
    if (p == NULL)
    {
        *head = temp;
    }
    else
    {
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
    printf(" MESSAGE : Inserted at end Sucessfully ");
}



void add_beg(struct node **head)
{
    printf(" <- SELECTED : Insert at Begining ->\n");
    int value = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value inserting begining : ");
    scanf("%d", &value);
    temp->data = value;
    temp->link = NULL;
    struct node *p = *head;
    if (p == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->link = p;
        *head = temp;
    }
    printf(" MESSAGE : value is inserted at begining sucessfully");
}
void add_pos(struct node **head, int pos)
{
    printf(" <- SELECTED : Insert at Position ->\n");
    int value = 0;
    int count = 2;
    if (pos == 1)
    {
        add_beg(head);
    }
    else
    {
        struct node *p = *head;
        while (p != NULL)
        {
            if (count == pos)
            {
                break;
            }
            p = p->link;
            count++;
        }
        if (p == NULL)
        {
            printf("invalid position");
        }
        else
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value : ");
            scanf("%d", &value);
            temp->data = value;
            temp->link = p->link;
            p->link = temp;
            printf(" MESSAGE : Element is inserted at spesified position sucessfully");
        }
    }
}
void del_elmt(struct node **head, int value)
{
    printf(" <- SELECTED : Deleting of Element ->\n");
    struct node *p = *head;
    struct node *q = NULL;
    while (p != NULL)
    {
        if (p->data == value)
        {
            break;
        }
        q = p;
        p = p->link;
    }
    if (p == NULL)
    {
        printf(" Element is not Present in the List\n");
    }
    else if (q == NULL)
    {
        *head = p->link;
        printf("Begining Element is deleted Sucessfully \n");
    }
    else
    {
        q->link = p->link;
        p->link = NULL;
        free(p);
        printf("Targeted Element is deleted Sucessfully \n");
    }
}
void del_pos_elmt(struct node **head)
{
    printf(" <- SELECTED : Deleting the Position NODE ->\n");
    int position;
    int count = 1, x = 0;
    printf("Enter the target NODE Number : ");
    scanf("%d", &position);
    struct node *p = *head;
    struct node *q = NULL;
    while (p != NULL)
    {
        if (count == position)
        {
            break;
        }
        q = p;
        p = p->link;
        count++;
    }
    if (p == NULL)
    {
        printf(" NODE position is not Present in the List");
    }
    else if (q == NULL)
    {
        x = p->data;
        *head = p->link;
        printf("Begining NODE is deleted Sucessfully \n");
        printf("Targeted Element : %d is deleted Sucessfully  \n", x);
    }
    else
    {
        q->link = p->link;
        x = p->data;
        p->link = NULL;
        free(p);
        printf("Targeted Element : %d is deleted Sucessfully  ", x);
    }
}
void search(struct node **head)
{
    int a[1000], i = 0;
    printf(" <- SELECTED : Searching of Element ->\n");
    int value = 0, cnt = 0;
    printf("Enter the scanimg Element in List : ");
    scanf("%d", &value);
    struct node *p = *head;
    while (p != NULL)
    {
        cnt++;
        if (p->data == value)
        {
            a[i] = cnt;
            i++;
        }
        p = p->link;
    }
    if (i == 0)
    {
        printf("\nElement is not found in the List");
    }
    else
    {
        printf("\nElement is found at position's :");
        for (int j = 0; j < i; j++)
        {
            printf(" , %d ", a[j]);
        }
    }
}
int count(struct node **head, int val)
{
    printf(" <- SELECTED : Counting the Element in List ->\n");
    struct node *p = *head;
    int count = 0;
    while (p != NULL)
    {
        if (p->data == val)
        {
            count++;
        }
        p = p->link;
    }
    return count;
}
void delete_elmt_at_all(struct node **head)
{
    int n = 0, val = 0;
    printf(" <- SELECTED : Deleting of Element at ALL Positions ->\n");
    printf("Enter the target value : ");
    scanf("%d", &val);
    n = count(head, val);
    for (int i = 0; i < n; i++)
    {
        del_elmt(head, val);
    }
}
void Elmt_locations(struct node **head)
{
    int a[1000], i = 0, count = 0;
    printf(" <- SELECTED : Finding the Element Locations in List ->\n");
    struct node *p = *head;
    int val = 0;
    printf("Enter the Element you R Finding Locations in list : ");
    scanf("%d", &val);
    while (p != NULL)
    {
        count++;
        if (p->data == val)
        {
            a[i] = count;
            i++;
        }
        p = p->link;
    }

    if (i == 0)
    {
        printf("Element is not found any location in the List");
    }
    else
    {
        printf("\nThe POSITIONS are : ");
        for (int j = 0; j < i; j++)
        {
            printf(" , %d ", a[j]);
        }
    }
}
void up_Sort(struct node **head)
{
    int swapped, temp;
    struct node *p;
    struct node *last = NULL;
    printf("<- SELECTED : ASCENDING Order ->\n");

    // Check for empty list
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        p = *head;

        while (p->link != last)
        {
            if (p->data > p->link->data)
            {
                // Swap the data of current and next nodes
                temp = p->data;
                p->data = p->link->data;
                p->link->data = temp;
                swapped = 1;
            }
            p = p->link;
        }
        last = p;
    } while (swapped);
    printf("MESSAGE : ASCENDING Order Sucessfully");
}
void down_Sort(struct node **head)
{
    int swapped, temp;
    struct node *p;
    struct node *last = NULL;
    printf("<- SELECTED : DECENDING Order ->\n");
    // Check for empty list
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        p = *head;

        while (p->link != last)
        {
            if (p->data < p->link->data)
            {
                // Swap the data of current and next nodes
                temp = p->data;
                p->data = p->link->data;
                p->link->data = temp;
                swapped = 1;
            }
            p = p->link;
        }
        last = p;
    } while (swapped);
    printf("MESSAGE : DECENDING Order Sucessfully");
}
int main()
{
    int test, pos = 0, cnt = 0, val = 0, value = 0;
    struct node *head = NULL;
    printf("\n       <--^^^^^^^ SINGLE_LINKED_IMPLEMENTATION ^^^^^^^--> \n");
    while (1)
    {

        printf("\n              <------- Enter Below Option -------> \n");
        printf("...................................................................\n");
        printf(".                                                                 .\n");
        printf(".      INSERT_AT_ENDING                     :           -> 1      .\n");
        printf(".      INSERT_AT_BEGINNING                  :           -> 2      .\n");
        printf(".      INSERT_AT_POSITION                   :           -> 3      .\n");
        printf(".      INSERT_AT_POSITION LEFT              :           -> 4      .\n");
        printf(".      INSERT_AT_POSITION RIGHT             :           -> 5      .\n");
        printf(".      DELETE_ELEMENT_AT_FIRST_CATCH        :           -> 6      .\n");
        printf(".      DELETE_NODE_BY_POSITION              :           -> 7      .");
        ptlst(&head);
        printf("\n");
        printf(".      DISPLAY_ELEMENTS_IN_LIST             :           -> 8      .\n");
        printf(".      SEARCH_ELEMENT_AT_ALL_POSITIONS      :           -> 9      .\n");
        printf(".      COUNT_THE_ELEMENT_REPEATED           :           -> 10     .\n");
        printf(".      DELETE_ELEMENT_AT_ALL_POSITIONS      :           -> 11     .\n");
        printf(".      ELEMENT_TO_NODE_POSITION             :           -> 12     .\n");
        printf(".      SORT_ASCENDING_ORDER                 :           -> 13     .\n");
        printf(".      SORT_DESCENING_ORDER                 :           -> 14     .\n");
        printf(".      EXIT_[OTHER_THEN_UP_KEYS]            :           -> ANY    .\n");
        // printf(".                                                                 .\n");
        printf("...................................................................\n");
        printf(" OPTION : ");
        scanf("%d", &test);
        if (test == 1)
        {
            add_end(&head);
        }
        else if (test == 2)
        {
            add_beg(&head);
        }
        else if (test == 3)
        {
            printf("Enter the position for Element Inserting: ");
            scanf("%d", &pos);
            add_pos(&head, pos);
        }
        else if (test == 4)
        {
            printf("Enter the position for Element Inserting: ");
            scanf("%d", &pos);
            add_pos(&head, pos - 1);
        }
        else if (test == 5)
        {
            printf("Enter the position for Element Inserting: ");
            scanf("%d", &pos);
            add_pos(&head, pos + 1);
        }
        else if (test == 6)
        {
            printf("Enter the target value : ");
            scanf("%d", &value);
            del_elmt(&head, value);
        }
        else if (test == 7)
        {
            del_pos_elmt(&head);
        }
        else if (test == 8)
        {
            printlst(&head);
        }
        else if (test == 9)
        {
            search(&head);
        }
        else if (test == 10)
        {
            printf("Enter the Value you are Counting : ");
            scanf("%d", &val);
            cnt = count(&head, val);
            printf("The Element Present in the List is : %d TIME'S\n", cnt);
            printf(" MESSAGE : Element is Counted in the list sucessfully");
        }
        else if (test == 11)
        {
            delete_elmt_at_all(&head);
        }
        else if (test == 12)
        {
            Elmt_locations(&head);
        }
        else if (test == 13)
        {
            up_Sort(&head);
        }
        else if (test == 14)
        {
            down_Sort(&head);
        }
        else
        {
            break;
        }
    }
}
