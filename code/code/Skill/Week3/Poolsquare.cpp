#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int a,b,have,count=0;;
    while(1)
    {
		have=0;
        cin>>a>>b;     
        if(a==0&&b==0)
           return 0;
        for(int i=2;i<b;i++)
        {
           int x=((i*(i+1))/2)+1;
           if(x>a&&x<b)
           {
				int y=sqrt(x);
        		if(y*y==x)
        		{
        			have++;
        			//cout<<x<<endl;
				}
		   }
		   else if(x>b)
		   	break;
          
        }
        count++;
        cout<<"Case "<<count<<": "<<have<<endl;
    }
}
