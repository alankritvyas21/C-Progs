    #include<stdio.h>   
    #include<stdlib.h>  
    #define maxsize 5  
    void insert_array();  
    void delete_array();  
    void disp_queue();  
    int front=-1,rear=-1;  
    int queue[maxsize];  
    void main()  
    {  
        int choice;   
        while(choice!=4)   
        {     
            printf("1. Insert an element in the Queue\n");  
            printf("2. Delete an element from the Queue\n");
            printf("3. Display the queue\n");
            printf("4. Exit\n");
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
                case 4:  
                         exit(0);  
                break;  
                default:   
                     printf("\nERROR\n");  
            }  
        }  
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