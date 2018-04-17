#include<iostream>

using namespace std;

int main()
{
	int n,count,mincount=0;
	cin>>n;
	int field[8][8]={0};
	int x,y,max1,max2,max3;
	
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		field[y-1][x-1]=1;
	}
	while(1)
	{
		max1=0;
		max2=0;
		max3=0;
		
		for(int i=0;i<8;i++)
		{
		    count=0;
			for(int j=0;j<8;j++)
			{
				if(field[j][i]==1)
					count++;
			}
			if(count>max1)
			{
				max1=count;
				max2=2;
				max3=i;
			}
		}
		
		for(int i=0;i<8;i++)
		{
		    count=0;
			for(int j=0;j<8;j++)
			{
				if(field[i][j]==1)
					count++;
			}
			if(count>max1)
			{
				max1=count;
				max2=1;
				max3=i;
			}
		}
		int z;
		for(int i=0;i<15;i++)
		{
			count=0;
			if(i==0)
			{
				if(field[7][0]==1)
					count++;
			}
			else if(i==1)
			{
				if(field[6][0]==1)
					count++;
				if(field[7][1]==1)
					count++;
			}
			else if(i==2)
			{
				if(field[5][0]==1)
					count++;
				if(field[6][1]==1)
					count++;
				if(field[7][2]==1)
					count++;
			}
			else if(i==3)
			{
				if(field[4][0]==1)
					count++;
				if(field[5][1]==1)
					count++;
				if(field[6][2]==1)
					count++;
				if(field[7][3]==1)
					count++;
			}
			else if(i==4)
			{
				z=0;
				for(int i=3;i<8;i++)
				{
					if(field[i][z]==1)
					 	count++;
					z++;
				}
			}
			else if(i==5)
			{
				z=0;
				for(int i=2;i<8;i++)
				{
					if(field[i][z]==1)
					 	count++;
					z++;
				}
			}
			else if(i==6)
			{
				z=0;
				for(int i=1;i<8;i++)
				{
					if(field[i][z]==1)
					 	count++;
					z++;
				}
			}
			else if(i==7)
			{
				z=0;
				for(int i=0;i<8;i++)
				{
					if(field[i][z]==1)
					 	count++;
					z++;
				}
			}
			else if(i==8)
			{
				z=0;
				for(int i=1;i<8;i++)
				{
					if(field[z][i]==1)
					 	count++;
					z++;
				}
			}
			else if(i==9)
			{
				z=0;
				for(int i=2;i<8;i++)
				{
					if(field[z][i]==1)
					 	count++;
					z++;
				}
			}
			else if(i==10)
			{
				z=0;
				for(int i=3;i<8;i++)
				{
					if(field[z][i]==1)
					 	count++;
					z++;
				}
			}
			else if(i==11)
			{
				z=0;
				for(int i=4;i<8;i++)
				{
					if(field[z][i]==1)
					 	count++;
					z++;
				}
			}
			else if(i==12)
			{
				if(field[0][5]==1)
					count++;
				if(field[1][6]==1)
					count++;
				if(field[2][7]==1)
					count++;
			}
			else if(i==13)
			{
				if(field[0][6]==1)
					count++;
				if(field[1][7]==1)
					count++;
			}
			else
			{
				if(field[0][7]==1)
				count++;
			}
			if(count>max1)
			{
				max1=count;
				max2=3;
				max3=i;
			}
		}
		int y;
		for(int i=0;i<15;i++)
		{
			count=0;
			if(i==0)
			{
				if(field[0][0]==1)
					count++;
			}
			else if(i==1)
			{
				if(field[1][0]==1)
					count++;
				if(field[0][1]==1)
					count++;
			}
			else if(i==2)
			{
				if(field[2][0]==1)
					count++;
				if(field[1][1]==1)
					count++;
				if(field[0][2]==1)
					count++;
			}
			else if(i==3)
			{
				if(field[3][0]==1)
					count++;
				if(field[2][1]==1)
					count++;
				if(field[1][2]==1)
					count++;
				if(field[0][3]==1)
					count++;
			}
			else if(i==4)
			{
				y=0;
				for(int i=4;i>=0;i--)
				{
					if(field[i][y]==1)
						count++;
					y++;
				}
			}
			else if(i==5)
			{
				y=0;
				for(int i=5;i>=0;i--)
				{
					if(field[i][y]==1)
						count++;
					y++;
				}
			}
			else if(i==6)
			{
				y=0;
				for(int i=6;i>=0;i--)
				{
					if(field[i][y]==1)
						count++;
					y++;
				}
			}
			else if(i==7)
			{
				y=0;
				for(int i=7;i>=0;i--)
				{
					if(field[y][i]==1)
						count++;
					y++;
				}
			}
			else if(i==8)
			{
				y=1;
				for(int i=7;i>=1;i--)
				{
					if(field[y][i]==1)
						count++;
					y++;
				}
			}
			else if(i==9)
			{
				y=2;
				for(int i=7;i>=2;i--)
				{
					if(field[y][i]==1)
						count++;
					y++;
				}
			}
			else if(i==10)
			{
				y=3;
				for(int i=7;i>=3;i--)
				{
					if(field[y][i]==1)
						count++;
					y++;
				}
			}
			else if(i==11)
			{
				y=4;
				for(int i=7;i>=4;i--)
				{
					if(field[y][i]==1)
						count++;
					y++;
				}
			}
			else if(i==12)
			{
				y=5;
				for(int i=7;i>=5;i--)
				{
					if(field[y][i]==1)
						count++;
					y++;
				}
			}
			else if(i==13)
			{
				if(field[7][6]==1)
					count++;
				if(field[6][7]==1)
					count++;
			}
			else
			{
				if(field[7][7]==1)
				count++;
			}
			if(count>max1)
			{
				max1=count;
				max2=4;
				max3=i;
			}
		}
		if(max1==0)
			break;
		else
		{
			mincount++;
			if(max2==1)
			{
				for(int i=0;i<8;i++)
					field[max3][i]=0;
			}
			else if(max2==2)
			{
				for(int i=0;i<8;i++)
					field[i][max3]=0;
			}
			else if(max2==3)
			{
				if(max3==0)
				{
					field[7][0]==0;
				}
				else if(max3==1)
				{
					field[6][0]==0;
					field[7][1]==0;
				}
				else if(max3==2)
				{
					field[5][0]==0;
					field[6][1]==0;
					field[7][2]==0;
				}
				else if(max3==3)
				{
					field[4][0]==0;
					field[5][1]==0;
					field[6][2]==0;
					field[7][3]==0;
				}
				else if(max3==4)
				{
					for(int i=0;i<5;i++)
						field[i+3][i]=0;
				}
				else if(max3==5)
				{
					for(int i=0;i<6;i++)
						field[i+2][i]=0;
				}
				else if(max3==6)
				{
					for(int i=0;i<7;i++)
						field[i+1][i]=0;
				}
				else if(max3==7)
				{
					for(int i=0;i<8;i++)
						field[i][i]=0;
				}
				else if(max3==8)
				{
					for(int i=0;i<7;i++)
						field[i][i+1]=0;
				}
				else if(max3==9)
				{
					for(int i=0;i<6;i++)
						field[i][i+2]=0;
				}
				else if(max3==10)
				{
					for(int i=0;i<5;i++)
						field[i][i+3]=0;
				}
				else if(max3==11)
				{
					for(int i=0;i<4;i++)
						field[i][i+4]=0;
				}
				else if(max3==12)
				{
					field[0][5]==0;
					field[1][6]==0;
					field[2][7]==0;
				}
				else if(max3==13)
				{
					field[0][6]==0;
					field[1][7]==0;
				}
				else
				{
					field[0][7]==0;
				}
			}
			
			else if(max2==4)
			{
				if(max3==0)
				{
					field[0][0]==0;
				}
				else if(max3==1)
				{
					for(int i=0;i<2;i++)
						field[i][1-i]=0;
				}
				else if(max3==2)
				{
					for(int i=0;i<3;i++)
						field[i][2-i]=0;
				}
				else if(max3==3)
				{
					for(int i=0;i<4;i++)
						field[i][3-i]=0;
				}
				else if(max3==4)
				{
					for(int i=0;i<5;i++)
						field[i][4-i]=0;
				}
				else if(max3==5)
				{
					for(int i=0;i<6;i++)
						field[i][5-i]=0;
				}
				else if(max3==6)
				{
					for(int i=0;i<7;i++)	
						field[i][6-i]=0;
				}
				else if(max3==7)
				{
					for(int i=0;i<8;i++)
						field[i][7-i]=0;
				}
				else if(max3==8)
				{
					for(int i=0;i<7;i++)
						field[i+1][7-i]=0;
				}
				else if(max3==9)
				{
					for(int i=0;i<6;i++)
						field[i+2][7-i]=0;
				}
				else if(max3==10)
				{
					for(int i=0;i<5;i++)
						field[i+3][7-i]=0;
				}
				else if(max3==11)
				{
					for(int i=0;i<4;i++)
						field[i+4][7-i]=0;
				}
				else if(max3==12)
				{
					for(int i=0;i<3;i++)
						field[i+5][7-i]=0;
				}
				else if(max3==13)
				{
					for(int i=0;i<2;i++)
						field[i+6][7-i]=0;
				}
				else
				{
					for(int i=0;i<1;i++)
						field[i+7][7-i]=0;
				}
			}
		}	
	}
	cout<<mincount;
	/*for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<field[i][j]<<" ";	
		
		}
		cout<<endl;
	}*/
}
