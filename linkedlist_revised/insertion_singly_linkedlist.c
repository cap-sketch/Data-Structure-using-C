//linked list
#include<stdio.h>
#include<stdlib.h>
//implementation of linked list
struct node{
    int data;
    struct node* next;
};

void traversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node* insertionatfirst(struct node* head,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct node* insertionatindex(struct node* head,int index,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;    
    return ptr;
}

struct node* insertionatend(struct node* head,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertionafternode(struct node* head,struct node* prev,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prev->next;
    prev->next=ptr;
    return head;
}


int main()
{
    //initialising nodes
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    struct node* forth=NULL;
    struct node* fifth=NULL;
    //allocating memory dynamically
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));
    fifth=(struct node*)malloc(sizeof(struct node));
    //linking and giving data
    head->data=5;
    head->next=second;

    second->data=6;
    second->next=third;

    third->data=7;
    third->next=forth;

    forth->data=8;
    forth->next=fifth;

    fifth->data=9;
    fifth->next=NULL;
     
    traversal(head); 
    //insertion
    head=insertionatfirst(head,4);
    traversal(head);

    head=insertionatend(head,22);
    traversal(head);

    head=insertionatindex(head,2,15);
    traversal(head);

    head=insertionafternode(head,third,25);
    traversal(head);

    return 0;
}
