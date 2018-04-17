#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int value(char c)
{
	if(c >= '0' && c <= '9')
		return c - 48;
	else if(c >= 'A' && c <= 'Z')
		return c - 55;
	return 0;
}

int minimumBase(string s)
{
	char max = '0';
	for(unsigned int i=0;i<s.length();i++)
	{
		if(s[i] > max)
		    max = s[i];
	}
	return value(max) + 1;
}

int stoi(string s, int i, int base)
{
	if(i >= s.length())
		return 0;
	return value(s[i]) * pow((float)base, (int)s.length() - 1 - i) + stoi(s, i + 1, base);
}

int main() 
{
	string a,b,c;
	cin>>a>>b>>c;

	int i;
	int minBase = minimumBase(a + b + c);
	for(i=minBase;i<=36;i++) 
	{
		if(stoi(a, 0, i) + stoi(b, 0, i) == stoi(c, 0, i))
			break;
	}

	if(i == 37)
		cout<<"no";
	else
		cout<<i;
}
