// push operation
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, int value)
{
    if (isfull(s))
    {
        printf("overflow condition");
        return ;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("pushed value is %d", value);
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // push operation
    int value = 5;
    push(s, value);
    return 0;
}
