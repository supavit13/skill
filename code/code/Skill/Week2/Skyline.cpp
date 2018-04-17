#include<iostream>

using namespace std;

int main()
{
	int n,build[255]={0},Li,Hi,Ri,maxR=0,maxL=255;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>Li>>Hi>>Ri;
		if(maxR<Ri)
			maxR=Ri;
		if(maxL>Li)
			maxL=Li;
		for(int j=Li;j<Ri;j++)
		{
			if(Hi>build[j])
			{
				build[j]=Hi;
			}
		}
	}

	for(int i=maxL-1;i<maxR;i++)
	{
		if(maxL==0)
		{
			cout<<i<<" "<<build[i]<<" ";
			maxL=1;
		}
		if(build[i]<build[i+1]||build[i]>build[i+1])
			cout<<i+1<<" "<<build[i+1]<<" ";
		
	}
//	cout<<endl;
	/*for(int i=0;i<maxR;i++)
	{
		cout<<build[i]<<" ";
	}
	cout<<endl;*/
	
//	cout<<maxL<<" "<<maxR;
}
