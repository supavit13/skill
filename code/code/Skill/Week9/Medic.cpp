#include<iostream>

using namespace std;

int main()
{
	int field[8][8]={0};
	int row[8],column[8],diagonalleft[15],diagonalright[15];
	int n,x,y;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		field[y-1][x-1]=1;
	}
	
	/////////check row///////
	int r=0;
	for(int i=0;i<8;i++)
	{
		int count=0;
		for(int j=0;j<8;j++)
		{
			if(field[i][j]==1)
				count++;
		}
		row[r++]=count;
		
	}
	/////////check column///////
	int c=0;
	for(int i=0;i<8;i++)
	{
		int count=0;
		for(int j=0;j<8;j++)
		{
			if(field[j][i]==1)
				count++;
		}
		column[c++]=count;
		
	}
	/////////check diagonalleft/////
	int count=0;
	if(field[7][0]==1)
		count++;
	diagonalleft[0]=count;
	
	count=0;
	if(field[6][0]==1)
		count++;
	if(field[7][1]==1)
		count++;
	diagonalleft[1]=count;
	
	count=0;
	if(field[5][0]==1)
		count++;
	if(field[6][1]==1)
		count++;
	if(field[7][2]==1)
		count++;
	diagonalleft[2]=count;
	
	count=0;
	if(field[4][0]==1)
		count++;
	if(field[5][1]==1)
		count++;
	if(field[6][2]==1)
		count++;
	if(field[7][3]==1)
		count++;
	diagonalleft[3]=count;
	
	int z=0;
	count=0;
	for(int i=3;i<8;i++)
	{
		if(field[i][z]==1)
		 	count++;
		z++;
	}
	diagonalleft[4]=count;
	
	z=0;
	count=0;
	for(int i=2;i<8;i++)
	{
		if(field[i][z]==1)
		 	count++;
		z++;
	}
	diagonalleft[5]=count;
	
    z=0;
	count=0;
	for(int i=1;i<8;i++)
	{
		if(field[i][z]==1)
		 	count++;
		z++;
	}
	diagonalleft[6]=count;
	
	z=0;
	count=0;
	for(int i=0;i<8;i++)
	{
		if(field[i][z]==1)
		 	count++;
		z++;
	}
	diagonalleft[7]=count;
	
	z=0;
	count=0;
	for(int i=1;i<8;i++)
	{
		if(field[z][i]==1)
		 	count++;
		z++;
	}
	diagonalleft[8]=count;
	
	z=0;
	count=0;
	for(int i=2;i<8;i++)
	{
		if(field[z][i]==1)
		 	count++;
		z++;
	}
	diagonalleft[9]=count;
	
	z=0;
	count=0;
	for(int i=3;i<8;i++)
	{
		if(field[z][i]==1)
		 	count++;
		z++;
	}
	diagonalleft[10]=count;
	
	z=0;
	count=0;
	for(int i=4;i<8;i++)
	{
		if(field[z][i]==1)
		 	count++;
		z++;
	}
	diagonalleft[11]=count;
	
	count=0;
	if(field[0][5]==1)
		count++;
	if(field[1][6]==1)
		count++;
	if(field[2][7]==1)
		count++;
	diagonalleft[12]=count;
	
	
	
	count=0;
	if(field[0][6]==1)
		count++;
	if(field[1][7]==1)
		count++;
	diagonalleft[13]=count;
	
	count=0;
	if(field[0][7]==1)
		count++;
	diagonalleft[14]=count;
	
	/////////check diagonalleft/////
	count=0;
	if(field[0][0]==1)
		count++;
	diagonalright[0]=count;
	
	count=0;
	if(field[1][0]==1)
		count++;
	if(field[0][1]==1)
		count++;
	diagonalright[1]=count;
	
	count=0;
	if(field[2][0]==1)
		count++;
	if(field[1][1]==1)
		count++;
	if(field[0][2]==1)
		count++;
	diagonalright[2]=count;
	
	count=0;
	if(field[3][0]==1)
		count++;
	if(field[2][1]==1)
		count++;
	if(field[1][2]==1)
		count++;
	if(field[0][3]==1)
		count++;
	diagonalright[3]=count;
	
	count=0;
	y=0;
	for(int i=4;i>=0;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[4]=count;
	
	count=0;
	y=0;
	for(int i=5;i>=0;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[5]=count;
	
	count=0;
	y=0;
	for(int i=6;i>=0;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[6]=count;
	
	count=0;
	y=0;
	for(int i=7;i>=0;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[7]=count;
	
	count=0;
	y=1;
	for(int i=7;i>=1;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[8]=count;
	
	count=0;
	y=2;
	for(int i=7;i>=2;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[9]=count;
	
	count=0;
	y=3;
	for(int i=7;i>=3;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[10]=count;
	
	count=0;
	y=4;
	for(int i=7;i>=4;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[11]=count;
	
	count=0;
	y=5;
	for(int i=7;i>=5;i--)
	{
		if(field[i][y]==1)
			count++;
		y++;
	}
	diagonalright[12]=count;
	
	count=0;
	if(field[7][6]==1)
		count++;
	if(field[6][7]==1)
		count++;
	diagonalright[13]=count;
	
	count=0;
	if(field[7][7]==1)
		count++;
	diagonalright[14]=count;
	
	int mincount=0;
	for(int i=0;i<8;i++)
	{
		if(row[i]!=0)
			mincount++;	
	}
	int count1=0;
	for(int i=0;i<8;i++)
	{
		if(column[i]!=0)
			count1++;	
	}
	if(count1<mincount)
		mincount=count1;
		
	int count2=0;
	for(int i=0;i<15;i++)
	{
		if(diagonalleft[i]!=0)
			count2++;	
	}
	if(count2<mincount)
		mincount=count2;
	
	int count3=0;
	for(int i=0;i<15;i++)
	{
		if(diagonalright[i]!=0)
			count3++;	
	}
	if(count3<mincount)
		mincount=count3;
		
	for(int i=0;i<8;i++)
		cout<<row[i]<<" ";
	cout<<endl;
	for(int i=0;i<8;i++)
		cout<<column[i]<<" ";
	cout<<endl;	
	for(int i=0;i<15;i++)
		cout<<diagonalleft[i]<<" ";
	cout<<endl;	
	for(int i=0;i<15;i++)
		cout<<diagonalright[i]<<" ";
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<field[i][j]<<" ";	
		
		}
		cout<<endl;
	}
	cout<<mincount<<endl;
}
