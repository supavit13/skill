/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      int a[10],i;
      printf("Input : ");
      for(i=0;i<10;i++)
       scanf("%d",&a[i]);
      printf("Even number : ");
      for(i=0;i<10;i++)
       {
         if(a[i]%2==0)
          printf("%d ",a[i]);
       }
      printf("\n");
      printf("Old number : ");
      for(i=0;i<10;i++)
       {
          if(a[i]%2==1)
          printf("%d ",a[i]);
       }
               
      getch();
}
