#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s,a,b;
	int i,j;
	vector<string> k,l,m,n;
	cin>>s;
	while(a != "#" && b != "#")
	{
		k.push_back(a);
		l.push_back(b);
		cin>>a>>b;
	}
	cout<<s<<endl;
	m.push_back(s);
	for(i=0;i<m.size();i++)
	{
        for(j=0;j<l.size();j++)
        {
            if(l[j] == m[i])
                n.push_back(k[j]);
        }
        sort(n.begin(), n.end());
        for(j=0;j<n.size();j++)
        {
            cout<<"("<<m[i]<<")"<<n[j]<<" ";
            m.push_back(n[j]);
        }
        cout<<endl;
		n.clear();
	}
}
