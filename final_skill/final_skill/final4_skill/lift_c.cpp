#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int lift,num,i,sum=0;
	cin>>num>>lift;
	int lift_num[num];
	for(i=0;i<num;i++)
		cin>>lift_num[i];
	
	sort(lift_num, lift_num + num);
	
	int cnt=0;    
	for(i=0;i<num;i++)
	{
		if(sum + lift_num[i] <= lift)
		{
			sum += lift_num[i];
			cnt++;
		}
	}
	cout<<cnt;
}
