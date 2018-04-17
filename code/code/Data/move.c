#include<stdio.h>
#include<math.h>
/*int main()
{
    FILE * cr;
 int r,i,e=101,x=45,m=667;
   r = (x*x)%m;
   for(i=1;i<=e-2;i++)
   {
        r = (r*x)%m;
   }
  // cr = fopen("codein.txt","a");
   printf("%d ",r);
   system("pause");
}


int primetest(int n)
{
   int i;
   for(i=2;i<=(int)sqrt((float)n);i++)
   {
       if(n%i==0)
       return 0;
   }
   return 1;
}
int main()
{
    int i;
    for(i=100;i<=670;i++)
    {
        if(primetest(i))
        {
            printf("%d ",i);
        }
    }
    system("pause");
}*/
int main()
{
  int x,i,r=643,m=667,d=61;
   x = (r*r)%m;
   for(i=1;i<=d-2;i++)
   {
        x = (x*r)%m;
   }
   printf("%d ",x);
   system("pause");
}
/*
{
    int sum = 191031,d =338187,m=502561,x,i;
 x = sum;
 for(i = 1;i < d; i++)
            {
                x = (x * sum) % m;
            }
            printf("%d",x);
            system("pause");
}*/

/*int main()
{
    int r = 191031,d =338187,m=502561,x,i;
 x = r;
 for(i = 1;i < d; i++)
            {
                x = (x * r) % m;
            }
            printf("%d",x);
            system("pause");
}
#include<stdio.h>
int main()
{
    char a[1000];
    int i=0,j=0;;
    FILE *fp;
    fp = fopen("input.txt","r"); 
    char c=fgetc(fp);
    while(c != EOF)
    { 
       
            a[i++]=c;       
            c=fgetc(fp); 
            j++;
    }
    for(i=1;i<j;i++)
    {
      printf("%c",a[i]);
    }
}*/
/*
#include<string.h>

void find_x(int r, int d, int m , FILE *o2)
{
    int x=1;
    int i;
    char data;
for (i=0;i<d;i++)
  {
      x = (x* r )%m;
  }


   x = (r*r)%m;
   for(i=1;i<=d-2;i++)
   {
        x = (x*r)%m;
   }

      if( x>=00 && x<=99 )
      {
      if ( x == 26 )
      {
      data = 'a';
      fprintf(o2,"%c",data);
      } 
      else if ( x == 25 )
      {
      data = 'b';
      fprintf(o2,"%c",data);
      }
      else if ( x == 24 )
      {
      data = 'c';
      fprintf(o2,"%c",data);
      }
      else if ( x == 23 )
      {
      data = 'd';
      fprintf(o2,"%c",data);
      }
      else if ( x == 22 )
      {
      data = 'e';
      fprintf(o2,"%c",data);
      }
      else if ( x == 21 )
      {
      data = 'f';
      fprintf(o2,"%c",data);
      }
      else if ( x == 20 )
      {
      data = 'g';
      fprintf(o2,"%c",data);
      }
      else if ( x == 19 )
      {
      data = 'h';
      fprintf(o2,"%c",data);
      }
      else if ( x == 18 )
      {
      data = 'i';
      fprintf(o2,"%c",data);
      }
      else if ( x == 17 )
      {
      data = 'j';
      fprintf(o2,"%c",data);
      }
      else if ( x == 16 )
      {
      data = 'k';
      fprintf(o2,"%c",data);
      }
      else if ( x == 15 )
      {
      data = 'l';
      fprintf(o2,"%c",data);
      }
      else if ( x == 14 )
      {
      data = 'm';
      fprintf(o2,"%c",data);
      }
      else if ( x == 13 )
      {
      data = 'n';
      fprintf(o2,"%c",data);
      }
      else if ( x == 12 )
      {
      data = 'o';
      fprintf(o2,"%c",data);
      }
      else if ( x == 11 )
      {
      data = 'p';
      fprintf(o2,"%c",data);
      }
      else if ( x == 10 )
      {
      data = 'q';
      fprintf(o2,"%c",data);
      }
      else if ( x == 31 )
      {
      data = 'r';
      fprintf(o2,"%c",data);
      }
      else if ( x == 32 )
      {
      data = 's';
      fprintf(o2,"%c",data);
      }
      else if ( x == 33 )
      {
      data = 't';
      fprintf(o2,"%c",data);
      }
      else if ( x == 34 )
      {
      data = 'u';
      fprintf(o2,"%c",data);
      }
      else if ( x == 35 )
      {
      data = 'v';
      fprintf(o2,"%c",data);
      }
      else if ( x == 36 )
      {
      data = 'w';
      fprintf(o2,"%c",data);
      }
      else if ( x == 37 )
      {
      data = 'x';
      fprintf(o2,"%c",data);
      }
      else if ( x == 38 )
      {
      data = 'y';
      fprintf(o2,"%c",data);
      }
      else if ( x == 39 )
      {
      data = 'z';
      fprintf(o2,"%c",data);
      }
      else 
      {
      data = 'm';
      fprintf(o2,"%c",data);
      }

}

int main()
{
    FILE *oFile;
    FILE *o2;
    int d,m,r,x;
    printf ("RSA decoder\n");
    printf ("Enter d : ");
    scanf ("%d",&d);
    printf ("Enter m : ");
    scanf ("%d",&m);
    oFile = fopen ("output.txt","r"); 
    o2 = fopen ("output2.txt","w");  
    while((fscanf(oFile,"%d",&r))!=EOF)
    {find_x(r,d,m,o2);
// close file     
    fclose (oFile);
    fclose (o2);
// end close file
    getch();
}
int dp=0,*b_a;
int gcd(int b,int c)
{
    dp++;
    if(b==0)
       return c; 
    return gcd(c%b,b);
}
int gcd2(int b,int c)
{
    if(b!=0)
        b_a[dp++] = c/b;
    if(b==0)
       return c;
    else
    {   
        return gcd2(c%b,b);
    }
}

int main()
{
    int n,b,i,j=0,k=0,*t,count=0,p,q,tmp,e,m,o,u=101,v=616,tmp_s,tmp_t,ss,tt,f,x,ee,mm,y=0,z=0;
     b_a = malloc(dp*sizeof(int));
         dp = 0;
         gcd2(u,v);
         ss = 1,tt = 0;
         for(i=dp-2;i>=0;i--)
         {
            tmp_s = tt - ss*(b_a[i]);
            tmp_t = ss;
            ss = tmp_s;
            tt = tmp_t;
         }
         f = ss%v;
         if(f<0)
         {
             f = v+ss;
             printf("e = %d,d = %d \n",u,f);
         }
         else
         {
             printf("e = %d,d = %d \n",u,f);
         }
         system("pause");
}
*/
