#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n=0,k=0;
	cin>>n>>k;
	vector<int> train;
	for(int i=1;i<=n;i++) train.push_back(i);
//	for(int i=0;i<n;i++) cout<<train[i]<<" ";
	for(int i=0;i<k;i++){
		int x=0,y=0;
		cin>>x>>y;
		vector<int>::iterator st,en;
		vector<int> temp;
		st=lower_bound(train.begin(),train.end(),x);
		en=lower_bound(train.begin(),train.end(),y);
		int stInt=st-train.begin();
		int enInt=en-train.begin();
		temp.assign(train.begin()+stInt,train.begin()+enInt+1);
		train.erase(train.begin()+stInt,train.begin()+enInt+1);
		for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
		cout<<endl;
		for(int i=0;i<train.size();i++) cout<<train[i]<<" ";
		train.insert(train.end(),temp.begin(),temp.end());
		cout<<endl;
		for(int i=0;i<train.size();i++) cout<<train[i]<<" ";
	}
}
