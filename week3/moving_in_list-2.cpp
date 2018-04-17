#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main(){
	int n=0,k=0;
	cin>>n>>k;
	list<int> lst;
	char cmd[k];
	int x[k];
	int y[k];
	for(int i=1;i<=n;i++){
		lst.push_back(i);
	}
	for(int i=0;i<k;i++){
		cin>>cmd[i];
		cin>>x[i];
		cin>>y[i];
	}			
	for(int i=0;i<k;i++){
		list<int>::iterator p;
		list<int> temp;
		if(cmd[i]=='A'){
			temp.push_back(x[i]);
			lst.remove(x[i]);
			p=lower_bound(lst.begin(),lst.end(),y[i]);
			lst.insert(p,temp.begin(),temp.end());
		}
		if(cmd[i]=='B'){
			temp.push_back(x[i]);
			lst.remove(x[i]);
			p=lower_bound(lst.begin(),lst.end(),y[i]);
			p++;
			lst.insert(p,temp.begin(),temp.end());
		}

	}
	for(list<int>::iterator i=lst.begin() ;i != lst.end() ;i++){
		cout<<*i<<endl;
	}

	
}
