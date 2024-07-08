//linked list insertion at index
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* insertionatindex(struct node* head,int val,int index)
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=val;
    ptr->next=p->next;
    p->next=ptr;
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
    head= insertionatindex(head,1,2);
    printf("\n");
    traversal(head);


    return 0;

}