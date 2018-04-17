#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
struct record
{
    char data[40];
    long int id;
    struct record *next;
};

long int key;
int m=101;
struct record *head[101];

int has(long int x,int k)
{
    int p;
    p = (x + (k*k)) % m;
    if(head[p] == NULL)
    {
        return p;
    }
    else
    {
        k++;
        return has(p,k);
    }
}

int ck(long int x,int k)
{
    int p;
    p = (x + (k*k)) % m;
    if(head[p] == NULL)
    {
        return -1;
    }
    else if(head[p] != NULL && key == head[p]->id)
    {
return p;
    }
    else
    {
        k++;
        return ck(p,k);
    }
}

void insert(int pass,char name[])
{
     struct record *tmp,*p;
     tmp = (struct record *)malloc(sizeof(struct record));
     strcpy(tmp->data, name);
     tmp->id = key;
     tmp->next = NULL;
     if(head[pass] == NULL)
     {
         head[pass] = tmp;
     }
}
main()
{
      int a,pass,i;
      long int k;
      FILE *r;
      char name[40];
      for(i=0;i<101;i++)
      {
          head[i] = NULL;
      }
      r = fopen("h.dat","r");
      while(1)
      {
               printf("MENU\n");
               printf("1) Insert\n");
               printf("2) Delete\n");
               printf("3) Exit\n");
               printf("Please choose > ");
               scanf("%d",&a);
  printf("\n");
               if(a == 1)
               {
                    while(fscanf(r,"%ld",&key)!=EOF)
                    {
                        k = key;
                        pass = has(k,0);
                        fgets(name, 40, r);
                        insert(pass,name);
                    }
                    fclose(r);
                    printf("\n");
               }
   
               else if(a == 2)
               {
                    printf("Insert Key : ");
                    scanf("%ld",&key);
                    k = key;
                    if(ck(k,0)==-1)
                    {
                        printf("Not found!!!\n");
                    }
                    else
                    {
                        head[ck(k,0)]=NULL;
                        printf("Data Delete!");
 }
                    printf("\n");
               }
               else if(a == 3)
               {
                    exit(1);
               }
               else
               {
                   printf("Please choose 1-3.\n");
               }
      }
      return 0;
}
