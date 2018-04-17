#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int power,num,i,sum=0;
	cin>>power>>num;
	int power_num[num];
	for(i=0;i<num;i++)
	{
		cin>>power_num[i];
		sum += power_num[i];
	}
	cout<<endl;
	
	sort(power_num, power_num + num);
	
	if(sum < power)
	    cout<<"0";
	else
	{
		int cnt=0;    
		for(i=num-1;i>=0;i--)
		{
			power = power - power_num[i];
			cnt++;
			if(power <= 0)
			{
				cout<<cnt;
				return 0;
			}
		}
	}
}
