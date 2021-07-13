#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void insert_link();  
void delete_link();  
void disp_link();  
void main ()  
{  
    int choicess;   
    while(choicess!=4)   
    {     
        printf("1. Insert an element in the Queue\n");  
        printf("2. Delete an element from the Queue\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");  
        scanf("%d",&choicess);  
        switch(choicess)  
        {  
            case 1:insert_link();  
                    break;  
            case 2:delete_link();  
                    break;  
            case 3:disp_link();  
                    break;  
            case 4:exit(0);  
                    break;  
            default:   
            printf("\nERROR\n");  
        }  
    }  
}  
void insert_link()  
{  
    struct node *ptr;  
    int data;   
    ptr=(struct node *) malloc (sizeof(struct node));  
    if(ptr==NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter the element: ");  
        scanf("%d",&data);  
        ptr->data=data;  
        if(front==NULL)  
        {  
            front=ptr;  
            rear=ptr;   
            front->next=NULL;  
            rear->next=NULL;  
        }  
        else   
        {  
            rear->next=ptr;  
            rear=ptr;  
            rear->next=NULL;  
        }  
    }  
}     
void delete_link ()  
{  
    struct node *ptr;  
    if(front==NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr=front;  
        front=front->next;  
        free(ptr);  
    }  
}  
void disp_link()  
{  
    struct node *ptr;  
    ptr=front;      
    if(front==NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("The elements in the queue are: ");  
        while(ptr!=NULL)   
        {  
            printf("%d\n",ptr->data);  
            ptr=ptr->next;  
        }  
    }  
} 
