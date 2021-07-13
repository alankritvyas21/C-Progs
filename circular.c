#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
}*head;
void create_circular(int n);
void insert_begcirc(int data);
void insert_endcirc(int data);
void insert_anywherecirc(int data,int position);
void delete_begcirc(int data);
void delete_endcirc(int data);
void delete_anywherecirc(int position); 
void displayListcirc();
int main()
{
    int n,data,choice=1,position;
    head=NULL;
    printf("\n\nEnter the total number of nodes in the circulr linked list: ");
    scanf("%d",&n);
    create_circular(n);
    printf("Which opertaion do you want to perform in the circular linked list: ");
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
            insert_begcirc(data);
            displayListcirc();
            break;

    case 2:printf("\nEnter data to insert at end of the list: ");
            scanf("%d", &data);
            insert_endcirc(data);
            displayListcirc();
            break;


    case 3: insert_anywherecirc(data,position);
            printf("\nData in the list \n");
            displayListcirc();
            break;

    
    case 4:delete_begcirc(data);
            displayListcirc();
            break;


    case 5:delete_endcirc(data);
            displayListcirc();
            break;

                
    case 6:delete_anywherecirc(position);
            displayListcirc();
            break;

                
    default:
    printf("error");
        break;
    }
    return 0;

}

void create_circular(int n)
{
    int i,data;
    struct node *prevNode,*newNode;
    printf("Enter data: ");
     if(n>=1)
    {
        head=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        prevNode = head;
        for(i=2;i<=n;i++)
        {
            newNode=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&data);
            newNode->data = data;
            newNode->next = NULL;
            prevNode->next = newNode;
            prevNode = newNode;
        }
        prevNode->next = head;
        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void displayListcirc()
{
    struct node *current;
    int n=1;
    if(head==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current=head;
        printf("DATA IN THE LIST:\n");
        do {
            printf("Data %d = %d\n",n,current->data);
            current=current->next;
            n++;
        }while(current!=head);
    }
    
}
void insert_begcirc(int data)    
{    
        
    struct node *ptr=(struct node *)malloc(sizeof(struct node));    
    struct node *temp;  
    if(ptr==NULL)    
    {    
        printf("\nOVERFLOW");    
    }    
    else     
    {    
        ptr->data=data;    
        if(head==NULL)    
        {    
            head=ptr;    
            ptr->next=head;    
        }    
        else     
        {       
            temp=head;    
            while(temp->next!=head)    
                temp=temp->next;    
            ptr->next=head;     
            temp->next=ptr;     
            head=ptr;    
        }     
    printf("\nDATA INSERTED SUCCESSFULLY\n");  
    }    
                
}    
void insert_endcirc( int data)  
    {  
        struct node*ptr;
        struct node *temp;
        ptr=(struct node *)malloc(sizeof(struct node));  
        if(ptr==NULL)  
        {  
            printf("\nOVERFLOW\n");  
        }  
        else  
        {  
            ptr->data=data;  
            if(head==NULL)  
            {  
                head=ptr;  
                ptr->next=head;    
            }  
            else  
            {  
                temp=head;  
                while(temp->next!=head)  
                {  
                    temp=temp->next;  
                }  
                temp->next=ptr;   
                ptr->next=head;  
            }  
        }  
      printf("\nDATA INSERTED SUCCESSFULLY\n"); 
    }  
void insert_anywherecirc(int data,int position)  
{  
    struct node *ptr,*x,*y,*z;  
    int c=1,count=1;  
    y=(struct node*)malloc(sizeof(struct node));  
    if(head==NULL)  
    {  
        printf("cannot enter an element at this place");  
    }  
    printf("\nEnter data to insert at the desired position of the list:");  
    scanf("%d",&y->data);  
    printf("\nEnter the position where you want to insert the data: ");  
    scanf("%d",&position);  
    x=head;  
    ptr=head;  
    while(ptr->next!=head)  
    {  
        count++;  
        ptr=ptr->next;  
    }  
    count++;  
    if (position>count)  
    {  
        printf("Not in list");  
        return;  
    }  
    while (c<position)  
    {  
        z=x;  
        x=x->next;  
        c++;  
    }  
    y->next=x;  
    z->next=y;  
}  
void delete_begcirc(int data)  
{  
    struct node *ptr;  
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW\n");      
    }  
    else if(head->next==head)  
    {  
        head=NULL;  
        free(head);  
        printf("\nNODE DELETED\n");   
    }  
    else  
    {     
        ptr=head;   
        while(ptr->next!=head)  
            ptr=ptr->next;   
        ptr->next=head->next;  
        free(head);  
        head=ptr->next;  
        printf("\nNODE DELETED\n");   
    }  
}  
void delete_endcirc(int data)  
{  
struct node *ptr,*preptr;    
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW\n");  
    }  
    else if(head->next==head)  
    {  
        head=NULL;  
        free(head);  
        printf("\nNODE DELETED\n");  
    }  
    else   
    {  
        ptr=head;  
        while(ptr->next!=head)  
        {  
            preptr=ptr;  
            ptr=ptr->next;  
        }  
        preptr->next=ptr->next;  
        free(ptr);  
        printf("\nNODE DELETED\n");  
    }  
}  
void delete_anywherecirc(int position)  
{  
    if (head==NULL)  
        printf("\n List is empty");  
    else  
    {  
        int c=1;  
        struct node *x,*y,*z;
        printf("\n Enter the position to be deleted:");  
        scanf("%d",&position);  
        x=head;  
        while(c<position)  
        {  
            y=x;  
            x=x->next;  
            c++;  
        }  
        y->next=x->next;  
        free(x);  
        printf("\nNODE DELETED\n"); 
    }  
}  