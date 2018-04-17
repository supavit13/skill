#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<string> CPE1,CPE2;
queue<string> PrintQ,Level;

int find(int count)
{
	while(!PrintQ.empty())
		{
			vector<string> LineData;
			int i=0;
			while(i<CPE2.size())
			{
				if(CPE2[i]==PrintQ.front())//check name of CPE2
				{
					LineData.push_back(CPE1[i]);
					count=1;
				}
				i++;
			}
			sort(LineData.begin(),LineData.end());//sort name follow dic
			int j=0;
			while(j<LineData.size())//print CPE same level
			{
				cout<<"("<<PrintQ.front()<<")"<<LineData[j]<<" ";
				Level.push(LineData[j]);
				j++;
			}
			PrintQ.pop();
		}
	return count;
}
int main()
{
	string headline,C1,C2;
	cin>>headline;
	while(1)
	{
		cin>>C1>>C2;
		if(C1=="#"&&C2=="#")
			break;
		else
		{
			CPE1.push_back(C1);
			CPE2.push_back(C2);
		}
	}
	cout<<headline<<endl;
	PrintQ.push(headline);
	while(1)
	{
		int count=0;
		count=find(count);//check wa yung me pee tee me nong aek plao
		if(count==0)
			break;
		while(!Level.empty())//push CPE1 for find linedata of CPE1
		{
			PrintQ.push(Level.front());
			Level.pop();
		}
		cout<<endl;	
	}
}
