/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      char arr[100];
      int n=0,i;
      printf("Input : ");
      gets(arr);
      for(i=0;i<=strlen(arr);i++)
       if(arr[i]==' '||arr[i]=='\0')
        n++;
      printf("word : %d",n);
      
      getch();
}
