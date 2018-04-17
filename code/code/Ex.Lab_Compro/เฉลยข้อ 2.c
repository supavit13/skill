/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      int a[10],i,j,n;
      printf("Input : ");
      for(i=0;i<10;i++)
       scanf("%d",&a[i]);

      printf("Prime number : ");
      for(i=0;i<10;i++)
      { 
        n=0;               
        for(j=1;j<=a[i];j++)
        {
         if(a[i]%j==0)
          n++;
        }
        if(n==2)
         printf("%d ",a[i]);
      }
      
      getch();
}
