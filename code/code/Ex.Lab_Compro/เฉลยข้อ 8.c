/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      char arr[50];
      int i=0;
      printf("Input : ");
      gets(arr);
      while(arr[i]!='\0')
       i++;
      printf("length : %d",i);
      getch();
}
