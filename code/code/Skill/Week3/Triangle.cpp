#include<iostream>

using namespace std;

int main()
{   
    while(1)
    {    
        int n,count=1,index=0;  
        cin>>n;
        for(int i=1;count<n;i++)
        {
               //cout<<count<<" "; 
               count=count+(i+1);
               if(n==count)
               {
                  index=i+1; 
                  break;
               }        
        }
        if(n==0)
                return 0;
        if(n==1)
                cout<<"1"<<endl;
        else if(index==0)
                cout<<"bad"<<endl;
        else
            cout<<index<<endl;
    }
    //system("pause");
}
