//queue using linear array 
#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isfull(struct queue *ptr)
{
    if(ptr->r==ptr->size-1)
    return 1;
    return 0;
}
int isempty(struct queue *ptr)
{
    if(ptr->f==ptr->r)
    return 1;
    return 0;
}

void enqueue(struct queue* s,int value)
{
    if(isfull(s))
    {
        printf("queue overflow");
    }
    else
    {
        s->r++;
        s->arr[s->r]=value;
        printf("element enqueued is %d\n",value);
    }
}

int dequeue(struct queue*s)
{
    int a=-1;
    if(isempty(s))
    {
        printf("queue underflow");
    }
    else
    {
        s->f++;
        a=s->arr[s->f];
        return a;
    }
    return a;
}
void traverse(struct queue* s) {
    for (int i = s->f + 1; i <= s->r; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int size()
{
    int size;
    printf("enter the capacity: ");
    scanf("%d",&size);
    return size;
}


int main()
{
    struct queue *s;
     s=(struct queue*)malloc(sizeof(struct queue));
    int n=size();
    s->size=n;
    s->f=s->r=-1;
    s->arr=(int*)malloc (s->size*sizeof(int));
    for(int i=0;i<n;i++)
    {
    enqueue(s,i+1);
    if(isfull(s))
    printf("sorry queue is full now ");
    } 
    traverse(s);
    
    int x=dequeue(s);
    printf("dequeued element is %d\n",x);
    int y=dequeue(s);
    printf("dequeued element is %d\n",y);
    printf("remaining elements in queue: ");
     traverse(s);
     if(isempty(s))
     {
        printf("queue is now empty");
     }
    return 0;
}