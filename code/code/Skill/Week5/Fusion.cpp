#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
vector <int> Power;

int main()
{
	int P,n;
	cin>>P;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
        cin>>x;
        Power.push_back(x);
    }
	sort(Power.begin(),Power.end())	;
	int count=0,sum=0;
	for(int i=Power.size()-1;i>=0;i--)
	{
        sum=sum+Power[i];
        count++;
        if(sum>=P)
            break;
        
        //cout<<Power[i]<<endl;
    }
    if(sum<P)
        cout<<"0";
    else
        cout<<count;
/*	for(int i=0;i<n;i++)
		cout<<Power[i]<<endl;	*/
//	system("pause");
}
