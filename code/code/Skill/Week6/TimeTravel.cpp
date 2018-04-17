#include<iostream>
#include <cmath>
#include<algorithm>

using namespace std;

int factorial(int n)
{
	if(n==1)
		return 1;
	else
		return factorial(n-1)*n;
}

int main()
{
	int T,N,c=0;
	cin>>T;
	while(c<T)
	{
		cin>>N;
	//	int fac=factorial(N);
		int walk[N+1][3], data[N],Sequence[N],result=0;
		for(int i=0;i<N;i++)
		{
			data[i]=i+1;
			Sequence[i]=0;
			for(int j=0;j<3;j++)
			{
				cin>>walk[i][j];
			}
		}
		walk[N][0]=0;
		walk[N][1]=0;
		walk[N][2]=0;
	//	int k=0;
		int sum=999999;
		do 
		{
			//cout<<data[0]<<' '<<data[1]<<endl;
			int x=0,y=0,time=0,tmp;
			tmp = abs(x-walk[data[0]-1][0]) + abs(y-walk[data[0]-1][1]) + abs(time-walk[data[0]-1][2]);
			//cout<<walk[data[0]-1][0]<<' '<<walk[data[0]-1][1]<<' '<<walk[data[0]-1][2]<<endl;
			//cout<<tmp<<endl;
			for(int i=0;i<N-1;i++)
			{
				tmp = tmp + abs(walk[data[i]-1][0]-walk[data[i+1]-1][0]) + abs(walk[data[i]-1][1]-walk[data[i+1]-1][1]) + abs(walk[data[i]-1][2]-walk[data[i+1]-1][2]);
			}
			tmp = tmp + abs(x-walk[data[N-1]-1][0]) + abs(y-walk[data[N-1]-1][1]) + abs(time-walk[data[N-1]-1][2]);
		//	cout<<tmp<<endl;
			if(tmp<sum)
			{
				sum=tmp;
				result=tmp;
			}	
		} while ( next_permutation(data,data+N) );
	/*	for(int i=0;i<N;i++)
		{
			cout<<Sequence[i]<<' ';
		}*/
		cout<<result<<endl;
		c++;
	}
}
