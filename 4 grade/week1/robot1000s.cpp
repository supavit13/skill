#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){
	string cmd="";
	int k=0;
	int x=0,y=0;
	int total = 0;
	cin>>cmd;
	cin>>k;
	int north=0,south=0,east=0,west=0;
	int lostcmd=cmd.length()-k;
	for(int i=0;i<cmd.length();i++){
		if(cmd[i]=='N'){
			x++;
			north++;
		}else if(cmd[i]=='S'){
			x--;
			south--;
		}else if(cmd[i]=='E'){
			y++;
			east++;
		}else if(cmd[i]=='W'){
			y--;
			west--;
		}else if(cmd[i]=='Z'){
			x=y=0;
		}
	}
	west=abs(west);
	south=abs(south);
	int max=0,min=0;
	if(north>=south){
		max=north;
		min=south;
	}else{
		max=south;
		min=north;
	}
	if(west>=east){
		max+=west;
		min+=east;
	}else{
		max+=east;
		min+=west;
	}
//	int maxX=x;
//	int maxY=y;
//	for(int i=0;i<k;i++){
//		
//	}
	total=max-abs(k-min);
	cout<<total*2;
	
}
