#include<iostream>

using namespace std;

int main()
{
	int n,m,count=0,a,T,tmp=0,index=0;
	cin>>n>>m;
	int W[n],V[n],D[n],X[n],Ans[m],k=0,j=0;
	for(int i=0;i<n+m;i++)
	{
		W[i]=-1;
		V[i]=-1;
		D[i]=-1;
		X[i]=-1;
	}
	for(int i=0;i<n+m;i++)
	{
		count++;
		cin>>a;
		if(a==1)
		{

			cin>>T;
			if(T==1)
			{
				cin>>W[j]>>V[j];//type 1
			}
			if(T==2)
			{
				cin>>W[j]>>V[j]>>D[j];//type2
			}
			if(T==3)
			{
				cin>>W[j]>>V[j]>>D[j]>>X[j];//type3
			}
			j++;
		}
		else if(a==2)//pick gift
		{
			index=0;
			tmp=1000001;
			for(int i=0;i<n;i++)
			{
				if(W[i]<tmp && W[i]!=-1)//check weight a little
				{
					tmp=W[i];
					index=i; //keep position weight a little
				}

			}

			if(V[index]==-1)
				V[index]=0;
				//cout<<V[index]<<endl;
				Ans[k++]=V[index];

	///////////////////// set array after pick gift ////////////////////////////
				W[index]=-1;
				V[index]=-1;
				D[index]=-1;
				X[index]=-1;
				//cout<<Ans[0]<<endl;
		}
		for(int j=0;j<n;j++)
		{
			if(count==D[j] && X[j]==-1)//type2    check time Gift Disappear
			{
				W[j]=-1;
				V[j]=-1;
				D[j]=-1;
			}
			else if(count==D[j] && X[j]!=-1)//type3   check time Gift weight reduce follow X
			{
				W[j]=X[j];
			}
		}


	}
	//cout<<Ans[0]<<endl;
	/*for(int i=0;i<m;i++)
	{
		cout<<W[i]<<" "<<V[i]<<" "<<D[i]<<" "<<X[i]<<" "<<endl;
	//	cout<<Ans[i]<<endl;
	}*/

	for(int i=0;i<m;i++)
	{
		//cout<<W[i]<<" "<<V[i]<<" "<<D[i]<<" "<<X[i]<<" "<<endl;
		cout<<Ans[i]<<endl;
	}

}
