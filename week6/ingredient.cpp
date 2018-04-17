#include <iostream>
#include <vector>
using namespace std;
int lcm(int num1,int num2){
	int max = (num1 > num2) ? num1 : num2;
   	while(1){
      if((max % num1 == 0) && (max % num2 == 0)){
         return max;
      }
      ++max;
   }
}
int main(){
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int x=0;
		cin>>x;
		vector<int> vec[2];
		vector<int> ans;
		for(int j=0;j<2;j++){
			for(int k=0;k<x;k++){
				int p;
				cin>>p;
				vec[j].push_back(p);
			}
		}
		for(int j=0;j<x;j++){
			ans.push_back(lcm(vec[0][j] , vec[1][j])/vec[0][j]);
		}
		int temp=ans[0];
		for(int j=1;j<x;j++){
			temp=lcm(temp,ans[j]);
		}
		cout<<temp<<endl;
		for(int j=0;j<x;j++){
			cout<<temp*vec[0][j]/vec[1][j]<<" ";
		}
		cout<<endl;
	}
}
