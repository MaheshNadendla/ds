#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;
node *head2 = NULL;
node *x = NULL;

void insertbegin() {
    int a;
    printf("Enter data: ");
    scanf("%d", &a);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = a;
    temp->next = head;
    head = temp;
}

void insertend() {
    int a;
    printf("Enter data: ");
    scanf("%d", &a);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void insertend2() {
    int a;
    printf("Enter data: ");
    scanf("%d", &a);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;

    if (head2 == NULL) {
        head2 = temp;
    } else {
        node *p = head2;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void deletebegin() {
    if (head == NULL) {
        printf("Can't delete, list is empty\n");
        return;
    }

    node *p = head;
    head = head->next;
    free(p);
}

void deleteend() {
    if (head == NULL) {
        printf("Can't delete, list is empty\n");
        return;
    }

    node *p = head;
    if (p->next == NULL) {
        head = NULL;
    } else {
        node *q;
        while (p->next != NULL) {
            q = p;
            p = p->next;
        }
        q->next = NULL;
    }
    free(p);
}

void reverse(node **head_ref) {
    node *p = *head_ref;
    node *prev = NULL, *next = NULL;

    while (p != NULL) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }

    *head_ref = prev;
}

void display(node *head) {
    node *p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void addslls() {
    if (head == NULL || head2 == NULL) {
        printf("One of the lists is empty, can't add\n");
        return;
    }

    reverse(&head);
    reverse(&head2);

    node *p = head;
    node *q = head2;
    int carry = 0;

    while (p != NULL || q != NULL || carry > 0) {
        int sum = carry;
        if (p != NULL) {
            sum += p->data;
            p = p->next;
        }
        if (q != NULL) {
            sum += q->data;
            q = q->next;
        }

        carry = sum / 10;
        int value = sum % 10;

        node *temp = (node *)malloc(sizeof(node));
        temp->data = value;
        temp->next = x;
        x = temp;
    }

    reverse(&head);
    reverse(&head2);

    printf("Sum list: ");
    display(x);
}

void addone() {
    if (head == NULL) {
        printf("Empty list, can't add one\n");
        return;
    }

    reverse(&head);

    node *p = head;
    int carry = 1;

    while (p != NULL && carry > 0) {
        int sum = p->data + carry;
        carry = sum / 10;
        p->data = sum % 10;
        if (p->next == NULL && carry > 0) {
            node *temp = (node *)malloc(sizeof(node));
            temp->data = carry;
            temp->next = NULL;
            p->next = temp;
            carry = 0;
        }
        p = p->next;
    }

    reverse(&head);
    printf("List after adding one: ");
    display(head);
}

int main() {
    int test;
    printf("\n       <--^^^^^^^      TESTING    ^^^^^^^--> \n");
    while (1) {
        printf("\n   <------- Enter Below Option -------> \n");
        printf("........................................... .\n");
        printf(".      OPTION 1 : Insert_beg                .\n");
        printf(".      OPTION 2 : Insert_end                .\n");
        printf(".      OPTION 3 : delete_beg                .\n");
        printf(".      OPTION 4 : delete_end                .\n");
        printf(".      OPTION 5 : display                   .\n");
        printf(".      OPTION 6 : reverse                   .\n");
        printf(".      OPTION 7 : addone                    .\n");
        printf(".      OPTION 8 : Insert_end2               .\n");
        printf(".      OPTION 9 : addsll                    .\n");
        printf(".      Exit     : Any other key             .\n");
        printf(".............................................\n");
        printf(" OPTION : ");
        scanf("%d", &test);

        if (test == 1) {
            insertbegin();
        } else if (test == 2) {
            insertend();
        } else if (test == 3) {
            deletebegin();
        } else if (test == 4) {
            deleteend();
        } else if (test == 5) {
            display(head);
            display(head2);
        } else if (test == 6) {
            reverse(&head);
            printf("Reversed list: ");
            display(head);
        } else if (test == 7) {
            addone();
        } else if (test == 8) {
            insertend2();
        } else if (test == 9) {
            addslls();
        } else {
            break;
        }
    }

    return 0;
}
