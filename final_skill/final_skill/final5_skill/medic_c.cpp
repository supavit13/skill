#include <iostream>
using namespace std;

int main()
{
	int n,i,a[64],b[64],c[8][8]={0},x[3],cnt,j,y=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
		c[a[i]][b[i]] = 1;
	}
	
	while(1)
	{
		x[0] = 0;
		x[1] = 0;
		x[2] = 0;
		for(i=0;i<8;i++)
		{
			cnt = 0;
			for(j=0;j<8;j++)
				if(c[i][j] == 1)
					cnt++;

			if(cnt > x[0])
			{
				x[0] = cnt;
				x[1] = 1;
				x[2] = i;
			}
		}
		
		for(i=0;i<8;i++)
		{
			cnt = 0;
			for(j=0;j<8;j++)
				if(c[j][i] == 1)
					cnt++;

			if(cnt > x[0])
			{
				x[0] = cnt;
				x[1] = 2;
				x[2] = i;
			}
		}
		
		for(i=0;i<15;i++)
		{
			cnt=0;
			switch(i)
			{
				case 0: for(j=0;j<1;j++)if(c[j+7][j] == 1)cnt++;break;
				case 1: for(j=0;j<2;j++)if(c[j+6][j] == 1)cnt++;break;
				case 2: for(j=0;j<3;j++)if(c[j+5][j] == 1)cnt++;break;
				case 3: for(j=0;j<4;j++)if(c[j+4][j] == 1)cnt++;break;
				case 4: for(j=0;j<5;j++)if(c[j+3][j] == 1)cnt++;break;
				case 5: for(j=0;j<6;j++)if(c[j+2][j] == 1)cnt++;break;
				case 6: for(j=0;j<7;j++)if(c[j+1][j] == 1)cnt++;break;
				case 7: for(j=0;j<8;j++)if(c[j][j] == 1)cnt++;break;
				case 8: for(j=0;j<7;j++)if(c[j][j+1] == 1)cnt++;break;
				case 9: for(j=0;j<6;j++)if(c[j][j+2] == 1)cnt++;break;
				case 10: for(j=0;j<5;j++)if(c[j][j+3] == 1)cnt++;break;
				case 11: for(j=0;j<4;j++)if(c[j][j+4] == 1)cnt++;break;
				case 12: for(j=0;j<3;j++)if(c[j][j+5] == 1)cnt++;break;
				case 13: for(j=0;j<2;j++)if(c[j][j+6] == 1)cnt++;break;
				case 14: for(j=0;j<1;j++)if(c[j][j+7] == 1)cnt++;break;
			}
			if(cnt > x[0])
			{
				x[0] = cnt;
				x[1] = 3;
				x[2] = i;
			}
		}
		for(i=0;i<15;i++)
		{
			cnt=0;
			switch(i)
			{
				case 0: for(j=0;j<1;j++)if(c[j][j] == 1)cnt++;break;
				case 1: for(j=0;j<2;j++)if(c[j][1-j] == 1)cnt++;break;
				case 2: for(j=0;j<3;j++)if(c[j][2-j] == 1)cnt++;break;
				case 3: for(j=0;j<4;j++)if(c[j][3-j] == 1)cnt++;break;
				case 4: for(j=0;j<5;j++)if(c[j][4-j] == 1)cnt++;break;
				case 5: for(j=0;j<6;j++)if(c[j][5-j] == 1)cnt++;break;
				case 6: for(j=0;j<7;j++)if(c[j][6-j] == 1)cnt++;break;
				case 7: for(j=0;j<8;j++)if(c[j][7-j] == 1)cnt++;break;
				case 8: for(j=0;j<7;j++)if(c[j+1][7-j] == 1)cnt++;break;
				case 9: for(j=0;j<6;j++)if(c[j+2][7-j] == 1)cnt++;break;
				case 10: for(j=0;j<5;j++)if(c[j+3][7-j] == 1)cnt++;break;
				case 11: for(j=0;j<4;j++)if(c[j+4][7-j] == 1)cnt++;break;
				case 12: for(j=0;j<3;j++)if(c[j+5][7-j] == 1)cnt++;break;
				case 13: for(j=0;j<2;j++)if(c[j+6][7-j] == 1)cnt++;break;
				case 14: for(j=0;j<1;j++)if(c[j+7][7-j] == 1)cnt++;break;
			}
			if(cnt > x[0])
			{
				x[0] = cnt;
				x[1] = 4;
				x[2] = i;
			}
		}
		
		if(x[0] == 0)
			break;
			
		else
		{
			y++;
			switch(x[1])
			{
				case 1:
				{
					for(i=0;i<8;i++)
							c[x[2]][i] = 0;
				};break;
				
				case 2:
				{
					for(i=0;i<8;i++)
						c[i][x[2]] = 0;
				};break;
				
				case 3:
				{
					switch(x[2])
					{
						case 0: for(i=0;i<1;i++)c[i+7][i] = 0;break;
						case 1: for(i=0;i<2;i++)c[i+6][i] = 0;break;
						case 2: for(i=0;i<3;i++)c[i+5][i] = 0;break;
						case 3: for(i=0;i<4;i++)c[i+4][i] = 0;break;
						case 4: for(i=0;i<5;i++)c[i+3][i] = 0;break;
						case 5: for(i=0;i<6;i++)c[i+2][i] = 0;break;
						case 6: for(i=0;i<7;i++)c[i+1][i] = 0;break;
						case 7: for(i=0;i<8;i++)c[i][i] = 0;break;
						case 8: for(i=0;i<7;i++)c[i][i+1] = 0;break;
						case 9: for(i=0;i<6;i++)c[i][i+2] = 0;break;
						case 10: for(i=0;i<5;i++)c[i][i+3] = 0;break;
						case 11: for(i=0;i<4;i++)c[i][i+4] = 0;break;
						case 12: for(i=0;i<3;i++)c[i][i+5] = 0;break;
						case 13: for(i=0;i<2;i++)c[i][i+6] = 0;break;
						case 14: for(i=0;i<1;i++)c[i][i+7] = 0;break;
					}
				};break;
				
				case 4:
				{
					switch(x[2])
					{
						case 0: for(i=0;i<1;i++)c[i][i] = 0;break;
						case 1: for(i=0;i<2;i++)c[i][1-i] = 0;break;
						case 2: for(i=0;i<3;i++)c[i][2-i] = 0;break;
						case 3: for(i=0;i<4;i++)c[i][3-i] = 0;break;
						case 4: for(i=0;i<5;i++)c[i][4-i] = 0;break;
						case 5: for(i=0;i<6;i++)c[i][5-i] = 0;break;
						case 6: for(i=0;i<7;i++)c[i][6-i] = 0;break;
						case 7: for(i=0;i<8;i++)c[i][7-i] = 0;break;
						case 8: for(i=0;i<7;i++)c[i+1][7-i] = 0;break;
						case 9: for(i=0;i<6;i++)c[i+2][7-i] = 0;break;
						case 10: for(i=0;i<5;i++)c[i+3][7-i] = 0;break;
						case 11: for(i=0;i<4;i++)c[i+4][7-i] = 0;break;
						case 12: for(i=0;i<3;i++)c[i+5][7-i] = 0;break;
						case 13: for(i=0;i<2;i++)c[i+6][7-i] = 0;break;
						case 14: for(i=0;i<1;i++)c[i+7][7-i] = 0;break;
					}
				};break;
			}
		}
	}
	cout<<y<<endl;
}
