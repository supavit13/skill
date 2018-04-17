#include<iostream>

using namespace std;

int main()
{
	int n,m,k,c=0,Paint,Varnish,check1=0,check2=0;
	cin>>n>>m>>k;
	Paint=n+1;
	Varnish=m+1;
	if(Paint%2==0 && Varnish%2==0)
	{
		for(int i=0;i<=k;)
		{
			if(i==Paint && i==Varnish)
			{
				Paint=Paint+(n+1);
				Varnish=Varnish+(m+1);
				c++;
			}		
			else if(i==Paint)
			{
				Paint=Paint+(n+1);
				check1++;
			}
			else if(i==Varnish)
			{
				Varnish=Varnish+(m+1);
				check2++;
			}	
			i=i+2;	
		}
	}
	else
	{
		for(int i=0;i<=k;i++)
		{
			if(i==Paint && i==Varnish)
			{
				Paint=Paint+(n+1);
				Varnish=Varnish+(m+1);
				c++;
			}		
			else if(i==Paint)
			{
				Paint=Paint+(n+1);
				check1++;
			}
			else if(i==Varnish)
			{
				Varnish=Varnish+(m+1);
				check2++;
			}		
		}
	}
	k=k-c-check1-check2;
	cout<<k<<" "<<c<<" "<<check2<<" "<<check1;
}
