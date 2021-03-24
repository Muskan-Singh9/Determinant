#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define size 10

int main()
{
  float matrix[size][size], a[size], ratio, det=1;
  int i, j, k, n;

  printf("Enter order of matrix: \n");  /*Order of matrix*/
  scanf("%d", &n);

  printf("\nEnter Coefficients of matrix: \n");  /*Coefficients of matrix*/
  for(i=0; i<n; i++)                            /*i=0; i<n means i starting from 0 till n*/
  {
      for(j=0;j<n;j++)
      {
          printf("matrix[%d][%d]=", i,j);     /*i and j are the element numbers*/
          scanf("%f", &matrix[i][j]);
      }

  }
  for(i=0; i<n; i++)
  {
      if (matrix[i][i]==0.0)               /*Diagonal matrix not 0*/
      {
          printf("Error!");
          exit(0);
      }

      /*Upper triangular matrix using Gauss elimination method*/

      for(j=i+1;j<n;j++)                /*j increases from i+1 to n*/
      {
          ratio = matrix[j][i]/matrix[i][i];    /*Ratio is of element */

          for(k=0;k<n;k++)              /*k starting from 0 to n*/
          {
              matrix[j][k]= matrix[j][k]- ratio*matrix[i][k];      /*Subtracting the product of ratio and element from the upper element*/
          }

      }
  }

  /*Displaying the upper triangular matrix*/

  printf("\nThe Upper Triangular Matrix: \n");

  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {
          printf("%0.2f\t", matrix[i][j]);
      }
      printf("\n");
  }

  /*Calculating the determinant*/

  for(i=0;i<n;i++)
  {
      det= det * matrix[i][i];   /*Multiplying the diagonal elements*/
  }
  printf("The Determinant is: %0.3f", det);


  return 0;

}
