#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int y=0,p=0;
	cin>>y>>p;
	int popes[p];
	vector<int> vec;
	
	for(int i=0;i<p;i++){
		cin>>popes[i];
	}
	sort(popes,popes+p);
	int max=0;
	
	for(int i=0;i<p;i++){
		vector<int> temp;
		int tempMax=0;
		for(int j=0,k=i;popes[k]<popes[i]+y;j++,k++){
			if(popes[k]<popes[i]+y){
				temp.push_back(popes[k]);
			}
		}
		for(int j=0;j<temp.size();j++){
			cout<<temp[j]<<" ";
		}
		cout<<endl;
		tempMax=temp.size();
		if(vec.empty()){
			vec=temp;
		}
		if(max<tempMax){
			max=tempMax;
			vec = temp;
		}
	}
	cout<<max<<" "<<vec[0]<<" "<<vec[vec.size()-1];

}
