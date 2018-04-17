#include<stdio.h>
#include<stdlib.h>

struct node
{
       int data;
       struct node *next;
};

char cur[11],x[2];
int num[11];
struct node *head[11];

int findun(char y)
{
     int i=1;
     while(i!=11)
     {
         
         if(y == cur[i])
         {
              return i;
         }
         else
         {
             i++;
         }
         if(i == 11)
         {
              printf("Not found %c\n",y);
              return 0;
         }
     }
}

void un(int c1,int c2)
{
     struct node *tmp;
     tmp = (struct node*)malloc(sizeof(struct node));
     tmp->next = NULL;
     if(num[c1] ==  num[c2])
     {
         head[c1]->next = head[c2];
         num[c1] = num[c1]+num[c2];
         num[c2] = c1;
     }
     else
     {
         if(num[c1] < num[c2])
         {
             if(num[c2] > 0)
             {
                 c2 = num[c2];
                 head[c1]->next = head[c2];
                 num[c2] = num[c1]+num[c2];
                 num[c1] = c2;
             }
             else
             {
                 head[c2]->next = head[c1];
                 num[c1] = num[c1]+num[c2];
                 num[c2] = c1;
             }
         }
         else if(num[c1] > num[c2])
         {
             if(num[c1] > 0)
             {
                 c1 = num[c1];
                 head[c2]->next = head[c1];
                 num[c1] = num[c1]+num[c2];
                 num[c2] = c1;
             }
             else
             {
                 head[c1]->next = head[c2];
                 num[c2] = num[c1]+num[c2];
                 num[c1] = c2;
             }
         }
     }
}

int find(int c)
{
     if(num[c]<=0)
         return  c;
     else
         return find(num[c]);
}

main()
{
      char z;
      int i,j,c1=0,c2=0,a,b1,b2;
      for(i=1;i<11;i++)
      {
          cur[i] = 96+i;
          num[i] = -1;
          head[i] = (struct node*)malloc(sizeof(struct node));
          head[i]->data = cur[i];
          head[i]->next = NULL;
      }
      while(1)
      {
          printf("======================\n");
          printf("\tMenu\n");
          printf("======================\n");
          printf("1. Union (???????? union by size)\n");
          printf("2. Find\n");
          printf("3. Exit\n");
          printf("Please choose > ");
          scanf("%d",&a);
          getchar();
          printf("\n");
          if(a == 1)//union
          {
                   printf("U : ");
                   gets(x);
                   if(x[0] == x[2])
                   {
                       printf("It same !!!\n");
                   }
                   c1=c2=b1=b2=0;
                   c1 = findun(x[0]);
                   c2 = findun(x[2]);
                   b1 = find(c1);
                   b2 = find(c2);
                   if(b1 == b2)
                   {
                         printf("Same set! \n");
                   }
                   else
                   {
                       un(c1,c2);
                   }
                   printf("\n");
          }
          else if(a == 2)//find
          {
                   printf("Find : ");
                   scanf("%s",&z);
                   c1=0;
                   c1 = findun(z);
                   c1 = find(c1);
                   printf("Output : %c\n",cur[c1]);
                   printf("\n");
          }
          else if(a ==3)//exit
          {
                   exit(1);
          }
          else
          { 
              printf("Please choose 1-3.\n");
          }
      printf("\n");
      }
      getch();
}
