#include<stdio.h>
int main()
{
    int n,i,array[100],search,first,mid,last;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Enter the value to be searched: ");
    scanf("%d",&search);
    first=0;
    last=n-1;
    mid=(first+last)/2;
    while(first<=last)
    {
        if(array[mid]<search)
        {
            first=mid+1;
        }
        else if(array[mid]==search)
        {
            printf("The valuse searched is present at location %d ",mid+1);
        }
         else{
            last=mid-1;
            mid=(first+last)/2;
        }
    }
       if(first>last)
      printf("Value not present in the list");
   return 0;  
}
