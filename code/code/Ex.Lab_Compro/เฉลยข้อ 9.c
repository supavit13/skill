/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      char str1[50],str2[50];
      int i,j;
      printf("Input string1 : ");
      gets(str1);
      printf("Input string2 : ");
      gets(str2);
      for(i=0;str1[i]!='\0';i++);
       for(j=0;str2[j]!='\0';j++,i++)
        str1[i]=str2[j];
        str1[i]='\0';
      printf("Result : %s",str1);
      
      getch();
}
