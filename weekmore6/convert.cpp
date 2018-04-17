#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
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
string dec2bin(int number){
    string bin;
    char holder=' ';
    while(number!=0)
    {
        holder=number%2+'0';
        bin=holder+bin;
        number/=2;
    }
    return bin;
}
string checksumPackage(string w1,string w2){
	word="0000";
	for(int i=3;i>=0;i--){
		word[i]=binPlus(word[i],binPlus(w1[i],w2[i],i),i);
	}
	for(int i=0;i<4;i++){
		if(word[i]=='1') word[i]='0';
		else word[i]='1';
	}
	return word;
}
int main(){
	string str="",ans="";
	getline(cin, str);
	for(int i=0;i<str.length();i++){
		int num = (int)str[i];
		string temp=dec2bin(num);
		for(int j=temp.length();j<8;j++){
			temp="0"+temp;
		}
		string fir = temp.substr(0,4);
		string sec = temp.substr(4,4);
		string crc = checksumPackage(fir,sec);
		ans+=fir+sec+crc;
	}
	cout<<ans;
}//010010010010001000001101010011001111010011111100010101100100010001010110001000001101010110010001010011111100010101010101
