/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      int a[2][3],i,j;
      printf("Input Matrix A:\n");
      for(i=0;i<2;i++)
       for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
      printf("Transpose A :\n");
      for(i=0;i<3;i++)
       {
          for(j=0;j<2;j++)
          printf("%d ",a[j][i]);
          printf("\n");
       }
       
      getch();
}
