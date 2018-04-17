#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
char alphabet[4000];
int number;
void convert_text(int n)
{
	int i=0;
    while(n!=0)
    {
        if(n>=1000)
        {
            n=n-1000;
            alphabet[i]= 'M';
             i++;
        }
        if(n>=900&&n<1000)
        {
            n=n-900;
            alphabet[i]= 'C';
            alphabet[i+1]= 'M';
             i=i+2;
        }
        if(n<900 && n>=500)
        {
            n=n-500;
            alphabet[i]= 'D';
             i++;
        }
        if(n<500 && n>=400)
        {
            n=n-400;
            alphabet[i]= 'C';
            alphabet[i+1]= 'D';
             i=i+2;
        }
        if(n<400 && n>=100)
        {
            n=n-100;
            alphabet[i]= 'C';
             i++;
        }
        if(n<100 && n>=90)
        {
            n=n-90;
            alphabet[i]= 'X';
            alphabet[i+1]= 'C';
             i=i+2;
        }
        if(n<90 && n>=50)
        {
            n=n-50;
            alphabet[i]= 'L';
             i++;
        }
        if(n<50 && n>=40)
        {
            n=n-40;
            alphabet[i]= 'X';
            alphabet[i+1]= 'L';
             i=i+2;
        }
        if(n<40 && n>=10)
        {
            n=n-10;
            alphabet[i]= 'X';
             i++;
        }
        if(n==9)
        {
            n=n-9;
            alphabet[i]= 'I';
            alphabet[i+1]= 'X';
             i=i+2;
        }
        if(n<9 && n>=5)
        {
            n=n-5;
            alphabet[i]= 'V';
             i++;
        }
        if(n==4)
        {
            n=n-4;
            alphabet[i]= 'I';
            alphabet[i+1]= 'V';
             i=i+2;
        }
        if(n<4 && n>=1)
        {
            n=n-1;
            alphabet[i]= 'I';
            i++;
        }       
    }
    number=i;
}
int main()
{
	string x;
	char text[4000];
	int cn=1,sum,check=0,num=0,value[4000]={0},a=0,count=0;
	cin>>x;
	for(int i=0;i<x.size();i++)
	{
		text[i]=x[i];
	}
	for(int i=0;i<x.size();i++)
	{
		if(text[0]>='A' && text[0]<='Z')//MMM
		{
			if(text[i+1]>='0' && text[i+1]<='9')//M17
            {   
				cn=0;
                cout<<"Error"<<endl;
                break;
            }
            if(text[i]>='A' && text[i]<='Z')//keep value in value[i]
            {
				if(text[i]=='M')
                    value[i]=1000;
                if(text[i]=='D')
                    value[i]=500;
                if(text[i]=='C')
                    value[i]=100;
                if(text[i]=='L')
                    value[i]=50;
                if(text[i]=='X')
                    value[i]=10;
                if(text[i]=='V')
                    value[i]=5;
                if(text[i]=='I')
                    value[i]=1;
             
                check=1;
            }
			
		}
		else if(text[0]>='0' && text[0]<='9')//1732
		{
			if(text[i+1]>='A' && text[i+1]<='Z')//17MM
            {   
				cn=0;
                cout<<"Error"<<endl;
                break;
            }
            else
            {
				int n=x.size();
				sum=0;
				cn=2;
				for(int j=0;j<x.size();j++)//1 7 3 2 char to int 1732
				{
					n--;
					sum=sum+((text[j]-48)*(pow(10,n)));
				}
				convert_text(sum);//convert int to text
			}
		}
	}
	if(cn==2)
	{
		for(int i=0;i<number;i++)
		{
			cout<<alphabet[i];
		}
	}
    if(check==1&&cn==1)
	{
		for(int i=0;i<x.size();i++)
		{
			
			if(value[i]<value[i+1])
			{
				if(value[i-1]<=value[i]&&value[i-1]!=0)//IIX
				{
					a=1;
					cn=0;
	                cout<<"Error"<<endl;
	                break;
				}
				else//MCMLVI
				{
					//count++;
					num=num+value[i+1]-value[i];
					i++;
				}
			}
			else if(value[i]==value[i+1]&&value[i+1]==value[i+2]&&value[i+2]==value[i+3])//MDCCCCLVI  have 4 alphabet same
			{
				a=1;
				cn=0;
                cout<<"Error"<<endl;
                break;
			}
			else//sum value in value[i]
				num=num+value[i];
		}
		if(a==0)
			cout<<num;
		/*if(count<2&&a==0)
		{
			cout<<num;
		}
		if(count>=2)
		{
            cout<<"Error"<<endl;
            //break;
		}*/
		//if(a==0)
			
/*	for(int i=0;i<x.size();i++)/// check value in value[i]
		{
			cout<<value[i]<<" ";
		}*/
	}
	//cout<<text[0]<<" "<<(pow(10,3))+text[0];
	//cout<<sum;
	
	/*for(int i=0;i<x.size();i++)
	{
		cout<<text[i]<<" ";
	}*/
}
