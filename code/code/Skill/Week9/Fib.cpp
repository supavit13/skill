#include<iostream>
#include<vector>

using namespace std;


int main()
{
	long long a,b;
	while(1)
	{
		cin>>a>>b;
		if(a==0 && b==0)
			return 0;
		else
		{
		    long long f1=1,f2=2;
		    long long sum;
		    vector<long> fib;
			fib.push_back(f1);
			fib.push_back(f2);
			while(1)
			{
				    sum=f1+f2;
					fib.push_back(sum);
					f1=f2;
					f2=sum;
					if(sum>b)
						break;
					
			}
			int count=0;
			for(int i=0;i<fib.size();i++)
			{
				if(fib[i]>=a && fib[i]<=b)
					count++;
					
				//cout<<fib[i]<<" ";
			}
			cout<<count<<endl;
		}
	}
}
