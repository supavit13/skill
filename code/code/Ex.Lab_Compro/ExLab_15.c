#include<stdio.h>
#include<string.h>
struct point
{
  char name[30];
  int mid;
  int fin;
}p[5];
int main()
{
    int a=0,i,max_mid,tmid,max_fin,tfin,sum=0;
	float mean_fin,mean_mid;
    for(i=0;i<5;i++)
    {
      printf("%d) Name : ",i+1);
      gets(p[i].name);
      printf("Midterm : ");
      scanf("%d",&p[i].mid);
      printf("Final : ");
      scanf("%d",&p[i].fin);
	  getchar();
	}
	//Mid
	max_mid = p[0].mid;
	for(i=0;i<5;i++)
	{
		if(p[i].mid > max_mid)
		{
			max_mid = p[i].mid;
			tmid = i;
		}
	}
    for(i=0;i<5;i++)
	{
		sum = sum + p[i].mid;
		a++;
	}
	mean_mid = (float)sum/a;
	//final
	max_fin = p[0].fin;
	for(i=0;i<5;i++)
	{
		if(p[i].fin > max_fin)
		{
			max_fin = p[i].fin;
			tfin = i;
		}
	}
    for(i=0;i<5;i++)
	{
		sum = sum + p[i].fin;
		a++;
	}
	mean_fin = (float)sum/a;
	//out
	printf("Midterm :\n");
	printf("Mean = %.2f\n",mean_mid);
	printf("Top'name : %s\n",p[tmid].name);
	printf("Score : %d\n",max_mid);
	printf("\n");
	printf("Final :\n");
	printf("Mean = %.2f\n",mean_fin);
	printf("Top'name : %s\n",p[tfin].name);
	printf("Score : %d\n",max_fin);
	system("pause");
}
