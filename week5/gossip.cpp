#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n=0;
	cin>>n;
	vector<int> adj_lst[n];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int ki;
			cin>>ki;
			adj_lst[i].push_back(ki);
		}
	}
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++){
		int ti,max=0,day=0;
		cin>>ti;
		if(adj_lst[ti].size()==0){
			cout<<0<<endl;
			continue;
		}
		max=adj_lst[ti].size();
		vector<int> fs[n*n];
		int c=0;
//		while(day<n){
//			fs[day].push_back(ti);
//			for(int j=0;j<adj_lst[ti].size();j++){
//				fs[day].push_back(adj_lst[ti][j]);
//				cout<<adj_lst[ti][j]<<" ";
//			}
//			cout<<endl;
//			
//			day++;
//		}
		
	}
	
}
