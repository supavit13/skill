#include <iostream>
using namespace std;
int main(){
	int total = 0;
	for(int i=0;i<4;i++){
		int score = 0;
		cin>>score;
		total+=score;
	}
	
	if(total<49){
		cout<<"F";
	}else if(total<=54){
		cout<<"D";
	}else if(total<=59){
		cout<<"D+";
	}else if(total<=64){
		cout<<"C";
	}else if(total<=69){
		cout<<"C+";
	}else if(total<=74){
		cout<<"B";
	}else if(total<=79){
		cout<<"B+";
	}else if(total>=80){
		cout<<"A";
	}
}
