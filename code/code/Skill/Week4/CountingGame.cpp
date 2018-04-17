#include<iostream>
#include<vector>

using namespace std;
vector<int> bot;

int main()
{
	int n,x,i=0;
	cin>>n>>x;
	int sum=n-1;
	while(1)//calculate bot
	{
		bot.push_back(sum);
		sum=sum-(x+1);
		if(sum<=0)
			break;
	}
	for(int i=bot.size()-1;i>=0;i--)
	{
		if(bot[bot.size()-1]>x)//human begin
		{
			int a;
			cin>>a;
			//i--;
			cout<<bot[i]<<endl;
			if(i==0)
			{
				cin>>a;
				if(a==n)
					cout<<"HaHa You Lose!!";
			}
		}
		else//bot begin
		{
			cout<<bot[i]<<endl;
			int a;
			cin>>a;
			
			if(i==0)
			{
				if(a==n)
					cout<<"HaHa You Lose!!";
			}
		}
		
	}
}
