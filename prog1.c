#include <stdio.h>
void read_arr();
void lsearch();
 
int num,array[100],i,  keynum, found = 0;
int main()

{  
 printf("Enter the number of elements ");

    scanf("%d", &num);
    read_arr();
    lsearch();
    return 0;
}

    
void read_arr(){
    printf("Enter the elements one by one \n");

    for (i = 0; i < num; i++)

    {

        scanf("%d", &array[i]);

    }
}
 void lsearch(){

    printf("Enter the element to be searched ");

    scanf("%d", &keynum);

    /*  Linear search begins */

    for (i = 0; i < num ; i++)

    {

        if (keynum == array[i] )

        {

            found = 1;

            break;

        }

    }

    if (found == 1)

        printf("Element is present in the array at position %d",i+1);

    else

        printf("Element is not present in the array\n");

}