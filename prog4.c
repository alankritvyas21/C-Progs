#include <stdio.h>
void matrix_multiply();
 void transpose_matrix();
 void upper_triangle();
int  A[100][100],B[100][100],C[100][100],D[100][100],m,n,p,q,c,d,k,multiply = 0,upper; 
int main()
{
  printf("Enter number of rows and columns of matrix A\n");
  scanf("%d %d",&m,&n);
  printf("Enter elements of matrix A\n");
  for(c=0;c<m;c++)
  {
    for(d=0;d<n;d++)
    {
      scanf("%d",&A[c][d]);
    }
  }
  printf("Enter number of rows and columns of matrix B\n");
  scanf("%d %d",&p,&q);
  if(n!=p)
  {
    printf("The multiplication isn't possible.\n");
  }
  else
  {
    printf("Enter elements of matrix B\n");
    for(c=0;c<p;c++)
    {
      for(d=0;d<q;d++)
      {
        scanf("%d", &B[c][d]);
      }
    }
  }

    matrix_multiply();
    transpose_matrix();
    upper_triangle();
    return 0;
  }
  void matrix_multiply(){
      for(c=0;c<m;c++) 
      {
      for(d=0;d<q;d++) 
      {
        for(k=0;k<p;k++) 
        {
          multiply=multiply+A[c][k]*B[k][d];
        }
 
        C[c][d] = multiply;
        multiply = 0;
      }
    }
    printf("Product of the matrices:\n");
    for(c=0;c<m;c++) 
    {
      for(d=0;d<q;d++)
      {
        printf("%d\t",C[c][d]);
      }
      printf("\n");
    }
  }
 void transpose_matrix()
 {
     for(c=0;c<m;c++)
        {
             for(d=0;d<n;d++)
                {
                    D[d][c]=C[c][d];
 }
        }
         printf("\nTranspose of the matrix:\n");
     for(c=0;c<m;c++) 
    {
      for(d=0;d<q;d++)
      {
            printf("%d\t ",D[c][d]);
            if(d==q-1)
                printf("\n");
        }
 }
 }
 void upper_triangle()
 {
   upper=1;
   for(c=0;c<m;c++) 
    {
      for(d=0;d<q;d++)
      {
      if(d<c && A[c][d])
      {
        upper=0;
      }
    }
  }
  if(upper==1)
  {
    printf("The matrix is a upper triangle matrix:\n ");
    for(c=0;c<m;c++) 
    {
      for(d=0;d<q;d++)
      {
        printf("%d\t",C[c][d]);
      }
      printf("\n");
    }
  }
  else{
    printf("The traingle is not an upper triangle matrix");
  }
 }