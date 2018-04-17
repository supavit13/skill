#include <iostream>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	int a[x][y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>a[i][j];
		}
	}
	int count=0,sum=0;
	for(int i=1;i<x-1;i++){
		for(int j=1;j<y-1;j++){
			if(a[i][j]==1){
				
				if(a[i][j-1]==1)
					count++;
				if(a[i][j+1]==1)
					count++;
				if(a[i-1][j-1]==1)
					count++;
				if(a[i-1][j]==1)
					count++;
				if(a[i-1][j+1]==1)
					count++;
				if(a[i+1][j-1]==1)
					count++;
				if(a[i+1][j]==1)
					count++;
				if(a[i+1][j+1]==1)
					count++;
			}
		}
		if(count<2){
			sum=1;
			break;
		}
		count=0;
	}

	if(sum==0){
		cout<<"Yes";
	}
	else if(sum==1){
		cout<<"No";
	}
}
//	cout<<"HERE"<<endl;
//	for(int i=0;i<x;i++){
//		cout<<endl;
//		for(int j=0;j<y;j++){
//			cout<<a[i][j]<<" ";
//		}
//	}
