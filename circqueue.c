    #include<stdio.h> 
    #include<stdlib.h> 
    # define max 10  
    int queue[max];  
    int front=-1;  
    int rear=-1;  
    void insert_circ(int element)  
    {  
        if(front==-1 && rear==-1)  
        {  
            front=0;  
            rear=0;  
            queue[rear]=element;  
        }  
        else if((rear+1)%max==front)   
        {  
            printf("\nOverflow\n");  
        }  
        else  
        {  
            rear=(rear+1)%max;       
            queue[rear]=element;     
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
       front=(front+1)%max;  
    }  
    }  
    void disp_circ()  
    {  
        int i=front;  
        if(front==-1 && rear==-1)  
        {  
            printf("\n Queue is empty");  
        }  
        else  
        {  
            printf("\nElements in a Queue are:");  
            while(i<=rear)  
            {  
                printf("%d\n", queue[i]);  
                i=(i+1)%max;  
            }  
        }  
    }  
    int main()  
    {  
        int choice=1,x;   
        while(choice<4 && choice!=0)   
        {  
        printf("\n1: Insert an element");  
        printf("\n2: Delete an element");  
        printf("\n3: Display the element");
        printf("\n4. Exit\n");  
        printf("\nEnter your choice\n");  
        scanf("%d", &choice);  
          
        switch(choice)  
        {  
              
            case 1: printf("Enter the element which is to be inserted\n");  
                    scanf("%d", &x);  
                    insert_circ(x);  
                    break;  
            case 2: delete_circ();  
                    break;  
            case 3: disp_circ();
                    break;  
            case 4: exit(0);  
                    break;
                    default:
                    printf("ERROR");
        }
        }  
        return 0;  
    }  