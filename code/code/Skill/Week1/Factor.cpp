#include<iostream>

using namespace std;

int fac(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            cout << i << endl;
            n=n/i;
            return fac(n); 
        }
    }
    return n;
}

int main()
{
	int n;
	cin>>n;
	n=fac(n);
	if(n==1)
		cout << "0" << endl;
}
