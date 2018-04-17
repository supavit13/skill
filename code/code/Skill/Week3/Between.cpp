#include<iostream>
#include<algorithm>

using namespace std;

int factorial(int n)
{
	if(n==1)
		return 1;
	else
		return factorial(n-1)*n;
}
int main()
{
	int n,c,T,a=0,fac;
	int per[20000][10];
//	cin>>T;
	
	//while(a<T)
//	{
		cin>>n>>c;
		int data[n];
		int m[c],l[c],r[c];
		for(int i=0;i<n;i++)
		{
			data[i]=i+1;
		}
		fac=factorial(n);
	//for(int i=0;i<fac/2;i++)
	int k=0;
			do 
			{
				for(int i=0;i<n;i++)
				{
					per[k][i]=data[i];
				}
			    //cout << data[0] << ' ' << data[1] << ' ' << data[2] <<' '<<endl;
			    if(k>=fac)
			    	break;
			    k++;
			} while ( next_permutation(data,data+n) );
	//
	   /*int lc,rc; 
		for(int i=0;i<c;i++)
		{
			cin>>m[i]>>lc>>rc;
			if(rc<lc)
			{
				int tmp=lc;
				lc=rc;
				rc=tmp;
				l[i]=lc;
				r[i]=rc;
			}
			else
			{
				l[i]=lc;
				r[i]=rc;
			}
		}
		int count,index=0;
		bool check=false;
			for(int i=0;i<k;i++)//per row
			{
				count=0;
				
				for(int p=0;p<c;p++)//condition
				{
					
					for(int j=0;j<n;j++)//per column
					{
						if(per[i][j]==m[p])
						{
							for(int x=j-1;x>=0;x--)
							{
							
								if(per[i][x]==l[p])
								{
										//cout<<"5555555555";
										count++;
										break;
								}
								else
									break;
							}
							for(int y=j+1;y<n;y++)
							{
								if(per[i][y]==r[p])
								{
									count++;
									break;
								}
								else
									break;
							}
							if(counter==2)
								break;
						}
						if(count==c*2)
						{
							//cout<<"666666666";
							index=i;
							check=true;
						}
						if(check==true)
							break;
					}
					if(check==true)
						break;
				}
				if(check==true)
					break;	
			}
		cout<<count<<" "<<index;
	//	cout<<"NO"<<endl;
	//	a++;*/
	/*	for(int i=0;i<n;i++)
		{
			cout<<per[index][i]<<" ";
		}*/
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<per[i][j]<<" ";
			}
			cout<<endl;
		}
//	}
	//cout<<fac;
}
/*
int main () {
  int myints[] = {1,2,3,4,5};

  
  do {
    cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] <<' '<< myints[3] <<' '<< myints[4] <<'\n';
  } while ( next_permutation(myints,myints+5) );


  return 0;
}*/
