#include<iostream>

using namespace std;
int m,n,a,b;	
char area[100][100];
int main()
{
	string x;
    while(1)
	{
        cin>>m>>n;	
        if(m==0&&n==0)
		{
			return 0;
		}
    	for(int i=0;i<m;i++)
    	{
    		cin>>x;
    		for(int j=0;j<n;j++)
    		{
    			area[i][j]=x[j];
    		}
    	}
    	cin>>a>>b;
	    area[a-1][b-1]='W';	
		    
		  ///////////////Go/////////////
      for(int k=0;k<m*n;k++)
		  for(int i=0;i<m;i++)
		  {
				for(int j=0;j<n;j++)
				{
				   if(area[i][j]=='W')
				   {
							if(area[i][j-1]=='D')
								area[i][j-1]='W';
							if(area[i][j+1]=='D')
							    area[i][j+1]='W';
							if(area[i-1][j]=='D')
							    area[i-1][j]='W';
							if(area[i-1][j-1]=='D')
							    area[i-1][j-1]='W';
							if(area[i-1][j+1]=='D')
							    area[i-1][j+1]='W';
							if(area[i+1][j]=='D')
							    area[i+1][j]='W';
							if(area[i+1][j+1]=='D')
							    area[i+1][j+1]='W';
							if(area[i+1][j-1]=='D')
								area[i+1][j-1]='W';
					}
							
				}
		}
		///////////////////END Go////////////////////////
					
    	for(int i=0;i<m;i++)
       	{
        	for(int j=0;j<n;j++)
        	{
        		cout<<area[i][j];
        	}
        	cout<<endl;
       	}	
	
  }
}
