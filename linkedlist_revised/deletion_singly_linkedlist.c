//deletion in singly linked list
#include<stdio.h>
#include<stdlib.h>
//linked list implementation
struct node{
    int data;
    struct node* next;
};

void traverse(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

//deletion at first node
struct node* deleteatfirst(struct node* head)
{
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
//deletion at given index
struct node* deleteatindex(struct node* head, int index)
{
    struct node* p=head;
    struct node* q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node* deleteatlast(struct node* head)
{
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node* deleteatvalue(struct node* head,int value)
{
    struct node* p=head;
    struct node* q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}

int main()
{
    //initializing nodes
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    struct node* forth=NULL;
    struct node* fifth=NULL;
    struct node* sixth=NULL;

    //allocating memory 
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));
    fifth=(struct node*)malloc(sizeof(struct node));
    sixth=(struct node*)malloc(sizeof(struct node));

    //linking nodes and giving data
    head->data=5;
    head->next=second;

    second->data=6;
    second->next=third;

    third->data=7;
    third->next=forth;

    forth->data=8;
    forth->next=fifth;

    fifth->data=9;
    fifth->next=sixth;

    sixth->data=10;
    sixth->next=NULL;

    //display before deletion
    traverse(head);
    //deletion of first node
    head=deleteatfirst(head);
    traverse(head);
    //deletion at index
    head=deleteatindex(head,2);
    traverse(head);
    //delete the last node
    head=deleteatlast(head);
    traverse(head);
    //delete at given value
    head=deleteatvalue(head,7);
    traverse(head);
    return 0;
}