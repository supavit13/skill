#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;
string to_str(int x){
	switch(x){
		case 1:
			return "1";
		case 2:
			return "2";
		case 3:
			return "3";
		case 4:
			return "4";
		case 5:
			return "5";
		case 6:
			return "6";
		case 7:
			return "7";
		case 8:
			return "8";
		case 9:
			return "9";
		case 0:
			return "0";	
	}
}
int main(){
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		string str="";
		int dec=0,base=0;
		cin>>dec>>base;
		int j=0;
		if(dec==0){
			cout<<0<<endl;
			continue;
		}
		while(dec>0){
			str+=to_str(dec%base);
			dec/=base;
		}
		reverse(str.begin(),str.end());
		cout<<str<<endl;
	}
}

