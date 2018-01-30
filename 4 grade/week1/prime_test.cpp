#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int number=0;
	cin>>number;
	if(number==1){
		cout<<"NO";
		return 0;
	}
	if(number==0){
		cout<<"NO";
		return 0;
	}
	for(int i=2;i<=sqrt(number);i++){
		if(number%i==0){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}
