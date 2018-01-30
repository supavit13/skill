#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n=0;
	cin>>n;
	vector<int> vec1;
	vector<int> vec2;
	for(int i=0;i<n;i++){
		int value=0;
		cin>>value;
		vec1.push_back(value);
	}
	for(int i=0;i<n;i++){
		int value=0;
		cin>>value;
		vec2.push_back(value);
	}
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
//	for(int i=0;i<n;i++){
//		cout<<vec1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<vec2[i]<<" ";
//	}
	int i=0,j=0;
	int counter=0;
	while(1){
		if(i==n||j==n){
			break;
		}
		if(vec1[i]==vec2[j]){
			i++;
			j++;
			counter++;
		}
		else if(vec1[i]<vec2[j]){
			i++;
		}else if(vec1[i]>vec2[j]){
			j++;
		}
		
	}
	cout<<counter<<endl;
	
}

