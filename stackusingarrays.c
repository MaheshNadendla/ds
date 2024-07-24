#include <stdio.h>
#define size 6
int arr[size];
int top=-1;

void push()
{
    printf("MESSAGE : ENTERED PUSH\n");
    int a=0;
    if(top==size-1)
    {
        printf("<- THE STACK IS FULL CAN'T PUSH ->\n");
    }
    else
    {
        printf("Enter the data inserting : ");
        scanf("%d",&a);
        top=top+1;
        arr[top]=a;
    }
    printf("\nSUCESS : PUSHED SUCESS\n");
}
void pop()
{
    printf("MESSAGE : ENTERED POP\n");
    if(top==-1)
    {
       printf("<- THE STACK IS EMPTY CAN'T POP ->\n"); 
    }
    else
    {
        top=top-1;
    }
    printf("SUCESS : POPED SUCESS\n");

}

void display()
{
    printf("MESSAGE : ENTERED DISPLAY\n");
    if(top==-1)
    {
       printf("<- THE STACK IS EMPTY ->\n"); 
    }
    else
    {
        printf("DATA : ");
        for(int i=top;i>=0;i--)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    printf("SUCESS : DISPLAYED SUCESS \n");

}

int main()
{
    int option=0;
    while(1)
    {
        printf(" PUSH    :->  1\n");
        printf(" POP     :->  2\n");
        printf(" DISPLAY :->  3\n");
        printf(" EXIT    :-> ANY\n");
        printf("OPTION : ");
        scanf("%d",&option);
        if(option==1)
        {
            push();
        }
        else if(option==2)
        {
            pop();
        }
        else if(option==3)
        {
            display();
        }
        else{
            break;
        }
    }

}
