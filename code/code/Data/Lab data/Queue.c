#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
};
struct record *s;
struct record *enq(int n)
{
    struct record *t,*p;
    t = malloc(sizeof(struct record));
    t->value = n;
    t->next = NULL;
    if(s == NULL)
        s = t;
    else
    {
        p = s;
        for(;p->next;p=p->next);
        p->next = t;
    }
    return s;
}
struct record *deq()
{
      struct record *f;
      f = s;
      s = s->next;
      free(f);
      return s;    
}
void printall(struct record *h)
{
    if(h)
    {
            printf("%d ",h->value);
            printall(h->next);
    }
}
int menu()
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
    struct record *q = NULL;
    int n,i=0;
    while(1)
    {
            switch(menu())
            {
                     case 1:if(i!=5)
                            {
                                printf("Enter number : ");
                                scanf("%d",&n);
                                q = enq(n);
                                i++;
                                if(i==1)
                                    printf("Queue f->r : %d\n",q->value);
                                else
                                 {
                                      printf("Queue : ");
                                      printall(q);
                                      printf("\n");
                                 }
                            }
                            else
                            {
                                printf("Q Full!!\n");
                                printf("Queue : ");
                                printall(q);
                                printf("\n");
                            }
                            break;
                    case 2:if(i!=0)
                            {
                                printf("Dequeue : %d ",q->value);
                                q = deq(q);
                                i--;
                                printf("\n");
                            }
                            else
                                printf("Q Empty!!\n");
                           break;
                    case 3:printf("Queue : ");
                           printall(q);
                           printf("\n");
                           break;
                    case 4:exit(0);
                           break;
                    default : printf("Please input only 1-5");
            }
    }
    system("pause");
}
