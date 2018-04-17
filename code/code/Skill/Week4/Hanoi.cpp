#include<iostream>
#include<cmath>

using namespace std;

char hanoi[4500][3];
int num[4500];
int i=0;
void move(int n,char a,char b,char c)
{
	if(n==1)
	{
		//cout<<"Move "<<n<<" from "<<a<<" to "<<c<<endl;
		num[i]=n;
		hanoi[i][1]=a;
		hanoi[i][2]=c;
		i++;
	}
	else
	{
		move(n-1,a,c,b);
		//cout<<"Move "<<n<<" from "<<a<<" to "<<c<<endl;
		num[i]=n;
		hanoi[i][1]=a;
		hanoi[i][2]=c;
		i++;
		move(n-1,b,a,c);
	}
}

int main()
{
	int n;
	cin>>n;
	char a='A',b='B',c='C';
	move(n,a,b,c);
	for(int i=0;i<pow(2,n)-1;i++)
	{
		cout<<"Move "<<num[i]<<" from "<<hanoi[i][1]<<" to "<<hanoi[i][2]<<endl;
	}
}

