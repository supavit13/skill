#include<stdio.h>
#include<math.h>
#include<time.h>
int *a;
FILE *cr,*ch;
struct record
{
       int value;
       struct record *next;
};
int menu()
{
    int x;
    printf("================\n");
    printf("===== MENU =====\n");
    printf("================\n");
    printf("1)Bubble Sort\n");
    printf("2)Shell Sort\n");
    printf("3)Radix Sort\n");
    printf("4)Quick Sort\n");
    printf("Please Enter >>");
    scanf("%d",&x);
    return x;
}
void bbs(int t[],int x)
{
    int i,j,tmp;
    for(i=1;i<=x;i++)
    {
      for(j=x-1;j>=i;j--)
      {
        if(t[j]<t[j-1])
        {
          tmp=t[j];
          t[j]=t[j-1];
          t[j-1]=tmp;
        }
      }
    }
}
void ss(int a[],int n)
{
     int j,i,m,mid;
     for(m = n/2;m>0;m/=2)
     {
          for(j = m;j< n;j++)
          {
               for(i=j-m;i>=0;i-=m)
               {
                   if(a[i+m]>=a[i])
                   break;
                   else
                   {
                       mid = a[i];
                       a[i] = a[i+m];
                       a[i+m] = mid;
                   }
               }
          }
     }
}
void rds(int *a,int n)
{
		int i,m=0,v=1;
		int * b=malloc(sizeof(int)*5000000);
		for(i=0;i<n;i++)
		{
			if(a[i]>m)
				m=a[i];
		}
		
		while(m/v>0)
		{
			int u[10]={0};
			for(i=0;i<n;i++)
				u[a[i]/v%10]++;
			for(i=1;i<10;i++)
				u[i]+=u[i-1];
			for(i=n-1;i>=0;i--)
				b[--u[a[i]/v%10]]=a[i];
			for(i=0;i<n;i++)
				a[i]=b[i];
			v*=10;
        }		
}
void quick( int t[], int i, int j)
{
     int left,cen,right,tmp;
     left=i;
     right=j;
     cen=t[(i+j)/2];
     do
     {
         while(cen > t[left])
         left++;
         while(t[right] > cen)
         right--;
         if(right >= left)
         {
             tmp=t[right];
             t[right]=t[left];
             t[left]=tmp;
             left++;
             right--;
         }
     }
     while(left < right);  
     if(i < right)
     quick(t,i,right);
     if(left < j)
     quick(t,left,j);
}
int main()
{
    struct record * p[10],*q[10],*r[10],*s[10],*temp;
    int input,x=0,i,cen;
   // int dis[30]; 
    char bub[20]={"bubble.dat"};
    char sh[20]={"shell.dat"};
    char ra[20]={"radix.dat"};
    char qu[20]={"quick.dat"};
    int * t = (int*) malloc(sizeof(int)*5000000);
    cr = fopen("data.dat","w+");
    srand(time(NULL));
    while(i<=5000000)// test 5000000 bubble slow
    {
        fprintf(cr,"%d ",rand()%1001);
        i++;
    }
    fclose(cr);  
    ch = fopen("data.dat","r");    
    while(fscanf(ch,"%d",&t[x++])==1)
    {}
    x--;
    fclose(ch);
    for(i=0;i<10;i++)
        p[i]=q[i]=r[i]=s[i]=NULL;
    switch(menu())
            {        
                     case 1 : bbs(t,x);
                              ch=fopen(bub, "w");
                              for(i=0;i<x;i++)
                              {
                                fprintf(ch, "%d ",t[i]);
                              }
                              fclose(ch); 
                              printf("Success!! >>> bubble.dat\n");
                              break;
                     case 2 : ss(t,x);
                              ch =fopen(sh, "w");
                              for(i=0;i<x;i++)
                              {
                                 fprintf(ch, "%d ",t[i]);
                              }
                              fclose(ch);
                              printf("Success!! >>> shell.dat\n");
                              break;
                     case 3 : rds(t,x);
                              ch = fopen(ra, "w");
                              for(i=0;i<x;i++)
                              {
                                fprintf(ch, "%d ",t[i]);
                              }
                              fclose(ch); 
                              printf("Success!! >>> radix.dat\n");
                              break;             
                     case 4 : quick( t, 0, x-1);
                              ch = fopen(qu, "w");
                              for(i=0;i<x;i++)
                              {
                                  fprintf(ch, "%d ",t[i]);
                              }
                              fclose(ch);
                              printf("Success!! >>> quick.dat\n");
                              break;    
            }
    system("pause");
}
