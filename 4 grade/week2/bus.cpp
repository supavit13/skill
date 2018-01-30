#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int road=0,money=0,tax=0;
	cin>>road>>money>>tax;
	while(road!=0&&money!=0&&tax!=0){
		vector<int> morning;
		vector<int> afternoon;
		for(int i=0;i<road;i++){
			int in=0;
			cin>>in;
			morning.push_back(in);
		}
		for(int i=0;i<road;i++){
			int in=0;
			cin>>in;
			afternoon.push_back(in);
		}
		sort(morning.begin(),morning.end());
		sort(afternoon.begin(),afternoon.end());
		reverse(afternoon.begin(),afternoon.end());
		int sum=0;
		for(int i=0;i<road;i++){
			morning[i]=morning[i]+afternoon[i];
			if(morning[i]>=money){
				morning[i]-=money;
				sum+=morning[i];
			}
//			cout<<"sum "<<morning[i]<<endl;
			
		}
		cout<<sum*tax<<endl;
		cin>>road>>money>>tax;
	}
	
}
