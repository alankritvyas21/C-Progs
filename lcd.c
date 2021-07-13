#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          
    struct node *next; 
    int num;
    struct node *preptr;
    struct node *nextptr;
}*head,*stnode,*ennode;
void create_singly(int n);
void insert_beglink(int data);
void insert_endlink(int data);
void insert_anywherelink(int data,int position);
void delete_beglink(int data);
void delete_endlinklink(int data);
void delete_anywherelink(int position); 
void displayListlink();
void create_circular(int n);
void insert_begcirc(int data);
void insert_endcirc(int data);
void insert_anywherecirc(int data,int position);
void delete_begcirc(int data);
void delete_endcirc(int data);
void delete_anywherecirc(int position); 
void displayListcirc();
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
    int n,nc,data,choice,position;
    head=NULL;
    stnode=NULL;
    ennode=NULL;
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
    printf("\n\nEnter the total number of nodes in the circulr linked list: ");
    scanf("%d",&nc);
    create_circular(nc);
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
printf("\n\nEnter the total number of nodes in the doubly linked list: ");
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