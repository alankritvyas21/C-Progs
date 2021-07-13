#include<stdio.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void tree_create(struct node *);
struct node *insert_element(struct node *,int);
int main()
{
    tree_create();
    printf("Tree is created");
    return 0;
}
void tree_create(struct node *tree)
{
    tree=NULL;
}
struct node *insert_element(struct node *tree, int val)
{
    struct node *ptr,*nodeptr,*parentptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    if(tree==NULL)
    {
        tree=ptr;
    }
}
