//doubly linked list
#include<stdio.h>
#include<stdlib.h>

//implementing doubly linked list
struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void printforward(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void printbackward(struct node* tail)
{
    while(tail!=NULL)
    {
        printf("%d ",tail->data);
        tail=tail->prev;
    }
    printf("\n");
}

struct node* insertatbeginning(struct node* head,int data)
{
    struct node* newnode=createnode(data);
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        return newnode;
    }
}

struct node* insertatend(struct node* tail,int data)
{
    struct node* newnode=createnode(data);
    if(tail==NULL)
    {
        return newnode;
    }
    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        return newnode;
    }
}

struct node* deleteatbeginning(struct node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node* temp=head;
        head= head->next;
        free(temp);
        return head;
    }
}
int main()
{
    struct node* head=NULL;
    struct node* tail=NULL;
    
    //creating nodes
    struct node* n1=createnode(1);
    struct node* n2=createnode(3);
    struct node* n3=createnode(5);
    struct node* n4=createnode(7);

    //linking nodes
    n1->next=n2;
    n2->prev=n1;
    n2->next=n3;
    n3->prev=n2;
    n3->next=n4;
    n4->prev=n3;

     //attaching head and tail
     head=n1;
     tail=n4;

    //traverse
    printforward(head);
    printbackward(tail);
    
    //insertion at beginning 
    head=insertatbeginning(head,15);
    printforward(head);
    //insertion at end
    tail=insertatend(tail,20);
    printforward(head);
    
    //deletion at beginning
    head=deleteatbeginning(head);
    printforward(head);
    return 0;
}