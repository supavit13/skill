#include<iostream>
using namespace std;
string str="";
const char * const ones[20] = {"zero", "one", "two", "three","four","five","six","seven",
    "eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"};
const char * const tens[10] = {"", "ten", "twenty", "thirty","forty","fifty","sixty","seventy",
	"eighty","ninety"};
void calculate(int value)
{
	if(value==10000){
    	str+="ten thousand";
	}else if(value>=1000){
		str+=ones[value/1000];
		str+=" thousand ";
		calculate(value%1000);
	}else if(value>=100){
		str+=ones[value/100];
		str+=" hundred ";
		calculate(value%100);
	}
	else if(value>=20){
		str+=tens[value/10];
		if(value%10!=0){
			str+="-";
			calculate(value%10);
		}
	}else if(value<20){
		if(value!=0){
			str+=ones[value];	
		}
	}
}
int main()
{
    int num=0,n=0;;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>num;
    	if(num==0){
    		cout<<"zero"<<endl;
    		continue;
		}
    	calculate(num);
    	cout<<str<<endl;
    	str="";
	}
}

