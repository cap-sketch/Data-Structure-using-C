//stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};

int isfull(struct node* ptr)
{
    struct node*p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        return 1;
    }
    return 0;
}

int isempty(struct node*ptr)
{
    if(ptr==NULL)
    return 1;
    return 0;
}

int peak(struct node*top,int pos)
{
    struct node*ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    return ptr->data;
    return -1;
}

int pop(struct node** top)
{
    if(isempty(*top))
    {
        printf("underflow condition");
    }
    struct node*p=*top;
     int x=(*top)->data;
     *top=(*top)->next;
     free(p);
    return x;
}

struct node* push(struct node*top,int value)
{
    if(isfull(top))
    {
        printf("stack overflow");
    }
    else
    {
        struct node*p=(struct node*)malloc(sizeof(struct node));
        p->data=value;
        p->next=top;
        top=p;
        return top;
    }
}

void traversal(struct node*ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node*top=NULL;
    //pushing 
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    top=push(top,4);
    traversal(top);
     //popping
     int x=pop(&top);
     printf("popped element is %d\n",x);
     int y=pop(&top);
     printf("popped element is %d\n",y);

  //peak operation
      int z=peak(top,1);
      printf("peeked element is %d\n",z);
    return 0;
}