#include<iostream>
#include <algorithm> 
#include <vector>

using namespace std;
vector<int> fish;
vector<int> fishhalf;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
          int x;
          cin>>x;
          fish.push_back(x);  
    }
    sort(fish.begin(),fish.end());
    int size=fish.size()/2;
    //cout<<size<<endl;
    for(int i=size;i<n;i++)
    {
          fishhalf.push_back(fish[i]);
    }
    for(int i=0;i<size;i++)
    {
          fishhalf.push_back(fish[i]);
    }
    for(int i=0;i<n;i++)
    {
          int f=fishhalf[i]/2;
          int ff=fish[i]/2;
          for(int j=0;j<n;j++)
          {
                if((f)>=fishhalf[j])
                {
                       f=f-fishhalf[j];
                       fishhalf[j]=0;            
                } 
				if((ff)>=fish[j])
                {
                       ff=ff-fish[j];
                       fish[j]=0;            
                }  
          }
    }
    int count=0,counter=0;
    for(int i=0;i<n;i++)
    {
            //cout<<fishhalf[i]<<" ";
            if(fishhalf[i]!=0)
              	count++;
            if(fish[i]!=0)
            	counter++;
    }
    if(count<counter)
    	cout<<count<<endl;
    else
    	cout<<counter<<endl;
}
