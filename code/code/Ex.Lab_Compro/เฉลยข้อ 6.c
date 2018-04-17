/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      int a[2][2],b[2][2],c[2][2],i,j;
      
      printf("Input Matrix A : \n");
      for(i=0;i<2;i++)
       {
          for(j=0;j<2;j++)
           scanf("%d",&a[i][j]);
       }
      printf("Input Matrix B : \n");
      for(i=0;i<2;i++)
       {
          for(j=0;j<2;j++)
           scanf("%d",&b[i][j]);
       }
      
      for(i=0;i<2;i++)
       {
         for(j=0;j<2;j++)
          c[i][j]=a[i][j]+b[i][j];
       }
      
      printf("Matrix C :\n");
      for(i=0;i<2;i++)
      {  
         for(j=0;j<2;j++)
           printf("%d ",c[i][j]);
         printf("\n");
      }
       
      getch();
}
