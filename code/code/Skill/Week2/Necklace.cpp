#include<iostream>
#include<cstdlib>

using namespace std;
struct record
{
       int value;
       struct record *next;
};

int main()
{
	int n;
	cin>>n;
	struct record box[n],*tmp;
	bool check_head[n];
	for(int i=0;i<n;i++)
	{
		box[i].value=i+1;
		box[i].next=NULL;
		check_head[i]=false;
	}
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		struct record *p;
		cin>>x>>y;
		check_head[x-1]=true;
		
		if(box[y-1].next==NULL)//nohave son
       		box[y-1].next=&box[x-1];
       	else //have son cut list
       	{
			tmp=box[y-1].next;
			box[y-1].next=&box[x-1];
			p=&box[x-1];
			while((*p).next != NULL)//find  tail
                p=(*p).next;
            (*p).next=tmp;
		}   	
	}
	//////////////////print list//////////////
	 for(int i=0;i<n;i++)
	 {
        if(!check_head[i])
        {
            struct record *p = &box[i];
            while(p!=NULL)
            {
                cout<<(*p).value<<" ";
                p=(*p).next;
            }
            break;
        } 
	}
	
}
