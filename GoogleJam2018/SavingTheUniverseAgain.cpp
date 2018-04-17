#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int damageCal(string str){
	int damage=1;
	int temp = 0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='C'){
			damage*=2;
		}else if(str[i]=='S'){
			temp+=damage;
		}
	}
	return temp;
}
int main(){
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int shield = 0;
		string instruction = "";
		cin>>shield>>instruction;
		string temp = instruction;
		sort(temp.begin(),temp.end());
		reverse(temp.begin(),temp.end());
		int j=0,k=1;
		int hacks=0;
		
		while(j<instruction.length()&&k<instruction.length()){
			if(damageCal(instruction)<=shield){
				break;
			}
			if(instruction[j]=='C' && instruction[k]=='S'){
				instruction[j]='S';
				instruction[k]='C';
				hacks++;
				j=0;
				k=1;
			}
			k++;
			j++;
			if(instruction==temp){
				break;
			}
			
		}
		if(damageCal(instruction)>shield){
			cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
		}else{
			cout<<"Case #"<<i+1<<": "<<hacks<<endl;
		}
		
	}
}

