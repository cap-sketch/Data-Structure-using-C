//pop operation
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
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
        printf("value popped is %d ",value);
    }
return 0;
}