#include <stdio.h>
#include <stdlib.h>

#define max 6
char stack[max];
int top=-1;

int isp(char op)
{
    switch(op)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '$': return 3;
        case '(': return 0;
        default : return -1;  
    }
}
int icp(char op)
{
    switch(op)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '$': return 3;
        case '(': return 4;
        default : return -1;   
    }
}
void push(char x)
{
    if(top==max-1)
    {
        printf("stack is full\n");
        return'\0';
    }
    top++;
    stack[top]=x;
}
char pop(void)
{
    if(top==-1)
    {
        return'\0';
    }
    int x=stack[top];
    top--;
    return x;
}
void infix_exp( char exp[30])
{
    char c;
    for(int i=0;exp[i]!='\0';i++)
    {
        c=exp[i];
        if(c>='a' && c <='z' || c>='A' && c <='Z' || c>='0' && c<='9')
        {
            printf("%c ",c);
        }
        else if(c==')')
        {
            while(stack[top]!='(')
            {
                printf("%c",pop());
            }
            pop();
        }
        else
        {
            while(isp(stack[top])>=icp(c))
            {  
                printf("%c",pop());  
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }

}
int main()
{
    char exp[30];
    printf("Enter the X : ");
    scanf("%s",exp);
    infix_exp(exp);
}

