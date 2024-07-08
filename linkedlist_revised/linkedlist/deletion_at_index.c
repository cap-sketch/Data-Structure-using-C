//deletion of node in between using index
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};               //self referencing structure

struct node* deletionatindex(struct node* head,int index)
{
     struct node*ptr=head;
     int i=0;
     while(i!=index-1)
     {
        ptr=ptr->next;
        i++;
     }
     struct node *q=ptr->next;
     ptr->next=q->next;
     free(q);
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
     head=deletionatindex(head,2);
     traversal(head);

}