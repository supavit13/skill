#include <iostream>
#include <string.h>
using namespace std;
int main(){
	string str = "";
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]!='A'&&str[i]!='B'&&str[i]!='C'&&str[i]!='D'&&str[i]!='E'&&str[i]!='F'){
			cout<<"Good";
			return 0;
		}else{
			size_t foundF = str.find("F");
			int posF = foundF+1;
			size_t foundA = str.find("A");
			int posA = foundA+1;
			size_t foundC = str.find("C");
			int posC = foundC+1;
//			cout<<"sss"<<endl;
//			cout<<str[str.length()-2]<<endl;
			if(str[1]!='A' || str[str.length()-2] != 'C' || posF == 2 || posF == str.length()-1){
				cout<<"Good";
				return 0;
			}
			if(posA >2){
				cout<<"Good";
				return 0;
			}
			if(posC < str.length()-2){
				cout<<"Good";
				return 0;
			}
			
		}
	}
	cout<<"Infected!";
}
