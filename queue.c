    #include<stdio.h>   
    #include<stdlib.h>  
    #define maxsize 100
    struct node   
{  
    int data;   
    struct node *next;  
};    

    void insert_array();  
    void delete_array();  
    void disp_queue();  
    int front=-1,rear=-1;  
    int queue[maxsize];  
    struct node *fronts;  
struct node *rears;   
void insert_link();  
void delete_link();  
void disp_link();
void insert_circ(int data)  
    {  
        if(front==-1 && rear==-1)  
        {  
            front=0;  
            rear=0;  
            queue[rear]=data;  
        }  
        else if((rear+1)%maxsize==front)   
        {  
            printf("\nOverflow\n");  
        }  
        else  
        {  
            rear=(rear+1)%maxsize;       
            queue[rear]=data;     
        }  
    }    
    int delete_circ()  
    {  
        if((front==-1) && (rear==-1))  
        {  
            printf("\nUnderflow\n");  
        }  
     else if(front==rear)  
    {  
       printf("\nThe deleted element is %d", queue[front]);  
       front=-1;  
       rear=-1;  
    }   
    else  
    {  
        printf("\nThe deleted element is %d", queue[front]);  
       front=(front+1)%maxsize;  
    }  
    }  
    void disp_circ()  
    {  
        int i=front;  
        if(front==-1 && rear==-1)  
        {  
            printf("\n Queue is empty\n");  
        }  
        else  
        {  
            printf("\nElements in a Queue are:\n");  
            while(i<=rear)  
            {  
                printf("%d\n", queue[i]);  
                i=(i+1)%maxsize;  
            }  
        }  
    }  
int main()  
    {  
        int choice,x;   
        while(choice!=7)   
        {     
            printf("1. Insert an element in the Queue using array\n");  
            printf("2. Delete an element from the Queue using array\n");
            printf("3. Display the queue\n");
            printf("4. Insert an element in the Queue using linked list\n");  
            printf("5. Delete an element from the Queue using linked list\n");
            printf("6. Display the queue\n");
            printf("7. Insert an element in the circular Queue using array\n");
            printf("8. Delete an element in the circular Queue using array\n");
            printf("9. Display the queue\n");
            printf("10. Exit\n");
            printf("\nEnter your choice: \n");  
            scanf("%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                    insert_array();  
                break;  
                case 2:  
                    delete_array();  
                break;  
                case 3:  
                    disp_queue();  
                break;  
                
                case 4:insert_link();  
                    break;  
                case 5:delete_link();  
                    break;  
                case 6:disp_link();  
                    break;  
                case 7:  printf("Enter the element which is to be inserted\n");  
                         scanf("%d", &x);    
                    insert_circ(x);  
                    break;  
                case 8: delete_circ();  
                    break;  
                case 9: disp_circ();
                    break;  
                case 10:exit(0);  
                    break;  
                default:   
                     printf("\nERROR\n");  
            }  
        }  
        return 0;
        }  
void insert_array()  
    {  
        int data;  
        printf("Enter the element\n");  
        scanf("\n%d",&data);      
        if(rear==maxsize-1)  
        {  
            printf("\nOVERFLOW\n");  
            return;  
        }  
        if(front==-1 && rear==-1)  
        {  
            front=0;  
            rear=0;  
        }  
        else   
        {  
            rear=rear+1;  
        }  
        queue[rear]=data;  
        printf("\nValue inserted\n ");  
          
    }  
    void delete_array()  
    {  
        int data;   
        if (front==-1 || front>rear)  
        {  
            printf("\nUNDERFLOW\n");  
            return;  
                  
        }  
        else  
        {  
            data=queue[front];  
            if(front==rear)  
            {  
                front=-1;  
                rear=-1 ;  
            }  
            else   
            {  
                front=front + 1;  
            }  
            printf("\nvalue deleted\n ");  
        }  
    }  
          
    void disp_queue()  
    {  
        int i;  
        if(rear==-1)  
        {  
            printf("\nEmpty queue\n");  
        }  
        else  
        {   printf("\nprinting values .....\n");  
            for(i=front;i<=rear;i++)  
            {  
                printf("\n%d\n",queue[i]);  
            }     
        }  
    }  
void insert_link()  
{  
    struct node *ptr;  
    int data;   
    ptr=(struct node *)malloc(sizeof(struct node));  
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
        if(fronts==NULL)  
        {  
            fronts=ptr;  
            rears=ptr;   
            fronts->next=NULL;  
            rears->next=NULL;  
        }  
        else   
        {  
            rears->next=ptr;  
            rears=ptr;  
            rears->next=NULL;  
        }  
    }  
}     
void delete_link ()  
{  
    struct node *ptr;  
    if(fronts==NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr=fronts;  
        fronts=fronts->next;  
        free(ptr);  
    }  
}  
void disp_link()  
{  
    struct node *ptr;  
    ptr=fronts;      
    if(fronts==NULL)  
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
