#include <iostream>
using namespace std;
int main(){
	int x=0,y=0;
	cin>>x;
	cin>>y;
	int sea[y][x];
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			cin>>sea[i][j];
		}
	}
//	for(int i=0;i<y;i++){
//		for(int j=0;j<x;j++){
//			cout<<sea[i][j];
//		}
//		cout<<" "<<i<<endl;
//	}
	int c=0;
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			if(sea[i][j]==0){
				continue;
			}
			if(sea[i-1][j]==1){ // w
				c++;
			}
			if(sea[i-1][j-1]==1){ //ws
				c++;
			}
			if(sea[i][j-1]==1){ // s
				c++;
			}
			if(sea[i+1][j]==1){ // n
				c++;
			}
			if(sea[i+1][j+1]==1){ //ne
				c++;
			}
			if(sea[i][j+1]==1){ //e
				c++;
			}
			if(sea[i-1][j+1]==1){ //se
				c++;
			}
			if(sea[i+1][j-1]==1){ //nw
				c++;
			}
			if(c<2){
//				cout<<i<<" "<<j<<endl;
				cout<<"No";
				return 0;
			}
			c=0;
		}
	}
	cout<<"Yes";
}
