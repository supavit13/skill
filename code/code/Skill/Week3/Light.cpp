#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
			return 0;
		else
		{
			if(pow((float)((int)sqrt(n)),2)==n)
			{
				cout<<"yes"<<endl;
				//break;
			}
			else
			{
				cout<<"no"<<endl;
			//	break;
			}
		}
	}
	
}
