#include<iostream>

using namespace std;

int main()
{
	int n,x,count=0,max,index_i,index_j,tmp=0,matrixi=0,matrixj=0;
	cin>>n;
	string data;
	int square[200][200];
	for(int i=0;i<n;i++)
	{
		cin>>data;
		for(int j=0;j<n;j++)
		{
			square[i][j]=data[j]-48;
		//	cin>>square[i][j];
		}
	}
    max = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(square[i][j]!=0)
            {
                int k=j;
                count=0;
                //cout << 55555;
                while(square[i][k]!=0)
                    k++;
                k = k - j;
                while(k > 0)
                {
                    bool check = false;
//                    cout << i << " " << j << " "  << k << endl;
                    for(int l=i;l<i+k;l++)
                    {
                        for(int m=j;m<j+k;m++)
                        {
                            if(square[l][m] == 0)
                            {
//                                cout << l << " " << m << endl;
                                check = true;
                                break;
                            }
                        }
                    }
                    if(check == false)
                    {
                        int a = k * k;
                        if(a > max)
                        {
                            max = a;
                            matrixi=i+1;
                            matrixj=j+1;
                        }
                    }
                    k--;
                }
            }
		}
	}
	cout << matrixi << " " << matrixj << endl;
    cout << max;
}
