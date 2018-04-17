#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
	int k=0;
	while(1)
	{
		string s;
		cin>>s;
		if(s=="end")
			return 0;
		else
		{
			vector <char> container;
			for(int i=0;i<s.size();i++)
			{
				if(i==0)
					container.push_back(s[i]);
				else 
				{
					int count=0;
					for(int j=0;j<container.size();j++)
					{
						if(s[i]<=container[j])
						{
							container[j]=s[i];
							count=0;
							break;
						}
						else
						{
							count++;
							//container.push_back(s[i]);
						}
					}
					if(count!=0)
						container.push_back(s[i]);
					
				}
				//cout<<s[i];
			}
			k++;
			cout<<"Case "<<k<<": "<<container.size()<<endl;
			/*for(int i=0;i<container.size();i++)
			{
				cout<<container[0];
			}*/
		}
	}
}
