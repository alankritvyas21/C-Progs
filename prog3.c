#include<stdio.h>
void bubble_sort();
void insert_sort();
void select_sort();
int smallest();
int array[100],i, j, n, temp,x,k,pos,small;
int main()
{
    
    printf("Enter the number of elements to in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:");
    for(i=0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }
     printf("Sorting Method: ");
     printf("\n1. Bubble Sort\n");
     printf("\n2. Insertion Sort\n");
     printf("\n3. Selection Sort\n");
     scanf("%d",&x);
     switch (x)
     {
     case 1: bubble_sort();
         break;
     
     case 2: insert_sort();
         break;

     case 3: select_sort();
         break;
    
     default:
     printf("Error!!!!!!!");
         break;
     }
    return 0;
}

void bubble_sort(){
    
    printf("\nBubble Sort\n");
    for(i=0; i<(n-1); i++)
    {
        for(j=0; j<(n-i-1); j++)
        {
            if(array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    printf("Array elements in ascending order:\n\n");
    for(i=0; i<n; i++)
        printf("%d ", array[i]);
}
void insert_sort(){
    {
        printf("\nInsertion Sort\n");
    for(i=1;i<n;i++)
    {
        temp=array[i];
        j = i-1;
        while((temp<array[j]) && (j>=0))
            {
                array[j+1]=array[j];
                j--;
            }
        array[j+1] = temp;
    }
   
    printf("Array elements in ascending order:\n\n");
    for(i=0; i<n; i++)
        printf("%d ", array[i]);

}
}
void select_sort(){
    printf("\nSelection Sort\n");
    for(k=0;k<n;k++)
    {
        pos= smallest(array,k,n);
        temp=array[k];
        array[k]=array[pos];
        array[pos]=temp;
    }
    printf("Array elements in ascending order:\n\n");
    for(i=0; i<n; i++)
        printf("%d ", array[i]);

}
int smallest(int arr[],int k,int n)
{
    pos=k; 
    small=array[k];
    for(i=k+1;i<n;i++)
    {
        if(array[i]<small)
        {
            small=array[i];
            pos=i;
        }
    }
    return pos;
}
