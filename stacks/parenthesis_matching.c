//parenthesis matching 
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int isempty(struct stack*ptr)
{
    if(ptr->top==-1)
    return 1;
    return 0;
}
int isfull(struct stack*ptr)
{
     if(ptr->top==ptr->size-1)
     return 1;
     return 0;
}

void  push(struct stack *s,char a)
{
    if(isfull(s))
    {
        printf("overflow condition\n");
    }
    else
    {
        struct stack*p=s;
        s->arr[++s->top]=a;
     //   printf("pushed element is %c\n",a);
    }
}
char pop(struct stack *s)
{
    if(isempty(s))
    {
        printf("underflow condtion\n");
        return -1;
    }
    else
    return s->arr[s->top--];
}

int parenthesismatching(char*exp,int n)
{
    struct stack*s=(struct stack*)malloc(sizeof(struct stack));
    s->size=n;
    s->top=-1;
    s->arr=(char*)malloc(n*sizeof(char));
     
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
         push(s,'(');
         }
         else if(exp[i]==')')
         {
            if(isempty(s))
            {
            return 0;
            }
             else
         pop(s);
         }
        
         
    }
    if(isempty(s))
    {
    return 1;
    }
    return 0;
}

int main()
{
    char exp[]="(3*(2+4))";
    int n=sizeof(exp)/sizeof(exp[0]);
    if(parenthesismatching(exp,n-1))
    printf("parenthesis matching");
    else
    printf("parenthesis not mathcing");
    return 0;
}