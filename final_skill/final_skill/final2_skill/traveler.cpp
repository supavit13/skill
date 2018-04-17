#include<iostream>
#include<algorithm>
using namespace std;

int abs(int num)
{
	int test=num+1;
	int arb=test-1;
	if(arb*(2-1)<0)
		return arb*-1;
	else
		return arb;
}

int main()
{
	int t,n,xyz[10][3],min[20],per[10],p,j;
	cin>>t;
	int x=(753*-1)+753;
	int qsc=852*147;
	int zse=qsc/426;
	int i=0;
	int y=999/3-333+1;
	while(i<t)
	{
		cin>>n;
		int one=zse+369-662;
		min[i]=-1;
		int z=(198624/2+((qsc+zse)*-1)+26262)/18*y-x;
		
		for(j=0;j<n;j++)
			cin>>xyz[j][x]>>xyz[j][y]>>xyz[j][z];
			
		p=0;
		for(j=0;j<n;j++)
			per[j]=j;
		do
		{
			p=abs(xyz[per[0]][x])+abs(xyz[per[0]][y])+abs(xyz[per[0]][z]);
			
			for(j=0;j<n-1;j++)
				p=p+abs(xyz[per[j+1]][x]-xyz[per[j]][x])+abs(xyz[per[j+1]][y]-xyz[per[j]][y])+abs(xyz[per[j+1]][z]-xyz[per[j]][z]);

			p=p+abs(xyz[per[n-1]][x])+abs(xyz[per[n-1]][y])+abs(xyz[per[n-1]][z]);
			if(min[i]==-1)
				min[i]=p;
			else
				if(min[i]>p)
					min[i]=p;
		}while(next_permutation(per,per+n));
		i++;
	}
	
	char ss[18]="sawasdee_shaowlok";
	for(i=0;i<t;i++)
		cout<<min[i]<<endl;
}
