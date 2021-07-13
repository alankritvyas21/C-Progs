/*Code by Alankrit Vyas Regis no: 199303131
SET 1*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char usn[25],name[25],branch[25];
    int sem;
    long int phone;
    struct node *link;
};
typedef struct node * NODE;
NODE start=NULL;
int count=0;
NODE create()
{
    NODE nodes;
    nodes=(NODE)malloc(sizeof(struct node));
    if(nodes==NULL)
    {
        printf("\nMemory is not available");
        exit(1);
    }
    printf("\nEnter the USN of the student: ");
    scanf("%s",nodes->usn);
    printf("\nEnter the Name of the student: ");
    scanf("%s",nodes->name);
    printf("\nEnter the Branch of the student: ");
    scanf("%s",nodes->branch);
    printf("\nEnter the Semester of the student: ");
    scanf("%d",&nodes->sem);
    printf("\nEnter the phone number of the student: ");
    scanf("%ld",&nodes->phone);
    nodes->link=NULL;
    count++;
    return nodes;
}
NODE insertfront()
{
    NODE temp;
    temp=create();
    if(start==NULL)
    {
           return temp;
    }

    temp->link=start;
    return temp;
}
NODE deletefront()
{
    NODE temp;
    if(start==NULL)
    {
        printf("\nLinked list is empty");
        return NULL;
    }
    if(start->link==NULL)
    {
            printf("\nThe Student node with usn:%s is deleted ",start->usn);
            count--;
            free(start);
            return NULL;
    }
    temp=start;
    start=start->link;
    printf("\nThe Student node with usn:%s is deleted",temp->usn);
    count--;
    free(temp);
    return start;
}
NODE insertend()
{
    NODE cur,temp;
    temp=create();
    if(start==NULL)
    {
      return temp;
    }
    cur=start;
    while(cur->link!=NULL)
    {
         cur=cur->link;
    }
    cur->link=temp;
    return start;
}
NODE deleteend()
{
     NODE cur,prev;
     if(start==NULL)
     {
        printf("\nLinked List is empty");
        return NULL;
     }

     if(start->link==NULL)
     {
        printf("\nThe student node with the usn:%s is deleted",start->usn);
        free(start);
        count--;
        return NULL;
     }
     prev=NULL;
     cur=start;
     while(cur->link!=NULL)
     {
         prev=cur;
         cur=cur->link;
     }
      printf("\nThe student node with the usn:%s is deleted",cur->usn);
      free(cur);
      prev->link = NULL;
      count--;
      return start;
}
void display()
{
    NODE cur;
    int num=1;
    if(start==NULL)
    {
        printf("\nNo Contents to display in list \n");
        return;
    }
    printf("\nThe contents of SLL: \n");
    cur=start;
    while(cur!=NULL)
    {
       printf("\n  USN: %s  Name: %s  Branch: %s  Sem: %d  Ph: %ld ",cur->usn, cur->name,cur->branch, cur->sem,cur->phone);
       cur = cur->link;
       num++;
    }
    printf("\n No of student are %d \n",count);
}
void stackdemo()
{
   int ch;
   while(1)
   {
     printf("\n1: Push operation ");
     printf("\n2: Pop operation ");
     printf("\n3: Display ");
     printf("\n4: Exit\n");
     printf("\nEnter your choice for stack demo: ");
     scanf("%d",&ch);

     switch(ch)
     {
        case 1: start=insertfront();
                break;
        case 2: start=deletefront();
                break;
        case 3: display();
               break;
       default : return;
     }
   }
   return;
}
int main()
{
    int ch,i,n;
    while(1)
    {
        printf("\nEnter the operation you want to perform \n");
        printf("\n1: Create the singly linked list");
        printf("\n2: Display the singly linked list");
        printf("\n3: Insert at the end of the linked list");
        printf("\n4: Delete at the end of the linked list");
        printf("\n5: Stack Demo using SLL(Insertion and Deletion at Front) ");
        printf("\n6: Exit \n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 : printf("\nEnter the number of students: ");
                 scanf("%d",&n);
                 for(i=1;i<=n;i++)
                    start=insertfront();
                 break;
        case 2: display();
                break;
        case 3: start=insertend();
                break;
        case 4: start=deleteend();
                break;
        case 5: stackdemo();
                break;
        case 6: exit(0);
        default: printf("\nINVALID CHOICE");
        }
    }
}

