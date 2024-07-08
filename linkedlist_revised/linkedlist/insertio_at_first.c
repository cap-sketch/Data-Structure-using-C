//linked list insertion at first
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* insertionatfirst(struct node* head,int val)
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=head;
    return ptr;

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
    head= insertionatfirst(head,1);
    printf("\n");
    traversal(head);


    return 0;

}