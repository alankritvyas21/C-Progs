#include<stdio.h>
void lsearch();
void binary_search();
int k,n,array[100],n,i,x,num,beg,end,mid,found=0;
int main()
{
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("Select sorting method: ");
    printf("\n1. Linear");
    printf("\n2. Binary\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1: lsearch();
    break;

    case 2: binary_search();
    break;
    default:
    printf("Error");
    
    }

    return 0;
}
void lsearch()
{
    printf("Enter the element to be searched: ");
    scanf("%d",&k);
    for (i=0;i<n;i++)
    {       
        if(k==array[i])
        {
            found=1;
             break;
        }
    }
    if(found==1)
    {
        printf("Element is present at location %d",i+1);
    }
    else
    {
        printf("Element is not present in the array\n");
    }
}
void binary_search()
{
    printf("Enter the element to be searched: ");
    scanf("%d",&num);
    beg=0;
    end=n-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(array[mid]==num)
        {
            printf("Element is present at location %d",mid+1);
            found=1;
            break;
        }
        else if(array[mid]>num)
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
        if(beg==0 && found==0)
        {
            printf("Error");
        }
    }
}