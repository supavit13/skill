#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int row=0,col=0,direct=0;
	cin>>col>>row>>direct;
	int arr[row+2][col+2];
	for(int i=0;i<row+2;i++){
		for(int j=0;j<col+2;j++){
			if(i==0||j==0||i==row+1||j==col+1){
				arr[i][j]=0;
			}else{
				cin>>arr[i][j];
			}
			
		}
	}
//	for(int i=0;i<row+2;i++){
//		for(int j=0;j<col+2;j++){
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int ans[row+2][col+2];
	int c=0;
	for(int i=0;i<row+2;i++){
		for(int j=0;j<col+2;j++){
//			c++;
//			temp.clear();
			if(i==0||j==0||i==row+1||j==col+1){
				ans[i][j]=0;
				continue;
			}
//			vector<int> temp;
//			temp.clear();
			int temp[direct+1];
			if(direct==4){
				temp[0]=arr[i][j]; // me 
				temp[1]=arr[i-1][j]; // N
				temp[2]=arr[i+1][j]; // S
				temp[3]=arr[i][j-1]; // W
				temp[4]=arr[i][j+1]; // E
			}else if(direct==8){
				temp[0]=arr[i][j]; //me
				temp[1]=arr[i-1][j]; // N
				temp[2]=arr[i+1][j]; // S
				temp[3]=arr[i][j-1]; // W
				temp[4]=arr[i][j+1]; // E
				temp[5]=arr[i-1][j-1]; // NW
				temp[6]=arr[i+1][j+1]; //SE
				temp[7]=arr[i+1][j-1]; // SW
				temp[8]=arr[i-1][j+1]; // NE
			}
			sort(temp,temp+direct+1);
//			for(int a=0;a<direct+1;a++){
//				cout<<temp[a]<<" ";
//			}
//			cout<<endl;
//			int median=temp.size()/2;
			if(direct==4){
				ans[i][j]=temp[2];
			}
			else{
				ans[i][j]=temp[4];
			}
			
		}
	}
	for(int i=1;i<row+1;i++){
		for(int j=1;j<col+1;j++){
			cout<<ans[i][j]<<" ";
		}
		if(row!=i){
			cout<<endl;	
		}
	}
}
