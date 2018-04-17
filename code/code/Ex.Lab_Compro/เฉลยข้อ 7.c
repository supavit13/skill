/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      int a[2][3],b[3][2],c[2][2],i,j,k,sum=0;
      printf("Input Matrix A :\n");
      for(i=0;i<2;i++)
       for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
      
      printf("Input Matrix B : \n");
      for(i=0;i<3;i++)
       for(j=0;j<2;j++)
        scanf("%d",&b[i][j]);
       
      for(i=0;i<2;i++)
       for(j=0;j<2;j++)
        {
           
           for(c[i][j]=0,k=0;k<3;k++)
            c[i][j]=c[i][j]+a[i][k]*b[k][j];
           
        }
        
      printf("Matrix C : \n");
      for(i=0;i<2;i++)
       {
          for(j=0;j<2;j++)
            printf("%d ",c[i][j]);
          printf("\n");
       }
      
      getch();
}
