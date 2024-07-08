//stack isempty condition check
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
    return 1;
    return 0;
}

int main()
{
   
    struct stack *s;
    //allocate memory for pointer
    s=(struct stack*)malloc(sizeof(struct stack));
    s->size=6;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int)); //allocating memory for the array
    //putting value in stack
    s->arr[0]=5;
    s->top++;
    if(isempty(s))
    {
        printf("stack is empty");
    }
    else
    printf("stack is not empty");
    return 0;

}