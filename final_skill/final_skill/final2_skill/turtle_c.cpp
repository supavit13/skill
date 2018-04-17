#include <iostream>
using namespace std;

int main()
{
	int num,i,x=0,y=0;
	cin>>num;
	string c,direct[1];
	int walk[num];
	direct[0] = "E";
	    
	for(i=0;i<num;i++)
	{
		cin>>c>>walk[i];
		
		if(c == "FD")
		{
			if(direct[0] == "E")
			    x+=walk[i];
			else if(direct[0] == "N")
			    y+=walk[i];
			else if(direct[0] == "S")
			    y-=walk[i];
			else if(direct[0] == "W")
			    x-=walk[i];
		}
		else if(c == "BW")
		{
			if(direct[0] == "E")
			{
			    x-=walk[i];
			    direct[0] = "W";
			}
			else if(direct[0] == "N")
			{
			    y-=walk[i];
			    direct[0] = "S";
			}
			else if(direct[0] == "S")
			{
			    y+=walk[i];
			    direct[0] = "N";
			}
			else if(direct[0] == "W")
			{
			    x+=walk[i];
			    direct[0] = "E";
			}
		}
		else if(c == "RT")
		{
			if(direct[0] == "E")
			{
			    y-=walk[i];
			    direct[0] = "S";
			}
			else if(direct[0] == "N")
			{
			    x+=walk[i];
			    direct[0] = "E";
			}
			else if(direct[0] == "S")
			{
			    x-=walk[i];
			    direct[0] = "W";
			}
			else if(direct[0] == "W")
			{
			    y+=walk[i];
			    direct[0] = "N";
			}
		}
		else if(c == "LT")
		{
			if(direct[0] == "E")
			{
			    y+=walk[i];
			    direct[0] = "N";
			}
			else if(direct[0] == "N")
			{
			    x-=walk[i];
			    direct[0] = "W";
			}
			else if(direct[0] == "S")
			{
			    x+=walk[i];
			    direct[0] = "E";
			}
			else if(direct[0] == "W")
			{
			    y-=walk[i];
			    direct[0] = "S";
			}
		}
	}
	
	if(x <= -50000 || x >= 50000 || y <= -50000 || y >= 50000)
	    cout<<"DEAD"<<endl;
	else
	{
		cout<<x<<" "<<y<<endl;
		cout<<direct[0];
	}
}
