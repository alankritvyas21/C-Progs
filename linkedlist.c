#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int num;                       
    struct node *nextptr;           
}*stnode;

void createNodeList(int n); 
void displayList();         

int main()
{
    int n;
	printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\nNodes entered are: \n");
    displayList();
    return 0;
}
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) 
    {
        printf("Memory can not be allocated.");
    }
    else
    {
    printf("Node 1 : ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->nextptr = NULL; 
        tmp = stnode;
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf("Memory can not be allocated.");
                break;
            }
            else
            {
                printf("Node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      
                fnNode->nextptr = NULL; 
                tmp->nextptr = fnNode; 
                tmp = tmp->nextptr; 
            }
        }
    }
}
void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf("%d\n", tmp->num);      
            tmp = tmp->nextptr;                    
        }
    }
} 
