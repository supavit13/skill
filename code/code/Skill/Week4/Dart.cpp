#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,x,y,sum=0;
	float z;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		x=abs(x);
		y=abs(y);
		//cout<<x<<" "<<y<<endl;
		z=sqrt((x*x)+(y*y));
		//cout<<z<<endl;
		if(z<=2)
			sum=sum+5;
		if(z>2&&z<=4)
			sum=sum+4;
		if(z>4&&z<=6)
			sum=sum+3;
		if(z>6&&z<=8)
			sum=sum+2;
		if(z>8&&z<=10)
			sum=sum+1;
		if(z>10)
			sum=sum+0;			
	}
	cout<<sum;
}
