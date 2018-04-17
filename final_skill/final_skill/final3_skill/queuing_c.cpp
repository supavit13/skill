#include <iostream>
using namespace std;

int main()
{
	int t,n,m,num,i,j,arr[50],sum,array[50],tmp;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>m>>n;
		sum = 0;
		for(j=0;j<n;j++)
		{
			cin>>num;
			arr[j] = num;
			sum += num;
		}
		
		for(j=0;j<m;j++)
			array[j] = 0;
		
		for(j=0;j<n;j++)
		{
			int min = array[0];
			tmp = 0;
			for(int k=1;k<m;k++)
			{
				if(array[k] < min)
				{
					min = array[k];
					tmp = k;
				}
			}
			array[tmp] += arr[j];
		}
		
		int min = array[0];
		tmp = 0;
		for(j=1;j<m;j++)
		{
			if(array[j] > min)
			{
				min = array[j];
				tmp = j;
			}
		}
		cout<<array[tmp]<<endl;
	}
}
