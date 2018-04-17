#include <stdio.h>
#include <string.h>
int check(char a[100] ,int count)
{
	int i;
	for(i=0 ; i<(strlen(a)+1)/2 ; i++)
	{
		if(a[i]==a[(strlen(a)-1)-i])
		{
			count ++ ;
		}
	}
	return count;
}
int main()
{
    int i , count = 0 , j , k , mem;
    char a[100],b[100],c[100],d[100];
    gets(a);
	count =  check(a , count);
	if(count == (strlen(a)+1)/2) printf("%s" , a);
	if(count!=(strlen(a)+1)/2)
	{
		mem = strlen(a);
		strcpy(d,a);
		for(i=0 ; i<mem ; i++)
		{
			count = 0;
			strcpy(a,d);
			for(k=0 ; k<=i ; k++)
			{
				b[k] = a[k];
                b[k+1] = '\0';
				for(j=1 ; j<=strlen(b) ; j++)
				{
					c[j-1]=b[strlen(b)-j];
				}
				c[j-1]='\0';
			}
			strcpy(a,strcat(a,c));
			count = check(a,count);
			if(count == (strlen(a)+1)/2)
			{
				printf("%s" , a);
				break;
			}
		}
	}
}
