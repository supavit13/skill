#include<iostream>

using namespace std;

int main()
{
	int n,walk;
	cin>>n;
	string direct;
	int x=0,y=0;
	char head='E';
	for(int i=0;i<n;i++)
	{
		cin>>direct>>walk;
		if(direct=="FD")
		{
			if(head=='E')
			{
				x=x+walk;
			}
			else if(head=='W')
			{
				x=x-walk;
			}
			else if(head=='S')
			{
				y=y-walk;
			}
			else if(head=='N')
			{
				y=y+walk;
			}
			
		}
		else if(direct=="RT")
		{
			if(head=='E')
			{
				head='S';
				y=y-walk;
			}
			else if(head=='W')
			{
				head='N';
				y=y+walk;
			}
			else if(head=='S')
			{
				head='W';
				x=x-walk;
			}
			else if(head=='N')
			{
				head='E';
				x=x+walk;
			}
		}
		else if(direct=="LT")
		{
			if(head=='E')
			{
				head='N';
				y=y+walk;
			}
			else if(head=='W')
			{
				head='S';
				y=y-walk;
			}
			else if(head=='S')
			{
				head='E';
				x=x+walk;
			}
			else if(head=='N')
			{
				head='W';
				x=x-walk;
			}
		}
		else if(direct=="BW")
		{
			if(head=='E')
			{
				head='W';
				x=x-walk;
			}
			else if(head=='W')
			{
				head='E';
				x=x+walk;
			}
			else if(head=='S')
			{
				head='N';
				y=y+walk;
			}
			else if(head=='N')
			{
				head='S';
				y=y-walk;
			}
		}
	}
	if(x>=-50000 && x<=50000 && y>=-50000 && y<=50000)
	{
		cout<<x<<" "<<y<<endl;
		cout<<head;
	}
	else
		cout<<"DEAD";
	//cout<<head;
}
