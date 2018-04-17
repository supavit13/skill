#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0) 
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * (b / gcd(a, b));
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	int paint,varnish,paint_v,varnish_p;
	varnish = k / lcm(n + 1, m + 1);
	paint_v = k / (m + 1) - varnish;
	varnish_p = k / (n + 1) - varnish;
	paint = k - paint_v - varnish_p - varnish;

	cout<<paint<<" "<<varnish<<" "<<paint_v<<" "<<varnish_p;
}
