#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int row=0,col=0,direct=0;
	cin>>row>>col>>direct;
	int arr[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
	int ans[row][col];
//	cout<<"before--------------"<<endl;
	int c=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			c++;
			vector<int> temp;
			temp.push_back(arr[i][j]);
			if(i-1<0&&j<col&&j>0){ // >N
				temp.push_back(0);
			}else{
				temp.push_back(arr[i-1][j]);
			}
			if(i+1>row&&j<col&&j>0){ // >S
				temp.push_back(0);
			}else{
				temp.push_back(arr[i+1][j]);
			}
			if(j-1<0&&i<row&&i>0){ // >W
				temp.push_back(0);
			}else{
				temp.push_back(arr[i][j-1]);
			}
			if(j+1>col&&i<row&&i>0){ // >E
				temp.push_back(0);
			}else{
				temp.push_back(arr[i][j+1]);
			}
			if(direct==8){
				if(i-1<0&&j+1>col){ // >NE
					temp.push_back(0);
				}else{
					temp.push_back(arr[i-1][j+1]);
				}
				if(i-1<0&&j-1<0){ // >NW
					temp.push_back(0);
				}else{
					temp.push_back(arr[i-1][j-1]);
				}
				if(i+1>row&&j+1>col){ // >SE
					temp.push_back(0);
				}else{
					temp.push_back(arr[i+1][j+1]);
				}
				if(i+1>row&&j-1<0){ // >SW
					temp.push_back(0);
				}else{
					temp.push_back(arr[i+1][j-1]);
				}
			}
			
			
//			if(direct==4){
//				temp.push_back(arr[i][j]); // me 
//				temp.push_back(arr[i-1][j]); // N
//				temp.push_back(arr[i+1][j]); // S
//				temp.push_back(arr[i][j-1]); // W
//				temp.push_back(arr[i][j+1]); // E
//			}else{
//				temp.push_back(arr[i][j]); //me
//				temp.push_back(arr[i-1][j]); // N
//				temp.push_back(arr[i+1][j]); // S
//				temp.push_back(arr[i][j-1]); // W
//				temp.push_back(arr[i][j+1]); // E
//				temp.push_back(arr[i-1][j-1]); // NW
//				temp.push_back(arr[i+1][j+1]); //SE
//				temp.push_back(arr[i+1][j-1]); // SW
//				temp.push_back(arr[i-1][j+1]); // NE
//			}
			sort(temp.begin(),temp.end());
//			if(c<10){
//				cout<<c<<" | ";
//			}
//			else{
//				cout<<c<<"| ";
//			}
//			for(int k=0;k<temp.size();k++){
//				cout<<temp[k]<<" ";
//			}
//			cout<<endl;
			int size=temp.size()/2;
			ans[i][j]=temp[size];
		}
	}
//	cout<<"ans--------------"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
