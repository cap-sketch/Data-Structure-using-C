//postorder traversal in  binary tree
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

void postorder(struct node* p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
int main()
{
    struct node* p=createnode(4);
    struct node* p1=createnode(5);
    struct node* p2=createnode(6);
    struct node* p3=createnode(7);
    struct node* p4=createnode(8);
    struct node* p5=createnode(9);
            //     4
            //    / \
            //   5   6
            //  /\    \
            // 7  8    9 
    //linking the nodes
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;
    postorder(p);
    return 0;
}