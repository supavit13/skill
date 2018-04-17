#include <iostream>
using namespace std;

int main()
{
	int u,v,check;
	while(1)
	{
		cin>>u>>v;
		if(u == 0 && v == 0)
		    return 0;
		else
		{
			while(u != v)
			{
				if(u > v)
				{
					check = u%2;
					if(check == 0)
						u = (u-2)/2;
					else if(check != 0)
					    u = (u-1)/2;
				}
				else
				{
					check = v%2;
					if(check == 0)
						v = (v-2)/2;
					else
					    v = (v-1)/2;
				}
			}
			cout<<u<<endl;
		}
	}
}
