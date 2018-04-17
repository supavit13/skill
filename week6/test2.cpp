#include <iostream>
#include <algorithm>
using namespace std;
string to_str(unsigned long long x){
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
string numtostring(string temp,unsigned long long num){
	if(num==0){
		reverse(temp.begin(),temp.end());
		return temp;
	}
	temp+=to_str(num%10);
	num/=10;
	return numtostring(temp,num);
}
int main(){
	string str="";
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		unsigned long long num;
		cin>>num;
		str=numtostring(str,num);
		cout<<"num to string = "<<str<<endl;
		str = "";
	}
}
