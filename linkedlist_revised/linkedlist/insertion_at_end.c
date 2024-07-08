//linked list insertion at end
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* insertionatend(struct node* head,int val)
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->data=val;
    ptr->next=NULL;
    return head;
}

void traversal(struct node* ptr)
{ 
    while(ptr!=NULL)
    {
    printf("%d ",ptr->data);
    ptr=ptr->next;
    }
}

int main()
 {    //allocating memory for linked list
    struct node*head;
    head=(struct node*)malloc(sizeof(struct node));
    struct node*second;
    second=(struct node*)malloc (sizeof(struct node));
    struct node*third;
    third=(struct node*)malloc(sizeof(struct node));
    struct node*forth;
    forth=(struct node*)malloc (sizeof(struct node));
    //linking them to each other
    head->data=2;
    head->next=second;
    second->data=3;
    second->next=third;
    third->data=4;
    third->next=forth;
    forth->data=5;
    forth->next=NULL;
    traversal(head);
    //insertion at head
    head= insertionatend(head,1);
    printf("\n");
    traversal(head);


    return 0;

}