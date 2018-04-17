/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      int a[10],i,j,temp;
      printf("Input : ");
      for(i=0;i<10;i++)
       scanf("%d",&a[i]);
      printf("min to max : ");
      for(i=0;i<10;i++)
      {
        for(j=i;j<10;j++)               
        if(a[j]<a[i])
         {
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
         }
        printf("%d ",a[i]);
      }
      printf("\n");
      printf("max to min : ");
      for(i=0;i<10;i++)
      {
        for(j=i;j<10;j++)               
        if(a[j]>a[i])
         {
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
         }
        printf("%d ",a[i]);
      }
           
      getch();
}
