#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int box[n],tmp1[n],tmp2[n];
	for(int i=0;i<n;i++)
	{
		box[i]=0;
		tmp1[i]=0;
		tmp2[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(i==0)
		{
			box[i]=b;
			box[i+1]=a;
		}
		else
		{
			int index=-1;
			for(int j=0;j<n;j++)
			{
				if(box[j]==b)
					index=j;
			}
			if(index==-1)
			{
				tmp1[0]=b;
				tmp1[1]=a;
			}
			else if(index!=-1)
			{
				for(int j=0;j<n;j++)
				{
					
				}
			}
		}
	}
}
