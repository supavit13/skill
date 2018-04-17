#include<iostream>

using namespace std;

int main()
{
	int a[8],table[8][8],row=0,c=0,count=0;
	for(int i=0;i<8;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			table[i][j]=0;
	
	for(int i=0;i<8;i++)
    {
        int j=0;
        while(j<a[i]-1)
        {
             j++;
        }
        table[j][i]=1;
    }
    
    for(int i=0;i<8;i++)
    {
         row = 0;
        for(int j=0;j<8;j++) 
        { 
            row+= table[i][j];
            c=0;
            for(int k=0;k<8-j-i;k++)
            {
                if(table[i+k][j+k]==1)
                c+= table[i+k][j+k]; 
            }
            if(c>1)
                count=1;
            else if(row>1)
                count=1;
        }
    }
    if(count==1)
    	cout<<"Invalid";
    else
      	cout<<"Valid";
}
