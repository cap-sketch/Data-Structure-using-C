//let us study trees
//tress are nonlinear heirarchial data structures
//let us write a c program to demonstate linked trees
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int x)
{
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

//traversal 
void preorder(struct node*p)
{
    if(p!=NULL)
    {
          printf("%d ",p->data);
          preorder(p->left);
          preorder(p->right);
    }

}

void postorder(struct node*p)
{
    if(p!=NULL)
    {
       
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
    
}

void inorder(struct node*p)
{
    if(p!=NULL)
    {
       
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
        
    }
    
}

int main()
{
    struct node* p=create(1);
    struct node* p1=create(2);
    struct node* p2=create(3);
    struct node* p3=create(4);
    struct node* p4=create(5);
    struct node* p5=create(6);
    struct node* p6=create(7);

    //rough idea
        //        p
        //      /  \
        //     p1   p2
        //    / \   / \
        //  p3  p4 p5  p6

     //linking with each other
     p->left=p1;
     p->right=p2;
     p1->left=p3;
     p1->right=p4;
     p2->left=p5;
     p2->right=p6;
 
     preorder(p);
     printf("\n");
     postorder(p);
     printf("\n");
     inorder(p);
     return 0;
}