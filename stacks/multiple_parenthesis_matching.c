// multiple parenthesis matching 
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

int match(char a,char b)
{
    if(a=='(' && b==')')
    return 1;
    if(a=='{' && b=='}')
    return 1;
    if(a=='[' && b==']')
    return 1;
    return 0;
}

int parenthesismatching(char*exp,int n)
{
    char ch;
    struct stack*s=(struct stack*)malloc(sizeof(struct stack));
    s->size=n;
    s->top=-1;
    s->arr=(char*)malloc(n*sizeof(char));
     
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
         push(s,exp[i]);
         }
         else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
         {
            if(isempty(s))
            {
            return 0;
            }
             else
             {
               ch=pop(s);
               if(!match(ch,exp[i]))
               return 0;
             }
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
    char exp[]="{([3]*(2+4))}";
    int n=sizeof(exp)/sizeof(exp[0]);
    if(parenthesismatching(exp,n-1))
    printf("parenthes is matching");
    else
    printf("parenthes is not mathcing");
    return 0;
}