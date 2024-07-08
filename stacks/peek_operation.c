//peek operation
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int peek(struct stack *ptr,int i)         //peek operation at given position i
{                                          //here, arrindex=top-i+1
    if(ptr->top-i+1<0)
    {
        printf("invalid position");
        return -1;
    }
    else
    return ptr->arr[ptr->top-i+1];
}
int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    return 1;
    else
    return 0;
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=8;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    //let us first put some value in stack
    if(isfull(s))
    printf("overflow condition");
    else
    {
    s->top++;
    s->arr[s->top]=4;
    }
    //pop operation
    if(isempty(s))
    {
        printf("underflow condition");
    }
    else
    {
        int value=s->arr[s->top];
        s->top--;
        printf("value popped is %d \n",value);
    }
    //peek operation at position i
    int i=0;
    int val=peek(s,i);
    printf("the peeked value at position %d is %d ",i+1,val);
return 0;
}