#include<iostream>

using namespace std;

int gcd(int a,int b)
{
        if(a==0)
        	return b;
        else
        	return gcd(b%a,a);        
}

int main()
{
	int R,G,min;
	cin>>R>>G;
	min=gcd(R,G);
//	cout<<min;	
	if(min%2==0)
	{
		for(int i=1;i<=min/2;i++)
		{
			if(R%i==0&&G%i==0)
			{
				cout<<i<<" "<<R/i<<" "<<G/i<<endl;
			}
			
		}
		cout<<min<<" "<<R/min<<" "<<G/min<<endl;
	}	
	else
	{
		for(int i=1;i<=min/3;i+=2)
		{
			if(R%i==0&&G%i==0)
			{
				cout<<i<<" "<<R/i<<" "<<G/i<<endl;
			}	
		}
		cout<<min<<" "<<R/min<<" "<<G/min<<endl;
	}	
	
}
