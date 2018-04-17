#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int count=0;
    string n;
    cin>>n;
    if(n[0]>='A'&&n[0]<='Z'||n[0]=='_'||n[0]>='a'&&n[0]<='z')
    {
     for(int i=1;i<n.size();i++)
     {
         if(n[i]>='A'&&n[i]<='Z'||n[i]=='_'||n[i]>='a'&&n[i]<='z'||n[i]>='0'&&n[i]<='9')
         {}
         else
         count++; 
     }
     if(count==0)
      cout<<"Valid"<<endl;
     else
      cout<<"Invalid"<<endl;
    }
    else
      cout<<"Invalid"<<endl;  
}
