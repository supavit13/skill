#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n;
	cin>>m;
	int a[n][m];
//	char arr[m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int count,count2;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			count=1,count2=1;
			int b=a[i][j];
			for(int k=i;k<n;k++){
				if(a[k][j]>b){
					count=10;
					break;
				}
			}
			for(int l=j;l<m;l++){
				if(a[i][l]>b){
					count2=10;
					break;
				}
			}
//			if(a[i][j+1]>a[i][j] and a[i+1][j]>a[i][j]){
			if(count==10 and count2==10){
				cout<<"NO";
				count=10;
				return 0;
			}
			
				
			
		}
		
	}
	cout<<"YES";
//	if(count==1){
//		
//	}
}
