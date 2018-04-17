#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int GCD(int y, int z)
{
    if(z == 0)
        return y;
    else
        return GCD(z, y%z);
}

int main()
{
	int red, green, i, sum;
	cin>>red>>green;
	sum = GCD(red, green);
	if(sum == 1)
	    cout<<1<<" "<<red<<" "<<green<<endl;
	else
	{
		vector<int> d;
        int rounds = sum, tmp1, tmp2, tmp3;

        for(i=1;i<rounds;i++)
        {
            if(sum % i == 0)
            {
                tmp1 = red/i, tmp2 = green/i, tmp3 = GCD(tmp1, tmp2);
                cout<<i<<" "<<tmp1<<" "<<tmp2<<endl;
                if(tmp3 == i)
                    break;
                d.push_back(tmp3);
                rounds = tmp3;
            }
		}
        rounds = d.size();
        for(i=rounds - 1;i>=0;i--)
            cout<<d[i]<<" "<<red/d[i]<<" "<<green/d[i]<<endl;
	}
}
