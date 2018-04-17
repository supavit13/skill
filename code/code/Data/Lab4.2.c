#include<stdio.h>
#include<stdlib.h>
int c = 1;
struct record
{
       int value;
       struct record *next;
};
struct record *enqueue (struct record *s,int n)
{
     struct record *p,*tmp;
     if(s == NULL)
     {
          s = (struct record *)malloc(sizeof(struct record));
          s->value = n;
          s->next = NULL;
     }
     else
     {
         p = s;
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
      return s;         
}
struct record *dequeue (struct record *s)
{
      struct record *first;
      first = s;
      s = s->next;
      free(first);
      return s;    
}
void printall(struct record *q)
{
     if(q == NULL)
     {
                 printf("Empty!!!");
     }
     else
     {
         while(q)
         {
                 printf("%d ",q->value);
                 q = q->next;
         }
     }
     printf("\n");
}
int function_menu()
{
    int x;
    printf("Menu\n");
    printf("1)Enqueue\n");
    printf("2)Dequeue\n");
    printf("3)Print queue\n");
    printf("4)Exit\n");
    printf("Enter Data>>");
    scanf("%d",&x);
    return x; 
}
int main()
{
    struct record *q = NULL,*node;
    int x,n,i,a;
    while(1)
    {
            x=function_menu();
            switch(x)
            {
                     case 1:printf("Input : ");
                            scanf("%d",&n);
                            if(c == 6)
                            {
                                printf("Error-> Q Full!!!");
                                printf("\n");
                            }
                            else
                            {
                                 c++;
                                 q = enqueue(q,n);     
                            }
                             printf("Queue f->r : ");
                             node = q;
                            while(node)
                             {
                                 printf("%d ",node->value);
                                 node = node->next;
                             }
                            printf("\n");
                            break;
                     case 2:printf("Dequeue :");
                            if(q == NULL)
                            {
                                 printf("Queue Empty\n");
                            }
                            else
                            {
                                 printf("%d",q->value);
                                 q = dequeue(q);
                                 printf("\n");
                                 c--;
                            }
                            break;
                     case 3:printf("Queue : ");
                            printall(q);
                            break;
                     case 4:exit(0);
            }
    }
    system("pause");
}
