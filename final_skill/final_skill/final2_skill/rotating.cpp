#include <iostream>
using namespace std;

int main()
{
	int num,degree,i,j,sum=0;
	cin>>num;
	int arr[num][num];
	
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			cin>>arr[i][j];
	
	cin>>degree;
	sum = degree % 360;
	
	if(sum == 0)
	{
		for(i=0;i<num;i++)
		{
			for(j=0;j<num;j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
	}
	else if(sum == 90)
	{
		for(i=0;i<num;i++)
		{
			for(j=num-1;j>=0;j--)
				cout<<arr[j][i]<<" ";
			cout<<endl;
		}
	}
	else if(sum == 180)
	{
		for(i=num-1;i>=0;i--)
		{
			for(j=num-1;j>=0;j--)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
	}
	else if(sum == 270)
	{
		for(j=num-1;j>=0;j--)
		{
			for(i=0;i<num;i++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
	}
	else
	    cout<<"No output"<<endl;
}
