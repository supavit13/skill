#include<iostream>
#include<cstring>

using namespace std;

int box[6],front[6];

void swap(string x,int count)
{
	int tmp1=0,tmp2=0;
	for(int i=0;i<6;i++)
	{
		box[i]=i+1;
	}
	for(int i=0;i<x.size();i++)
	{
		if(x[i]=='F')
		{
			tmp1=box[1];
			box[1]=box[0];
			tmp2=box[5];
			box[5]=tmp1;
			tmp1=box[4];
			box[4]=tmp2;
			box[0]=tmp1;
		}
		if(x[i]=='B')
		{
			tmp1=box[4];
			box[4]=box[0];
			tmp2=box[5];
			box[5]=tmp1;
			tmp1=box[1];
			box[1]=tmp2;
			box[0]=tmp1;
		}
		if(x[i]=='L')
		{
			tmp1=box[2];
			box[2]=box[0];
			tmp2=box[5];
			box[5]=tmp1;
			tmp1=box[3];
			box[3]=tmp2;
			box[0]=tmp1;
		}
		if(x[i]=='R')
		{
			tmp1=box[3];
			box[3]=box[0];
			tmp2=box[5];
			box[5]=tmp1;
			tmp1=box[2];
			box[2]=tmp2;
			box[0]=tmp1;
		}
		if(x[i]=='C')
		{
			tmp1=box[2];
			box[2]=box[1];
			tmp2=box[4];
			box[4]=tmp1;
			tmp1=box[3];
			box[3]=tmp2;
			box[1]=tmp1;
		}
		if(x[i]=='D')
		{
			tmp1=box[3];
			box[3]=box[1];
			tmp2=box[4];
			box[4]=tmp1;
			tmp1=box[2];
			box[2]=tmp2;
			box[1]=tmp1;	
		}
		
	}
	front[count]=box[1];
	
/*	for(int i=0;i<6;i++)
	{
		cout<<box[i]<<" ";
	}
	cout<<endl;*/
	/*for(int i=0;i<x.size();i++)
	{
		cout<<x[i];
	}*/
}

int main()
{
	int n,count=0;
	cin>>n;
	string x;
	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		swap(x,count);
		count++;
	}
	
	for(int i=0;i<count;i++)
	{
		cout<<front[i]<<" ";
	}

}
