#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
}*adj[10];
int pass[10],d[10],pred[10];
struct record *q = NULL;
void enq (int n)
{
     struct record *p,*tmp;
     if(q == NULL)
     {
          q = (struct record *)malloc(sizeof(struct record));
          q->value = n;
          q->next = NULL;
     }
     else
     {
         p = q;
         while(p)   
         {
              if(p->next==NULL)
              {
                 tmp = (struct record *)malloc(sizeof(struct record));
                 tmp->value = n;
                 tmp->next = NULL;
                 p->next = tmp;
                 break;
              }
              p = p->next;
         }
      }               
}
void deq ()
{
      struct record *first;
      first = q;
      q = q->next;
      free(first);
}
BFS()
{
   int u,v;
   struct record *node;
     while(q != NULL)
     { 
        u = q->value;
        node = adj[u];
        while(node != NULL)
        {
            v = node->value;
            if(pass[v] == 0)
            {
               pass[v] = 1;
               d[v] = d[u]+1;
               pred[v] = u;
               enq(v);
            }
          node = node->next;
        }
     deq();
   }
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
void path(int a,int num)
{
     if(pred[a] != num)
     {
        path(pred[a],num);
        printf(",%d",pred[a]);     
     }
     else
    printf("%d",num);
}    
int main()
{
    int n,i,num;
    printf("Number of Node = ");
    scanf("%d",&n);
    for(i=0;i<n;i++)//set begin
   {
       pass[i] = 0;
       d[i] = -1;
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
   printf("Input Start Node : ");
   scanf("%d",&num);
   enq(num);
   pass[num] = 1; //set start node
   d[num] = 0;
   pred[num] = num;
   BFS();
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
   printf("Distance\n");
   for(i=0;i<n;i++)
   {
       printf("from %d to %d : %d\n",num ,i ,d[i]);
       if(i!=num)
       {
          printf("path(");
          path(i,num); 
          printf(",%d)\n",i);  
       }
       else
       printf("path -\n");   
   }
    system("pause");
}

  

