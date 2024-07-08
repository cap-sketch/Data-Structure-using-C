//stack is full condition check
#include<stdio.h>
#include<stdlib.h>
 struct stack{
        int size;
        int top;
        int *arr;
    };
int isfull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    return 1;
    return 0;
}

int main()
{
   
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));//memory need to be allocate before access
    s->size=6;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int)); //allocating memory for the array
    
    if(isfull(s))
    {
        printf("stack is full");
    }
    else
    printf("stack is empty");
    return 0;

}