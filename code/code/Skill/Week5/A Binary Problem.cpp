#include<iostream>
#include<vector>

using namespace std;
vector <int> Binary;

int calculate(int Copy)
{
    int c=0;
    while(1)
    {
       if(Copy%2==1)
            c++;
       if(Copy/2>=1)
            Copy=Copy/2;
       else
       {
          //Binary.push_back(I);   
          break;
       }
    }
    return c;
    
}
int main()
{
    while(1)
    {
        int I,count=0,Copy,countsame=0;
        cin>>I;
        if(I==0)
            return 0;
        else
        {
            Copy=I+1;
            while(1)
            {
               
               Binary.push_back(I%2); 
               if(I%2==1)
                    count++;
               if(I/2>=1)
                    I=I/2;
               else
               {
                  //Binary.push_back(I);   
                  break;
               }
            }
            while(1)
            {
                countsame=calculate(Copy);
                if(countsame==count)
                {
                    cout<<Copy<<endl;
                    break;
                }
                else
                    Copy++;
            }

        }
    }
       // system("pause");
}
