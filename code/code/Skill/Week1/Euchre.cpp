#include<iostream>

using namespace std;

int main()
{
	int table[6],tmp=0,tmp1=0,a[1000],b[1000],count=0,j=0,c=0;
	while(c!=1)
	{
		for(int i=0;i<6;i++)
		{
			cin>>table[i];	
		}
		if((table[0]&&table[1]&&table[2]&&table[3]&&table[4]&&table[5])!=0)
		{
			/*tmp=table[0]-table[1];
			tmp=tmp+table[2]-table[3];
			tmp=tmp+table[4]-table[5];*/
			tmp1=table[0]+table[1];
			tmp=(table[0]+table[2]+table[4])-(table[1]+table[3]+table[5]);
			for(int i=1;i<tmp1;i++)
			{
				if(i+(i+tmp)==tmp1)
				{
					a[j]=i;
					b[j]=i+tmp;
					j++;
					count++;	
				}
			}
		}
		else
		{
			for(int i=0;i<count;i++)
			{
				cout<<"Anna's won-loss record is "<< a[i] << "-" << b[i] <<"."<<endl;
				c=1;
			}	
		}
	}
	
}
