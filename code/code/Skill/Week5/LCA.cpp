#include<iostream>

using namespace std;

int main()
{
	int u,v;
	while(1)
	{
		cin>>u>>v;
		if(u==0&&v==0)
			return 0;
		else
		{
			int a,b;
			if(u>v)
			{
				a=u;
				b=v;
			}
			else
			{
				a=v;
				b=u;	
			}	
			while(1)
			{
				if(a>b)
					a=(a-1)/2;
				if(b>a)
					b=(b-1)/2;
				if(a==b)
					break;
			}
			cout<<a;
		}
	}
}
