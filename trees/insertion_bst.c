//insertion in BST
        //      8
        //     / \
        //    3   10
        //   / \   / \
        //  1  6  9   14
        //    / \    /
        //   4   7  13
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int key)
{
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->data=key;
    x->left=NULL;
    x->right=NULL;
    return x;
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

void insert(struct node* root,int key)
{
    struct node* prev=NULL;
    while(root!=NULL)
    {
         prev=root;
         if(key==root->data)
         {
            printf("insertion failed");
         return;
         }
         else if(key<(root->data))
         {
         root=root->left;
         }
         else
         {
            root=root->right;
         }
    }
    struct node* new_node = createnode(key);

    // Insert the new node at the appropriate position
    if (prev == NULL) {
        // If the tree is empty
        root = new_node;
    } else if (key < prev->data) {
        prev->left = new_node;
    } else {
        prev->right = new_node;
    }

}
int main()
{
    //creating a node function
    struct node* p=createnode(8);
    struct node* p1=createnode(3);
    struct node* p2=createnode(10);
    struct node* p3=createnode(1);
    struct node* p4=createnode(6);
    struct node* p5=createnode(14);
    struct node* p6=createnode(4);
    struct node* p7=createnode(7);
    struct node* p8=createnode(13);

    //linking the nodes
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=NULL;
    p2->right=p5;
    p4->left=p6;
    p4->right=p7;
    p5->left=p8;


    //Traversal
    inorder(p);

    //insertion
    insert(p,9);
    insert(p,17);

    //traversal
    printf("\n");
    inorder(p);

    return 0;
}