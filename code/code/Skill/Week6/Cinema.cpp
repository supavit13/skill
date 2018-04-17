#include <iostream>
#include <climits>
 
using namespace std;

int Min_distance(int distance[], bool check[],int N)
{
   int min=INT_MAX,index; 
   for (int i=0;i<N;i++)
     if (check[i]==false && distance[i]<=min)
     {
         min=distance[i]; 
		 index = i;
	 }  
   return index;
}
 
int main()
{
   int N;
   while(1)
   {
	   cin>>N;
	   int Map[N][N],findcity[N][3];
	   for(int i=0;i<N;i++)
	   		for(int j=0;j<N;j++)
	   			Map[i][j]=0;
	   if(N==0)
	   		return 0;
	   else
	   {
	 		int m,p=0;
	 		cin>>m;
	 		for(int i=0;i<m;i++)
	 		{
				int u,v,l;
				cin>>u>>v>>l;
				Map[u-1][v-1]=l;
				Map[v-1][u-1]=l;
			}
			
			for(int j=0;j<N;j++)
			{
			     int distance[N];    //distanceance from begin city to other city
			     bool check[N]; // check distanceance shortest
			     for (int i = 0; i < N; i++)
			     {
					   distance[i] = INT_MAX; 
					   check[i] = false;
				 }
			     distance[j] = 0;//node begin
			     for (int count = 0; count < N-1; count++) // find shortest path for all distanceance
			     {
				       int u = Min_distance(distance, check,N);
				       check[u] = true;
				       for (int i = 0; i < N; i++)// Update distance value
				 	   {
				        	if (!check[i] && Map[u][i] && distance[u]!=INT_MAX && distance[u]+Map[u][i]<distance[i])
				            	distance[i] = distance[u] + Map[u][i];
					   }
			     }
				 int max=distance[0],index=0;
			     for (int i = 0; i < N; i++)
			     {
						if(distance[i]>max)
							max=distance[i];
      				//	cout<<i+1<<" "<<distance[i]<<endl;
				 }
			//	 cout<<endl;
				/* if(index==0)
				 	index=1;*/
				 //findcity[p][0]=index;
				 findcity[p][1]=max;
				 findcity[p][2]=j+1;
			     p++; 
				 /*if(index<bestcity && max<=valuecenter)
				 {
				 	bestcity=index;
				 	valuecenter=max;
				 }*/
			}
		//	cout<<endl;
			int bestcity=findcity[0][1],valuecenter=1;
			for(int i=0;i<N;i++)
			{
				if(findcity[i][1]<bestcity)
				{
					bestcity=findcity[i][1];
					valuecenter=findcity[i][2];
				}
			//	cout<<findcity[i][1]<<" "<<findcity[i][2]<<endl;
			}
			cout<<valuecenter<<" "<<bestcity<<endl;			
	   }
   }
   //return 0;
}
