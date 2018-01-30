#include <iostream>
using namespace std;
int main(){
	int n=1,W=1;
	while(1){
		cin>>n;
		cin>>W;
		if(n==0&&W==0){
			return 0;
		}
		int pack[n];
		for(int i=0;i<n;i++){
			cin>>pack[i];
		}
		int countingTruck=0;
		int weight=0;
		for(int i=0;i<n;i++){
			if(weight+pack[i]>W){
				countingTruck++;
				weight=0;
//				cout<<"truck1"<<endl;
			}
			weight+=pack[i];
//			cout<<weight<<endl;
		}
		if(weight!=0){
			countingTruck++;
		}
		cout<<countingTruck<<endl;
	}
}
