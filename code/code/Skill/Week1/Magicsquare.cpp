#include<iostream>

using namespace std;

int main()
{
	int n,tmp,row=0,col=0,check=0,x1=0,x2=0,c=0;
    int a[100][100];
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>tmp;
            if(tmp<=(n*n))
            {
                a[i][j]=tmp;
            } 
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            row = row+a[i][j];
            col = col+a[j][i];
        }
        if(i==0) 
        {
            check=row;
        }
        else
        {
            if(check!=row || check!=col) 
            { 
                cout<<"No";
                c++;
                break;
            }
        }
        x1 = x1+a[i][i];
        x2 = x2+a[i][(n-1)-i]; 
        row=0;col=0;
    }
    if(check!=x1 || check!=x2) 
    { 
        if(c==0)
        {
            cout<<"No";
            c++;
        }
    }
    if(c==0)
    	cout<<"Yes";
}
