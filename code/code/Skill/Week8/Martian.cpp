#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	string S1,S2,Sum;
	cin>>S1;
	cin>>S2;
	cin>>Sum;
	int p1,p2,p3,check=0,result1,result2,result3;
	for(int i=2;i<=36;i++)
	{
		result1=0;
		result2=0;
		result3=0;
		p1=0;
		for(int j=S1.size()-1;j>=0;j--)
		{
			if(S1[j]>=48 && S1[j]<=57)
			{
				result1=result1+((S1[j]-48)*pow(i,p1));
				p1++;
			}
			else if(S1[j]>=65 && S1[j]<=90)
			{
				result1=result1+((S1[j]-55)*pow(i,p1));
				p1++;
			}
		}
		p2=0;
		for(int j=S2.size()-1;j>=0;j--)
		{
			if(S2[j]>=48 && S2[j]<=57)
			{
				result2=result2+((S2[j]-48)*pow(i,p2));
				p2++;
				//cout<<result2<<endl;
			}
			else if(S2[j]>=65 && S2[j]<=90)
			{
				result2=result2+((S2[j]-55)*pow(i,p2));
				p2++;
				//cout<<result2<<endl;
			}
		}
		p3=0;
		for(int j=Sum.size()-1;j>=0;j--)
		{
			if(Sum[j]>=48 && Sum[j]<=57)
			{
				result3=result3+((Sum[j]-48)*pow(i,p3));
				p3++;
			}
			else if(Sum[j]>=65 && Sum[j]<=90)
			{
				result3=result3+((Sum[j]-55)*pow(i,p3));
				p3++;
			}
		}
		if(result1+result2==result3)
		{
			cout<<i;
			check=1;
			break;
		}
	}
	if(check==0)
		cout<<"no";
	//cout<<result1<<" "<<result2<<" "<<result3<<endl;
//	cout<<endl;
//	cout<<S2;
	
	//cout<<S1.size();
}
