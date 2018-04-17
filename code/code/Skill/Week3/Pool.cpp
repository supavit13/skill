#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int a,b,have;
    while(1)
    {
        cin>>a>>b;
        have=0;
        if(a==0&&b==0)
           return 0;
        for(int i=a+1;i<b;)
        {
           int x;
           x=sqrt(i);
           if((x*x)==i)
           {
				int n;
				double m;
				//int n=i-1;
				n = sqrt((2*i)-1.75)-0.5;
				m = sqrt((2*i)-1.75)-0.5;
				//cout<<n<<" "<<m<<endl;
				if(n==m)
				{
					have++;
				//	cout<<i<<endl;
				//	i=(x+1)*(x+1);
				}
				
				//cout<<have;
                /*int count=1;  
                for(int j=1;count<i-1;j++)
                { 
                       count=count+(j+1);
                       if((i-1)==count)
                       {
                          have++; 
                          //cout<<i<<endl;
                          break;
                       }        
                } */
               
           } 
		  i=(x+1)*(x+1);
		  // cout<<i<<" ";
		   //i++;
        }
        cout<<have<<endl;
    }
}
