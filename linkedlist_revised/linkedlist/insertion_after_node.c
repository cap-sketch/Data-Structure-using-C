//linked list insertion a node
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* insertionafternode(struct node* head,int val,struct node* prevnode)   //no need to tranverse
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
     ptr->next=prevnode->next;
     ptr->data=val;
     prevnode->next=ptr;
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
    head= insertionafternode(head,1,second);
    printf("\n");
    traversal(head);


    return 0;

}