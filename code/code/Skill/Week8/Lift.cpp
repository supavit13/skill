#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,w;
	cin>>n>>w;
	int lift[n];
	for(int i=0;i<n;i++)
	{
		cin>>lift[i];
	}
	sort(lift,lift+n);
	int over=w,count=0;
	for(int i=0;i<n;i++)
	{
		if(over<lift[i])
		{
			break;
		}
		else
		{
			over=over-lift[i];
			count++;
		}
		
	}
	cout<<count;
	
}
