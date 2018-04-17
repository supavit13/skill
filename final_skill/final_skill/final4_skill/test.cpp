#include <iostream>
using namespace std;

int main()
{
	int n,m,k,cnt=1,i;
	cin>>n>>m>>k;
	int arr_n[k];
	for(i=0;i<k;i++)
	{
		if(cnt <= n)
		{
			arr_n[i] = 1;
			cnt++;
		}
		else if(cnt > n)
		{
			arr_n[i] = -1;
			cnt = 1;
		}
	}
	
	int arr_m[k],cnt_m=1;    
	for(i=0;i<k;i++)
	{
		if(cnt_m <= m)
		{
			arr_m[i] = 1;
			cnt_m++;
		}
		else if(cnt_m > m)
		{
			arr_m[i] = -1;
			cnt_m = 1;
		}
	}
	
	int sum_o=0,sum_x=0,sum_ox=0,sum_xo=0;    
	for(i=0;i<k;i++)
	{
		if(arr_n[i] == 1 && arr_m[i] == 1)
		    sum_o++;
		else if(arr_n[i] == -1 && arr_m[i] == -1)
		    sum_x++;
		else if(arr_n[i] == 1 && arr_m[i] == -1)
		    sum_ox++;
		else if(arr_n[i] == -1 && arr_m[i] == 1)
		    sum_xo++;
	}
	cout<<sum_o<<" "<<sum_x<<" "<<sum_ox<<" "<<sum_xo;
}
