#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
}*adj[10];
int pass[10],d[10],pred[10],f[10];
int time = 0,count=0;
char a[30];
DFS(int u)
{  
   struct record *node;
   int v;
   pass[u] = 1;
   a[count++] = '(';//a[count] = '('; count ++;
   a[count++] = u+48;
   d[u] = ++time;
   node = adj[u];
   while(node!=NULL)
   {
      v = node->value;
      if(pass[v] == 0)
      {
        pred[v] = u;
        DFS(v);		
      }
      node=node->next;
   }
   pass[u] = 1;
   a[count++] = u+48;
   a[count++] = ')'; 
   f[u] = ++time;
}
void insert(int i,int n)
{
       struct record *node,*tmp;
       if(adj[i] == NULL)
         {
           adj[i]=(struct record *)malloc(sizeof(struct record));
           adj[i]->value = n;
           adj[i]->next = NULL;
         }
       else 
       {
            tmp=(struct record *)malloc(sizeof(struct record));
            tmp->value = n;
            node = adj[i];
            if(node->value > n)
            {
                tmp->next = adj[i];
                adj[i] = tmp;
            }
            else
            {
             while(node!=NULL)
             {
                 if(node->next==NULL)
                 {
                    node->next = tmp;
                    tmp->next = NULL; 
                    break;                
                 }
                 else if(n < node->next->value)
                 {
                      tmp->next = node->next;
                      node->next = tmp;
                      break;
                 }
                 node=node->next;
             }
            }
       }
} 
int main()
{
    int i,num,n;
    printf("Num ber of node : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)//set begin
   {
       pass[i] = 0;
       d[i] = -1;
       f[i] = -1;
       pred[i] = -1;
       adj[i] = NULL;
   }
   for(i=0;i<n;i++)//insert
   {
       printf("Adjacecy vertex %d : ",i);
       do 
       {
         scanf("%d",&num);
         if(num != -1)
         insert(i,num);
       }
       while(num != -1);  //-1 stop         
   }
   printf("\n");
   for(i=0;i<n;i++)
   {
      if(pass[i] == 0)
      {
           pred[i] = i;
           DFS(i);
      }
   }
   for(i=0;i<n;i++)
   {  
      printf("vertex%d : ",i);
      while(adj[i])
      {
        printf("%d ",adj[i]->value);
        adj[i] = adj[i]->next;
      }
      printf("\n");
   }
   printf("\n");
   printf("No|d|f|pred\n");
   printf("-----------\n");
    for(i=0;i<n;i++)
   {  
      printf("%d|%d|%d|%d|\n",i,d[i],f[i],pred[i]);
   }
   printf("\n");
   for(i=0;i<count;i++)
   {
      printf("%c ",a[i]);
   }
   printf("\n");
   system("pause");
 
}
