#include <stdio.h>
int nub(int n)
{
	int cou = 0;
	do{
		if(n%2 == 1)cou++;
		n /= 2;
		}while(n!=0);
		return cou;
}
int main()
{
	int n,i,a;
	do
	{
		scanf("%d",&n);
		if(n!=0)
		{
			a = nub(n);
			i = n+1;
			while(1)
			{
				if(a == nub(i))
				{
					printf("%d\n",i);
					break;
				}
				i++;
			}
		}
		else
			break;
	}while(1);
}
