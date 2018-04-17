#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main(){
	int n=0,k=0;
	cin>>n>>k;
	list<int> lst;
	char cmd;
	int x;
	int y;
	for(int i=1;i<=n;i++){
		lst.push_back(i);
	}
	for(int i=0;i<k;i++){
		cin>>cmd;
		cin>>x;
		cin>>y;
		list<int>::iterator p;
		list<int> temp;
		int arr[1]={y};
		if(cmd=='A'){
			temp.push_back(x);
			lst.remove(x);
			p=search(lst.begin(),lst.end(),arr,arr+1);
			lst.insert(p,temp.begin(),temp.end());
		}
		if(cmd=='B'){
			temp.push_back(x);
			lst.remove(x);
			p=search(lst.begin(),lst.end(),arr,arr+1);
			p++;
			lst.insert(p,temp.begin(),temp.end());
		}	
	}
	for(list<int>::iterator i=lst.begin() ;i != lst.end() ;i++){
		cout<<*i<<endl;
	}	
}
