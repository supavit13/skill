#include <iostream>
using namespace std;
int main(){
	string str;
	cin>>str;
	char state=' ';
	for(int i =0;i<str.length();i++){
		if(str[i]!='A'&&str[i]!='B'&&str[i]!='C'&&str[i]!='D'&&str[i]!='E'&&str[i]!='F'){
			cout<<"Good";
			return 0;
		}else{
			if(state==' '){
				state='A';
			}else if(state=='A'){
				if(str[i]=='C'){
					cout<<"Good";
					return 0;
				}else if(str[i]=='F'){
					state='F';
				}else{
					state='A';
				}
			}else if(state=='F'){
				if(str[i]=='A'){
					cout<<"Good";
					return 0;
				}else if(str[i]=='C'){
					state='C';
				}else{
					state='F';
				}
			}else if(state=='C'){
				if(str[i]=='A'&&i!=str.length()-1){
					cout<<"Good";
					return 0;
				}else if(str[i]=='F'&&i!=str.length()-1){
					cout<<"Good";
					return 0;
				}else{
					state='C';
				}
			}
		}
	}
	cout<<"Infected!";
}
