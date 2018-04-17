#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int n;
	string x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		//cout<<x.size();
		for(int j=0;j<x.size();j++)
		{
			int count=0;
			for(int k=x.size()-1-j;k>0;k--)
			{
				cout<<" ";
				count++;
			}
			for(int l=0;l<x.size()-count;l++)
			{
				cout<<x[l];
			}
			cout<<endl;
		}
		for(int j=0;j<x.size()-1;j++)
		{
			for(int k=1+j;k<x.size();k++)
				cout<<x[k];
			cout<<endl;
		}
	}
	

}
