#include <iostream>
using namespace std;
int main(){
	int k=1;
	int tax = 0;
	cin>>k;
	while(k!=0){
		tax=0;
		float percent=0;
		int val=0;
		if(k<=100000){
			tax=0;
		}
		
		if(k>=100001&&k<=1000000){
			percent=0.06;
			val=k-100000;
			tax+=0.06*val;
		}else if(k>1000000){
			tax+=54000;
		}
		
		if(k>=1000001&&k<=5000000){
			percent=0.12;
			val=k-1000000;
			tax+=0.12*val;
		}else if(k>5000000){
			tax+=480000;
		}
		
		if(k>=5000001&&k<=10000000){
			percent=0.2;
			val=k-5000000;
			tax+=0.2*val;
		}else if(k>10000000){
			tax+=1000000;
		}
		if(k>10000000){
			percent=0.32;
			val=k-10000000;
			tax+=0.32*val;
		}
		cout<<tax<<endl;
		cin>>k;
	}

}
