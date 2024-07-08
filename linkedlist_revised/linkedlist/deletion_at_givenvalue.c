//deletion of at given value
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};               //self referencing structure

struct node* deletionatvalue(struct node* head,int value)
{
     struct node*ptr=head;
     struct node*q=ptr->next;
     while( q->next!=NULL && q->data!=value )
     {
        ptr=ptr->next;
        q=q->next;
     }
     if(q->data==value)
     {
     ptr->next=q->next;
     free(q);
     }
     return head;
}

void traversal(struct node*head)
{
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct node*head;
    head=(struct node*)malloc (sizeof(struct node));
    struct node*second;
    second=(struct node*)malloc (sizeof(struct node));
    struct node*third;
    third=(struct node*)malloc (sizeof(struct node));
    struct node*forth;
    forth=(struct node*)malloc (sizeof(struct node));
     
     head->data=2;
     head->next=second;
     second->data=3;
     second->next=third;
     third->data=4;
     third->next=forth;
     forth->data=5;
     forth->next=NULL;

     traversal(head);
     printf("\n");
     head=deletionatvalue(head,4);
     traversal(head);

}