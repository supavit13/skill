#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string s;
	int i,j,count,arr[26],k=1;
	while(1)
	{
		cin>>s;
		count = 0;
		if(s == "end")
			break;
		arr[0] = s[0];
		for(i=1;i<s.size();i++)
		{
			bool check = true;
			for(j=0;j<=count;j++)
			{
				if(arr[j] >= s[i])
				{
					arr[j] = s[i];
					check = false;
					break;
				}
			}
			if(check)
			    arr[++count] = s[i];
		}
		cout<<"Case "<<k++<<": "<<count+1<<endl;
	}
}
