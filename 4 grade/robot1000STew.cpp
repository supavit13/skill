#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(){
	
	
	string pos;
	bool check = true;
	int x=0,y=0,count_1=0,count_2=0,count_3=0,count_4=0,k=0,max=0,min=0;
	cin >> pos;
	cin >> k;
	
	for(int i =0; i < pos.length();i++){
	
		if(pos[i] == 'N'){
			count_1=count_1+1;
		}else if(pos[i] =='S'){
			count_2=count_2+1;
		}else if (pos[i] =='W'){
			count_3=count_3+1;
		}else if(pos[i] =='E'){
			count_4=count_4+1;
		}
		
	}
	//cout << count_1 << " " << count_2 << " " << count_3 << " " << count_4;
	if(count_1 >= count_2 ){
		max = count_1;
		min = count_2;
	}else{
		max = count_2;
		min = count_1;
	}
	
	if(count_3 >= count_4 ){
		max = max + count_3;
		min = min + count_4;
	}else{
		max = max + count_4;
		min = min +count_3;
	}
		cout << (max - (abs(k-min)))*2 ;
	

	
	
}
