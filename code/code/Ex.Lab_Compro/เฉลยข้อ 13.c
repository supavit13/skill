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
      int i,len;
      printf("Input : ");
      gets(str);
      len=strlen(str);
      printf("reverse : ");
      for(i=len-1;i>=0;i--)
      printf("%c",str[i]);
      
      
       getch();
}
