#include<iostream>
#include<algorithm>

using namespace std;

/*int factorial(int n)
{
	if(n==1)
		return 1;
	else
		return factorial(n-1)*n;
}*/

int main()
{
	int n,k,l,fac,count=0;

		cin>>n>>k>>l;
		int per[100][n];
		int data[n];
		for(int i=0;i<n;i++)
		{
			data[i]=i+1;
		}
		while(l>100)
		{
			count++;
			l=l-100;
		}
	//	fac=factorial(n);
		int c=0,round=0;
			do 
			{
				for(int i=0;i<n;i++)
				{
					per[c][i]=data[i];
				}
			    //cout << data[0] << ' ' << data[1] << ' ' << data[2] <<' '<<endl;
			    c++;
			     if(c==100)
			     {
					//	cout<<"5555";
					round++;
			    	c=0;
				 }
				 if(round==count+1)
				 	break;
			    
			} while ( next_permutation(data,data+n) );
		
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<per[i][j]<<" ";
			}
			cout<<endl;
		}
	/*	for(int i=0;i<k;i++)
		{
			cout<<per[l-1][i]<<" ";
		}*/
	//	cout<<l<<" "<<count;
}
