//linked binary tree
#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int x)
{
    struct node* a;
    a=(struct node*)malloc(sizeof(struct node));
    a->data=x;
    a->left=NULL;
    a->right=NULL;
    return a;
}
int main()
{
    struct node* p=createnode(4);
    struct node* p1=createnode(5);
    struct node* p2=createnode(6);
    //linking the nodes
    p->left=p1;
    p->right=p2;
    return 0;
}