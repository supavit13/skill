/*
  Name: P`Tarn
  Copyright: Dev-C++
  Date: 07/09/11 22:43
  Description: 
*/
#include<stdio.h>
main()
{
      char str1[100],str2[100],str[200];
      int i=0,j=0;
      printf("Input string1 : ");
      gets(str1);
      printf("Input string2 : ");
      gets(str2);
      for(;;j++)
      {  str[i++]=str1[j];
           if(str1[j+1]=='\0')
              break;
         
         str[i++]=str2[j];
           if(str2[j+1]=='\0')
              break;
      }
      str[i]='\0';
      printf("Resuit : %s",str);
      
      getch();
}
