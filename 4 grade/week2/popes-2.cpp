#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int y=0,p=0;
	cin>>y>>p;
	vector<int> vec;
	for(int i=0;i<p;i++){
		int input=0;
		cin>>input;
		vec.push_back(input);
	}
	sort(vec.begin(),vec.end());
	vector<int>::iterator low,upp;
	int max=0;
	int lowBound=0;
	int uppBound=0;
	for(int i=0;i<p;i++){
//		cout<<"vec "<<vec[i]<<" "<<vec[i]+y-1<<endl;
		low=lower_bound (vec.begin(), vec.end(), vec[i]);
//		if(binary_search (vec.begin(), vec.end(), vec[i]+y-1)){
//			upp=upper_bound (vec.begin(), vec.end(), vec[i]+y-1);
//		}
		upp=upper_bound (vec.begin(), vec.end(),vec[i]+y-1);
		int lowInt=vec[low-vec.begin()];
		int uppInt=vec[(upp-vec.begin())-1];
//		if(max<vec[uppInt]-vec[lowInt]){
//			max=vec[uppInt]-vec[lowInt];
//		}
		if(max<(upp-vec.begin())-(low-vec.begin())){
			max=(upp-vec.begin())-(low-vec.begin());
			lowBound=lowInt;
			uppBound=uppInt;
		}
//		cout<<"max "<<max<<endl;
//		cout<<"int "<<lowInt<<" "<<uppInt<<endl<<endl;
	}
	cout<<max<<" "<<lowBound<<" "<<uppBound;
}
