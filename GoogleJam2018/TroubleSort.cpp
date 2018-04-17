#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> reverseM(vector<int> lst,int f,int s){
	vector<int> temp;
	for(int i =f;i<=s;i++){
		temp.push_back(lst[i]);
	}
	reverse(temp.begin(),temp.end());
	for(int i=f,j=0;i<=s;i++,j++){
		lst[i]=temp[j];
	}
	return lst;
}
vector<int> TroubleSort(vector<int> lst){
	bool done=false;
	while(!done){
		done=true;
		for(int i=0,j=2;j<lst.size();i++,j++){
			if(lst[i]>lst[j]){
				done=false;
				lst=reverseM(lst,i,j);
			}
		}
		
	}
	return lst;
}
int main(){
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int integers=0;
		cin>>integers;
		vector<int> lst;
		for(int j=0;j<integers;j++){
			int x=0;
			cin>>x;
			lst.push_back(x);
		}
		lst=TroubleSort(lst);
		bool err = 0;
		int pos = 0;
		for(int j=0;j<lst.size()-1;j++){
			if(lst[j]>lst[j+1]){
				err=1;
				pos=i;
			}
		}
		if(err){
			cout<<"Case #"<<i+1<<": "<<pos<<endl;
		}else{
			cout<<"Case #"<<i+1<<": OK"<<endl;
		}
		
	}
}
