/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      int a[10],i,max,min,sum=0;
      float avg;
      printf("Input : ");
      for(i=0;i<10;i++)
       scanf("%d",&a[i]);
      for(i=0;i<10;i++)
       sum=sum+a[i];
      for(i=0;i<10;i++)   
       {
          max=min=a[0];
          if(a[i]>max)
            max=a[i];
          if(a[i]<min)
            min=a[i];
       }
      avg=sum/10.0;
      printf("Max = %d\n",max);
      printf("Min = %d\n",min);
      printf("sum = %d\n",sum);
      printf("avg = %.2f",avg);
      
      getch();
}
