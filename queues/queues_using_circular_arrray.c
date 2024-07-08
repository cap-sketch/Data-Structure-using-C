//queues using circular arrays
#include<stdio.h>
#include<stdlib.h>
struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isfull(struct circularqueue*s)
{
    if((s->r+1)%(s->size)==s->f)
    return 1;
    return 0;
}
int isempty(struct circularqueue*s)
{
    if((s->r==s->f))
    return 1;
    return 0;
}


void enqueue(struct circularqueue*s,int value)
{
    if(isfull(s))
    printf("queue overflow");
    else
    {
        s->r=(s->r+1)%(s->size);    //circular incrementation
        s->arr[s->r]=value;
        printf("enqueued value is %d\n",value);
    }
}

int  dequeue(struct circularqueue*s)
{
    int value=-1;
    if(isempty(s))
    printf("queue underflow");
    else
    {
        s->f=(s->f+1)%(s->size);    //circular incrementation
        value=s->arr[s->f];
    }
    return value;
}

int main()
{
    struct circularqueue *s;
    s=(struct circularqueue*)malloc(sizeof(struct circularqueue));
    s->size=10;
    s->f=s->r=0;
    s->arr=(int*)malloc(s->size*sizeof(int));
    //inserting
    enqueue(s,4);
    enqueue(s,5);
    //removing
    printf("dequeued value is:%d\n",dequeue(s));
    return 0;
}
