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
    return 0;
}