/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      char str[50];
      int i,j,k;
      printf("Input : ");
      gets(str);
      k=strlen(str)-1;
      for(i=k;i>=0;i--)
      {  if(str[i-1]==' '||i==0)
         {   for(j=i;j<=k;j++)
               printf("%c",str[j]);
             printf(" ");
             k=i-2;
         }
      }  
      
      getch();
}
