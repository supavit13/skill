#include<iostream>
using namespace std;
bool between(int array[],int a,int b,int c)
{
    int p = 0;
    while(array[p] != b && array[p] != c)
        p++;
    while(1)
    {
        p++;
        if(array[p] == a)
            return true;
        else if(array[p] == b || array[p] == c)
            return false;
    }
}
int main()
{
    int round;
    cin >> round;
    for(int r=0;r<round;r++)
    {
    int n,m;
    cin >> n >> m;
    int array[n];
    bool check[n];
    for(int i=0;i<n;i++)
    {
        array[i] = i+1;
        check[i] = false;
    }
    int v[m][3];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[i][0] = a;
        if(b>c)
        {
			int tmp=c;
			c=b;
			b=tmp;
		}
        v[i][1] = b;
        v[i][2] = c;
        //while(!between(array,a,b,c))
        //{
            int x,y;
            for(int j=0;j<n;j++)
                if(array[j] == a && !check[a-1])
                {
                    x = j;
                    for(int k=0;k<n;k++)
                        if(array[k] == b || array[k] == c)
                            y = k;
                }
                else if(array[j] == a && check[a-1])
                {
                    y = j;
                    for(int k=0;k<n;k++)
                        if(array[k] == b || array[k] == c)
                            x = k;

                }
        while(!between(array,a,b,c))
        {
            if(x < y)
            {
                int temp = array[x];
                array[x] = array[x+1];
                array[x+1] = temp;
                x = x + 1;
            }
            else if(x > y)
            {
                int temp = array[x];
                array[x] = array[x-1];
                array[x-1] = temp;
                x = x - 1;
            }
            /*for(int j=0;j<n;j++)
                cout << array[j] << " ";
            cout << endl << "x : " << x << " y : " << y << endl;
            cin.get();*/
        }
        for(int i=0;i<n;i++)
            if(array[i] == a || array[i] == b || array[i] == c)
                check[i] = true;
        /*for(int j=0;j<n;j++)
                cout << array[j] << " ";
        cout << endl;*/
    }
    int sum = 0;
    for(int i=0;i<m;i++)
    {
        int a = v[i][0],b = v[i][1],c = v[i][2];
        if(between(array,a,b,c))
            sum++;
    }
    
    if(sum == m)
    {
        cout << "YES" << endl;
        for(int i=0;i<n;i++)
            cout << array[i] << " ";
    }
    else
        cout << "NO"<<endl;
    }
    //return 0;
}
