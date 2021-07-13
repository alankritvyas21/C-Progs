#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    struct node *preptr;
    struct node *nextptr;
}*stnode,*ennode;
 void create_doubly(int data);
 void insert_begdoub(int data);
 void insert_enddoub(int data);
 void insert_anywheredoub(int data, int position);
 void delete_begdoub(int data);
 void delete_enddoub(int data);
 void delete_anywheredoub(int position);
void displayListdoub();

int main()
{
    int n,data,choice=1,position;
    stnode=NULL;
    ennode=NULL;
	printf("\n\nEnter the total number of nodes in the circulr linked list: ");
    scanf("%d",&n);
    create_doubly(n);
    printf("Which opertaion do you want to perform in the doubly linked list: ");
    printf("\n1. Insert node at beginning of the list");
    printf("\n2. Insert node at end of the list");
    printf("\n3. Insert node at desired position of the list");
    printf("\n4. Delete node at beginning of the list");
    printf("\n5. Delete node at end of the list");
    printf("\n6. Delete node at desired position of the list\n");
     scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("\nEnter data to insert at beginning of the list: ");
            scanf("%d", &data);
            insert_begdoub(data);
            displayListdoub();
            break;

    case 2:printf("\nEnter data to insert at end of the list: ");
            scanf("%d", &data);
            insert_enddoub(data);
            displayListdoub();
            break;


    case 3: printf("\nEnter data to insert at the desired position of the list: ");
            scanf("%d", &data);
            printf("Enter the position where you want to insert the data: ");
            scanf("%d",&position);
            insert_anywheredoub(data,position);
            printf("\nData in the list \n");
            displayListdoub();
            break;

    
    case 4: delete_begdoub(data);
            displayListdoub();
            break;


    case 5: delete_enddoub(data);
            displayListdoub();
            break;

                
    case 6:delete_anywheredoub(position);
            displayListdoub();
            break;

                
    default:
    printf("error");
        break;
    }
    return 0;
}
void create_doubly(int n)
{
    int i,num;
    struct node *fnNode;
 
    if(n>=1)
    {
        stnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        if(stnode!=NULL)
        { 
            scanf("%d",&num);
            stnode->num=num;
            stnode->preptr=NULL;
            stnode->nextptr=NULL;
            ennode = stnode;
            for(i=2;i<=n;i++)
            {
                fnNode=(struct node *)malloc(sizeof(struct node));
                if(fnNode!=NULL)
                {
                    scanf("%d",&num);
                    fnNode->num=num;
                    fnNode->preptr=ennode;   
                    fnNode->nextptr=NULL;
                    ennode->nextptr = fnNode;   
                    ennode=fnNode;            
                }
                else
                {
                    printf("Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf("Memory can not be allocated.");
        }
    }
}
void displayListdoub()
{
    struct node *tmp;
    int n=1;
    if(stnode==NULL)
    {
        printf("No data found in the List yet.");
    }
    else
    {
        tmp=stnode;
        printf("\nData entered on the list are :\n");
 
        while(tmp!=NULL)
        {
            printf("node %d:%d\n",n,tmp->num);
            n++;
            tmp=tmp->nextptr; 
        }
    }
}
void insert_begdoub(int data)  
{ 
   
   struct node *ptr=(struct node *)malloc(sizeof(struct node));  
   if(ptr==NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {        
   if(stnode==NULL)  
   {  
       ptr->nextptr=NULL;  
       ptr->preptr=NULL;  
       ptr->num=data;  
       stnode=ptr;  
   }  
   else   
   {  
       ptr->num=data;  
       ptr->preptr=NULL;  
       ptr->nextptr=stnode;  
       stnode->preptr=ptr;  
       stnode=ptr;  
   }  
}  
     printf("\nNODE INSERTED\n");
}  
void insert_enddoub(int data)  
{  
   struct node *ptr=(struct node *) malloc(sizeof(struct node));  
   struct node *temp;  
   if(ptr==NULL)  
   {  
       printf("\nOVERFLOW");  
          
   }  
   else  
   {  
        ptr->num=data;  
       if(stnode==NULL)  
       {  
           ptr->nextptr=NULL;  
           ptr->preptr=NULL;  
           stnode=ptr;  
       }  
       else  
       {  
          temp=stnode;  
          while(temp->nextptr!=NULL)  
          {  
              temp=temp->nextptr;  
          }  
          temp->nextptr=ptr;  
          ptr ->preptr=temp;  
          ptr->nextptr=NULL;  
       }  
printf("\nNODE INSERTED\n");        
   }  
}  
void insert_anywheredoub(int data,int position)
{
    int i;
    struct node *newnode,*tmp;
    if(ennode==NULL)
    {
        printf("No data found in the list!\n");
    }
    else
    {
        tmp=stnode;
        i=1;
        while(i<position-1 && tmp!=NULL)
        {
            tmp=tmp->nextptr;
            i++;
        }
        if(position==1)
        {
            insert_begdoub(data);
        }
        else if(tmp==ennode)
        {
            insert_enddoub(data);
        }
        else if(tmp!=NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->num=data;           
            newnode->nextptr=tmp->nextptr;            
            newnode->preptr=tmp;              
            if(tmp->nextptr!=NULL)
            {
                tmp->nextptr->preptr=newnode; 
            }
            tmp->nextptr=newnode; 
        }
        else
        {
            printf("The position you entered, is invalid.\n");
        }
    }
    printf("\nNODE INSERTED\n");  
} 
void delete_begdoub(int data)  
{  
    struct node *ptr;  
    if(stnode==NULL)  
    {  
        printf("\n UNDERFLOW\n");  
    }  
    else if(stnode->nextptr==NULL)  
    {  
        stnode=NULL;   
        free(stnode);  
        printf("\nNODE DELETED\n");  
    }  
    else  
    {  
        ptr=stnode;  
        stnode=stnode->nextptr;  
        stnode->preptr=NULL;  
        free(ptr);  
        printf("\nNODE DELETED\n");  
    }  
}  
void delete_enddoub(int data)
{
    struct node *NodeToDel;
 
    if(ennode==NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel=ennode;
        ennode=ennode->preptr;    
        ennode->nextptr=NULL;     
        free(NodeToDel);
        printf("\nNODE DELETED\n");            
    }
}
void delete_anywheredoub(int position)
{
    struct node *curNode;
    int i,data;
     printf("\n Enter the position to be deleted:");  
        scanf("%d",&position); 
    curNode=stnode;
    for(i=1;i<position && curNode!=NULL;i++)
    {
        curNode=curNode->nextptr;
    }
 
    if(position==1)
    {
        delete_begdoub(data);
    }
    else if(curNode==ennode)
    {
        delete_enddoub(data);
    }
    else if(curNode!=NULL)
    {
        curNode->preptr->nextptr=curNode->nextptr;
        curNode->nextptr->preptr=curNode->preptr;
        free(curNode); 
        printf("\nNODE DELETED\n");
    }
    else
    {
        printf("The given position is invalid!\n");
    }
} 