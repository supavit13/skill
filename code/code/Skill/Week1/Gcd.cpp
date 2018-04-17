#include<iostream>

using namespace std;

int gcd(int a,int b)
{
        if(a==0)
        	return b;
        else
        	return gcd(b%a,a);        
}

int main()
{
	int n,a,b;
	cin>> n;
	cin>> a;
	for(int i=1;i<n;i++){
		cin>>b;
		a=gcd(a,b);
	}
	cout<< a << endl;
}
