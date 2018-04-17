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
      int a=0,e=0,i=0,o=0,u=0,n=0;
      printf("Input : ");
      gets(str);
      for(i=0;str[i]!='\0';i++)
       {
          if(str[i]=='a')
           a++;
          else if(str[i]=='e')
           e++;
          else if(str[i]=='i')
           n++;
          else if(str[i]=='o')
           o++;
          else if(str[i]=='u')
           u++;
       }
      printf("a = %d , e = %d , n = %d  , o = %d , u = %d",a,e,n,o,u);
      
      getch();
}
