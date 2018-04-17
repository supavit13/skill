#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T!=0)
	{
		int M,N;
		cin>>M>>N;
		int time[N],Q[M];
		for(int i=0;i<N;i++)
			cin>>time[i];
		for(int i=0;i<M;i++)
			Q[i]=0;/////Q[i]=time[i];*******
		int tmp,index=0;
	//	cout<<Q[0]<<" "<<Q[1]<<endl; 
		for(int i=0;i<N;i++)//for(int i=M;i<N;i++)*********
		{
			tmp=2000;
			for(int j=0;j<M;j++)
			{
				if(Q[j]<tmp)
				{
					tmp=Q[j];
					index=j;
				}	
			}
		//	sort(Q,Q+M);
		//	cout<<index<<endl;
		//	Q[0]=Q[0]+time[i];
			Q[index]=Q[index]+time[i];
		}	
		int result=0;
	//	sort(Q,Q+M);
	//	cout<<Q[M-1]<<endl;
		for(int i=0;i<M;i++)
		{
			if(Q[i]>result)
			{
				result=Q[i];
			}
		//	cout<<Q[i]<<" ";
		}
		//cout<<endl;
		cout<<result<<endl;
		T--;
	}
}
