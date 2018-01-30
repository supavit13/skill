#include <iostream>
#include <string.h>
using namespace std;
int main(){
	string cmd="";
	int x=0,y=0;
	cin>>cmd;
//	cout<<cmd.length();
	for(int i=0;i<cmd.length();i++){
		if(cmd[i]=='N'){
			x++;
		}else if(cmd[i]=='S'){
			x--;
		}else if(cmd[i]=='E'){
			y++;
		}else if(cmd[i]=='W'){
			y--;
		}else if(cmd[i]=='Z'){
			x=y=0;
		}
	}
	cout<<y<<" "<<x;
	
}
