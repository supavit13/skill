#include<iostream>
using namespace std;
int convert_mile(int m)
{
    m = m*63360;
    return m;
}
int convert_yard(int y)
{
    y = y*36;
    return y;
}
int convert_feet(int f)
{
    f = f*12;
    return f;
}
int main()
{
    int t,r1[5],r2[5],m,y,f,in;
    cin>>t;
    for(int i=0;i<t;i++)
    {
      int tmp=0,tmp1=0,result=0;
      for(int j=0;j<4;j++)
      {
         cin>>r1[j];
      }
      for(int k=0;k<4;k++)
      {
         cin>>r2[k];
      }
      tmp=tmp+convert_mile(r1[0]);
      tmp=tmp+convert_yard(r1[1]);
      tmp=tmp+convert_feet(r1[2]);
      tmp=tmp+r1[3];
      
      tmp1=tmp1+convert_mile(r2[0]);
      tmp1=tmp1+convert_yard(r2[1]);
      tmp1=tmp1+convert_feet(r2[2]);
      tmp1=tmp1+r2[3];
      
      if(tmp1>tmp)
          result=tmp1-tmp;
      else
          result=tmp-tmp1;
         
      m=result/63360;
      result=result%63360;
      y=result/36;
      result=result%36; 
      f=result/12;
      result=result%12;
      in=result;
      cout<< m << " " << y << " " << f << " " << in <<endl;     
    }  
}
