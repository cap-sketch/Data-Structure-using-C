//practising stack using array
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int isfull(struct stack *s)
{
    if(s->top==s->size-1)
    return 1;
    return 0;
}

int isempty(struct stack *s)
{
    if(s->top==-1)
    return 1;
    return 0;
}

void push(struct stack*s,int value)
{
    if(isfull(s))
    {
    printf("overflow condition");
    return;
    }
    s->arr[++s->top]=value;
    printf("the pushed value is %d\n",value);
}

int pop(struct stack *s)
{
    if(isempty(s))
    {
        printf("underflow condition");
        return -1;
    }
    return s->arr[s->top--];
}

int peak(struct stack*s,int i)
{
    if(s->top-i+1<0)
    {
        printf("invalid position");
        return -1;
    }
    return s->arr[s->top-i+1];
}
int stacktop(struct stack*s)
{
    return s->arr[s->top];
}
int stackbottom(struct stack*s)
{
    return s->arr[0];
}

int main()
{
    struct stack *s;
    s=(struct stack*)malloc (sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc(sizeof(int)*s->size);
    //now pushing elements
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);

    //pop operation
    int val=pop(s);
    printf("\npopped element is %d\n",val);

    int x=peak(s,2);
    printf("\npeaked element is %d",x);

    int y=stacktop(s);
    int z=stackbottom(s);
    printf("\nstack top is %d\nstack bottom is %d",y,z);
    return 0;

}