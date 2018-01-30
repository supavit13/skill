#include <iostream>
using namespace std;
int main(){
	int cola = 0;
	cin>>cola;
	int stock=0;
	int total=cola;
	while(1){
		stock=cola%3;
		cola=cola/3;
		if(stock==2){
			cola++;
		}
		total+=cola;
		if(total%3==0){
			break;
		}
		if(total%3!=0&&cola%3==0&&stock!=2){
			total--;
			break;
		}
		stock=0;
	}
	
	

	cout<<total;
}
