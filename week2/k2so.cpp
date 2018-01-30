#include <iostream>
#include <vector>
#include <algorithm> //8 2 3 4 5 5 6 8 9 3 6 5 6 9 12 9 10
using namespace std;


int main(){
	int n=0,x,c=0;
	cin>>n;
	vector<pair<int,int> > container;
	vector<int> count;
	for(int i=0;i<n*2;i++){
		if(i==1){
			cin>>x;
			container.push_back(make_pair(x,1));
			continue;
		}
		if(i%2==0){
			cin>>x;
			container.push_back(make_pair(x,0));
		}else{
			cin>>x;
			container.push_back(make_pair(x,1));
		}
		
	}
	cout<<"before sort"<<endl;
	
	for(int i=0;i<n*2;i++){
		cout<<container[i].first<<" "<<container[i].second<<endl;
	}
	sort(container.begin(),container.end());
	cout<<"after sort"<<endl;
	for(int i=0;i<n*2;i++){
		if(container[i].second==1){
			c--;
			count.push_back(c);
		}else{
			c++;
			count.push_back(c);
		}
	}
	for(int i=0;i<n*2;i++){
		cout<<container[i].first<<" "<<container[i].second<<" "<<count[i]<<endl;
	}
	int max=count[0];
	int position=0;
	for(int i=0;i<n*2;i++){
		if(max<count[i]){
			max=count[i];
			position=i;
		}
	}
	cout<<"ans"<<endl;
	cout<<container[position].first;

}
