//checking if binary tree is a BST
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int x)
{
    struct node* s;
    s=(struct node*)malloc(sizeof(struct node));
    s->data=x;
    s->left=NULL;
    s->right=NULL;
    return s;
}

void inorder(struct node* p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

int isbst(struct node* root)
{
     static struct node* prev=NULL;
    if(root!=NULL)
    {
       if(!isbst(root->left))
       return 0;
       if(prev!=NULL && root->data <= prev->data)
       return 0;
       prev=root;
       return isbst(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct node* p=create(9);
    struct node* p1=create(4);
    struct node* p2=create(11);
    struct node* p3=create(2);
    struct node* p4=create(7);
    struct node* p5=create(15);

    //linking nodes
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=NULL;
    p2->right=p5;
    
    //calling functions
    inorder(p);
    printf("\n");
    if(isbst(p))
    {
        printf("this is BST");
    }
    else
    {
        printf("not a BST");
    }
  
    return 0;
}