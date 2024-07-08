//infix to posfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack *ptr)
{
    return ptr->top;
}
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

int precedence(char ch)
{
    if(ch=='*' || ch=='/')
    return 3;
    else if (ch=='+' || ch=='-')
    return 2;
    else
    return 0;
}

int isoperator(char ch)
{
    if(ch=='+'|| ch=='-'|| ch=='*'|| ch=='/')
    return 1;
    else
    return 0;
}

char * infixtopostfix(char*infix)
{
    struct stack *sp;
    sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sizeof(char)*sp->size);
    char *postfix=(char*)malloc(sizeof(char)*(strlen(infix)+1));
    int i=0;  //track infix traversal
    int j=0;  //track postfix addition
    while(infix[i]!='\0')
    {
        if(!isoperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stacktop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isempty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}


int main()
{
    char *infix="x-y*z";
    printf("postfix is %s",infixtopostfix(infix));

}