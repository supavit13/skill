#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record
{
       int value;
       struct record *next;
};
int a=0;
struct record *insert(struct record *head,int n)
{
       struct record *p,*t;
       p = malloc(sizeof(struct record));
       p->value = n;
       p->next = NULL;
       if(head == NULL)
             head = p;
       else
        {
             t = head;
             if(t->value >= n)//insert front
              {
                 p->next = head;
                 head = p;
              }
             else
              {
                 while(t)
                 {
                   if(t->next == NULL)
                    {
                       t->next = p;
                       break;
                    }
                   else if(t->next->value >= n )
                    {
                       p->next = t->next; 
                       t->next = p;  
                       break;  
                    }
                    t=t->next;
                 }
            }
         }
         return head;
}
struct record *delete(struct record *head,int n)
{
    int b = 0;
    struct record *p = head;
    if(head != NULL)
    {
        if(head->value == n)
        {
            head = head->next;
            free(p);
            b = 1;
        }
        else
        {
            while(p->next)
            {
                if(p->next->value == n)
                {
                    p->next = p->next->next;
                    b = 1;
                    break;
                }
                p = p->next;
            }
        }
    }
    if(b == 1)
        printf("Delete success\n");
    else
        printf("Can't delete , no node\n");
    a-=b;
    return head;
}
void printhalf(struct record* head)
{
    struct record * p = head;
    int i;
    printf("First half : ");
    for(i=0;i<a/2;i++,p=p->next)
        printf("%d ",p->value);
    printf("\nLast half : ");
    for(;i<a;i++,p=p->next)
        printf("%d ",p->value);
    printf("\n");
}
void headAndlast(struct record* head)
{
    struct record * p = head;
    printf("First node : %d\n",p->value);
    while(p->next)p = p->next;
    printf("Last node : %d\n",p->value);
}
void printall(struct record *head,int c)
{
    if(head)
    {
        if(c == 1)
        {
            printf("%d ",head->value);
            printall(head->next,1);
        }
        else if(c == 0)
        {
            printall(head->next,0);
            printf("%d ",head->value);
        }
    }
}
int menu()
{
    int x;
    printf("MENU\n");
    printf("1)Insert\n");
    printf("2)Print All Data\n");
    printf("3)Print Half And Half\n");
    printf("4)Delete\n");
    printf("5)Print first node and Last node\n");
    printf("6)Print Reverse data(Max to Min)\n");
    printf("7)Exit\n");
    printf("Enter Data>>");
    scanf("%d",&x);
    return x;
    system("pause");
}
int main()
{
    struct record *head=NULL;
    int n,num;
    while(1)
    {
            switch(menu())
            {
                     case 1 : printf("Enter Number: ");
                              scanf("%d",&n);
                              head = insert(head,n);
                              a++;
                              break;
                     case 2 : printf("All Data(Min to Max): ");
                              printall(head,1);
                              printf("\n");
                              break;
                     case 3 : printhalf(head);
                              break;
                     case 4 : printf("Input Number: ");
                              scanf("%d",&num);
                              head = delete(head,num);
                              break;
                     case 5 : headAndlast(head);
                              break;
                     case 6:  printf("Reverse : ");
                              printall(head,0);
                              printf("\n");
                              break;
                     case 7 : exit(0); 
                     default : printf("Please input only 1-7\n");         
            }      
    } 
}
    
