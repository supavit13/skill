#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int tod = 0;
string word = "0000";
char binPlus(char w1,char w2,int i){
	if(w1=='1'&& w2=='0') return '1';
	else if(w1=='0'&&w2=='1') return '1';
	else if(w1=='1' && w2=='1'){
		word[i-1]='1';
		return '0';
	}
	return '0';
}
string checksumPackage(string fir,string sec,string crc){
	word = "0000";
	for(int i=3;i>=0;i--){
		word[i]=binPlus(word[i],binPlus(crc[i],binPlus(sec[i],fir[i],i),i),i);
	}
//	cout<<word<<endl;
	for(int i=0;i<4;i++){
		if(word[i]=='1') word[i]='0';
		else word[i]='1';
	}
//	cout<<word<<endl;
	return word;
	
}
int bin2dec(string binary)
{
    int len,dec=0,i,exp;

    len = binary.length();
    exp = len-1;

    for(i=0;i<len;i++,exp--)
        dec += binary[i]=='1'?pow(2,exp):0;
    return dec;
}
int main(){
	string package="";
	cin>>package;
	int amountData = package.length()/12;
	for(int i=0, j=0;i<amountData*12;i+=12,j++){
		string payload = package.substr(i,12);
		string fir = payload.substr(0,4);
		string sec = payload.substr(4,4);
		string crc = payload.substr(8,4);
//		cout<<fir<<endl;
//		cout<<sec<<endl;
//		cout<<crc<<endl;
		crc = checksumPackage(fir,sec,crc);
		if(crc=="0000"){
			cout<<(char)bin2dec(fir+sec);
		}else{
			cout<<"#";
		}
	}
}//010000010010001000001101010011001101010011111100010101100100010001010110001000001101010110010001010011111100010101010101
