#include <iostream>
#include <algorithm> 
using namespace std;
int island[200][200];
int searchRow(int i,int j){
	if(island[i][j]==0){
		return j;
	}
	j++;
	return searchRow(i,j);
}
bool survey(int x,int y,int n){
	for(int i=x;i<n+x;i++){
		for(int j=y;j<n+y;j++){
			if(island[i][j]==0){
				return false;
			}
		}
	}
	return true;
}
int main(){
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		string str="";
		cin>>str;
		for(int j=0;j<n;j++){
			island[i][j]=str[j]-48;
//			cin>>island[i][j];
		}
	}
	int max=0;
	int row=0;
	int x=0,y=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(island[i][j]==0){
				continue;
			}
			row=searchRow(i,j);
			row-=j;
			while(row>0){
				if(survey(i,j,row)){
					if(max<row*row){
						max=row*row;
						x=i+1;
						y=j+1;
					}
				}
				row--;
			}
		}
	}
	cout<<x<<" "<<y<<endl<<max;
}
