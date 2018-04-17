#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int Square[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>Square[i][j];
		}
	}
	int d;
	cin>>d;
	while(d>360)
	{
		d=d-360;
	}
	if(d==0)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<Square[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(d==90)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=n-1;j>=0;j--)
			{
				cout<<Square[j][i]<<" ";
			}
		//	break;
			cout<<endl;
		}
		//cout<<Square[0][3];
	}
	else if(d==180)
	{
		for(int i=n-1;i>=0;i--)
		{
			for(int j=n-1;j>=0;j--)
			{
				cout<<Square[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(d==270)
	{
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<n;j++)
			{
				cout<<Square[j][i]<<" ";
			}
			cout<<endl;
		}
	}
	else if(d==360)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<Square[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
		cout<<"No output";
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<Square[i][j]<<" ";
		}
		cout<<endl;
	}*/
}
