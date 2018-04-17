#include <iostream>
using namespace std;
int arr[100][100];
int mar[100][100];

void mark(int i,int j){
	
	if(arr[i][j]==1&&mar[i][j]==0){
		mar[i][j]=1;
	}else{
		return ;
	}
	mark(i-1,j);
	mark(i+1,j);
	mark(i-1,j-1);
	mark(i-1,j+1);
	mark(i,j-1);
	mark(i,j+1);
	mark(i+1,j+1);
	mark(i+1,j-1);
	
}
int main(){
	int c=0;
	int x=0,y=0;
	cin>>x>>y;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>arr[i][j];
			mar[i][j]=0;
		}
	}	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(arr[i][j]==1&&mar[i][j]==0){
				c++;
			}
			mark(i,j);
		}
	}
	
	cout<<c;
}
