#include <stdio.h>
#include <stdlib.h>
int value = 0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void print(char *Str)
{
    printf("%s", Str);
}
int Scan_Value(char *data)
{
    printf("\nEnter a Value %s : ", data);
    scanf("%d", &value);
    return value;
}
void INSERT_NODE(struct node **root, int value)
{
    struct node *p = *root;
    struct node *q = *root;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    if (temp == NULL)
    {
        *root = temp;
    }
    else
    {
        while (p != NULL)
        {
            q = p;
            if (p->data >= value)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (q->data > value)
        {
            q->left = temp;
        }
        else
        {
            q->right = temp;
        }
    }
}
void IN_ORDER(struct node *my_node)
{
    if (my_node == NULL)
        return;
    IN_ORDER(my_node->left);
    printf("%4d ", my_node->data);
    IN_ORDER(my_node->right);
}

void PRE_ORDER(struct node *my_node)
{
    if (my_node == NULL)
        return;
    printf("%4d ", my_node->data);
    IN_ORDER(my_node->left);
    IN_ORDER(my_node->right);
}
void POST_ORDER(struct node *my_node)
{
    if (my_node == NULL)
        return;
    IN_ORDER(my_node->left);
    IN_ORDER(my_node->right);
    printf("%4d ", my_node->data);
}
int main()
{
    int test;
    struct node *root = NULL;
    printf("\n       <--^^^^^^^      BINARY SEARCH TREE     ^^^^^^^--> \n");
    while (1)
    {

        print("\n   <------- Enter Below Option -------> \n");
        print(".......................................................\n");
        print(".                                                     .\n");
        print(".      INSERT                   :           -> 1      .\n");
        print(".      IN FIX                   :           -> 2      .\n");
        print(".      PRE FIX                  :           -> 3      .\n");
        print(".      POST FIX                 :           -> 4      .\n");
        print(".      MAXIMUM                  :           -> 5      .\n");
        print(".      MINIMUM                  :           -> 6      .\n");
        print(".      SEARCH                   :           -> 7      .\n");
        print(".      DELETE                   :           -> 8      .\n");
        print(".......................................................\n");
        print(" OPTION : ");
        scanf("%d", &test);
        if (test == 1)
        {
            int x = Scan_Value("For Insearting");
            INSERT_NODE(&root, x);
            print("\n Value is inserted SUCESSFULLY ");
        }
        else if (test == 2)
        {
            print("IN_ORDER printing DATA :");
            IN_ORDER(root);
        }
        else if (test == 3)
        {
            print("PRE_ORDER printing DATA :");
            PRE_ORDER(root);
        }
        else if (test == 4)
        {
            print("POST_ORDER printing DATA :");
            POST_ORDER(root);
        }
        else if (test == 5)
        {
            print("Maximum value is : ");
            struct node *temp = root;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            printf("%d", temp->data);
        }
        else if (test == 6)
        {
            print("Minimum value is : ");
            struct node *temp = root;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            printf("%d", temp->data);
        }
        else
        {
            break;
        }
    }
}
