#include<iostream>

using namespace std;

bool check(int per[],int j)
{
    for(int i=0;i<j;i++)
    {
        if(per[i] == per[j])
            return true;
	}
    return false;
}
int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    int per[k];
    for(int i=0;i<k;i++)
    {
        per[i]=i+1;
	}
    int count,j,c;
    j=k-1;
    count=1;
    while(count<l)
    {
        per[j]++;
        if(!check(per,j) && per[j]<=n)
        {
            count++;
            c=j+1;
            while(c<k)
            {
                for(int i=1;i<=n;i++)
                {
                    per[c]=i;
                    if(!check(per,c))
                    {
                        c++;
                        break;
                    }
                }
            }
            j=k-1;
        }
        else if(per[j]>n)
        {
            j--;
        }
    }
    for(int i=0;i<k;i++)
    {
            cout<<per[i]<<" ";
	}
    //cout << endl;
    
}
