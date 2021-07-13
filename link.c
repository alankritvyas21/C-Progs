#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          
    struct node *next; 
}*head;
void create_singly(int n);
void insert_beglink(int data);
void insert_endlink(int data);
void insert_anywherelink(int data,int position);
void delete_beglink(int data);
void delete_endlinklink(int data);
void delete_anywherelink(int position); 
void displayListlink();
int main()
{
    int n,data,choice,position;
    printf("Enter the total number of nodes in the singly linked list: ");
    scanf("%d",&n);
    create_singly(n);
    printf("\nData in the list \n");
    displayListlink();
    printf("Which opertaion do you want to perform in the singly linked list: ");
    printf("\n1. Insert node at beginning of the list");
    printf("\n2. Insert node at end of the list");
    printf("\n3. Insert node at desired position of the list");
    printf("\n4. Delete node at beginning of the list");
    printf("\n5. Delete node at end of the list");
    printf("\n6. Delete node at desired position of the list\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("\nEnter data to insert at beginning of the list: ");
            scanf("%d", &data);
            insert_beglink(data);
            printf("\nData in the list \n");
            displayListlink();
            break;

    case 2:printf("\nEnter data to insert at end of the list: ");
            scanf("%d", &data);
            insert_endlink(data);
            printf("\nData in the list \n");
            displayListlink();
                break;

    case 3:printf("\nEnter data to insert at the desired position of the list: ");
            scanf("%d", &data);
            printf("Enter the position where you want to insert the data: ");
            scanf("%d",&position);
            insert_anywherelink(data,position);
            printf("\nData in the list \n");
            displayListlink();
                break;
    
    case 4:
            delete_beglink(data);
            printf("\nData in the list \n");
            displayListlink();
                break;

    case 5:
            delete_endlinklink(data);
            printf("\nData in the list \n");
            displayListlink();
                break;
                
    case 6:
            printf("Enter the position where you want to delete the data: ");
            
            delete_anywherelink(position);
            printf("\nData in the list \n");
            displayListlink();
                break;


    
    default:
    printf("error");
        break;
    }
   return 0;
}
void create_singly(int n)
{
    struct node *newNode,*temp;
    int data,i;
    head=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    if(head==NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        
        scanf("%d",&data);
        head->data=data; 
        head->next=NULL; 
        temp = head;
        for(i=2;i<=n;i++)
        {
            newNode=(struct node *)malloc(sizeof(struct node));
            if(newNode==NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                
                scanf("%d", &data);
                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode; 
                temp = temp->next; 
            }
        }
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insert_beglink(int data)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data=data; 
        newNode->next=head; 
        head=newNode;          
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void displayListlink()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data); 
            temp=temp->next;                 
        }
    }
}
void insert_endlink(int data)
{
    struct node *newNode,*temp;

    newNode=(struct node*)malloc(sizeof(struct node));

    if(newNode==NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data=data; 
        newNode->next=NULL; 
        temp=head;
        while(temp!=NULL && temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode; 
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void insert_anywherelink(int data,int position)
    {
    	struct node *ptr=(struct node*)malloc(sizeof(struct node));
    	ptr->data=data;		
    	int i;
    	struct node *temp=head;
    	if(position==1)
        {
        	ptr->next=temp;
    		head=ptr;
    		return;
    	}
        for(i=1;i<position-1;i++)  
    	{
        	temp=temp->next;
    	}
        ptr->next=temp->next; 
    	temp->next=ptr;  	
             printf("DATA INSERTED SUCCESSFULLY\n");

}
void delete_beglink(int data)
{
    struct node *toDelete;

    if(head==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete=head;
        head=head->next;
        printf("\nData deleted=%d\n",toDelete->data);
        free(toDelete);
        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void delete_endlinklink(int data)
{
    struct node *toDelete,*secondLastNode;

    if(head==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete=head;
        secondLastNode=head;
        while(toDelete->next!=NULL)
        {
            secondLastNode=toDelete;
            toDelete=toDelete->next;
        }
        if(toDelete==head)
        {
            head=NULL;
        }
        else
        {
            secondLastNode->next=NULL;
        }
        printf("\nData deleted=%d\n",toDelete->data);
        free(toDelete);
        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
void delete_anywherelink(int position)  
    {  
        struct node *ptr, *ptr1;  
        int i;   
        scanf("%d",&position);  
        ptr=head;  
        for(i=1;i<position;i++)  
        {  
            ptr1=ptr;       
            ptr=ptr->next;  
              
            if(ptr==NULL)  
            {  
                printf("\nThere are less than %d elements in the list..\n",position);  
                return;  
            }  
        }  
        ptr1 ->next = ptr ->next;  
        printf("\nData deleted=%d\n",position); 
        free(ptr);  
         printf("SUCCESSFULLY DELETED NODE OF LIST\n");
         
    }     
