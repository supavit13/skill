#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
};
struct record *tail;
struct record *insert(struct record *head,int n)
{
       struct record *node;
       node =(struct record *)malloc(sizeof(struct record));
       node->value = n;
       node->next = NULL;
       
       if(head == NULL)
       {
               head = node;
               tail = node;
       }
       else
       {
           tail->next = node;
           tail = tail->next;
           tail->next = head;
       }
   return head;           
}
void run(int m,int n)
{
     struct record *tmp;
     int x;
     printf("If M = %d and N = %d ,the order of elimitnation is ",m,n);
     while(n!=1)
     {
        x=0;
        while(x!=m)
        {
           tail = tail->next;
           x++;
        }
        printf("%d",tail->next->value);
        tmp = tail->next;
        tail->next = tail->next->next;
        free(tmp);
        n--;
        if(n==1)
           printf(".");
        else
           printf(",");
     }
     printf("\n");
 }
int main()
{
    struct record *tmp, *node, *head=NULL;
    int m,n,i;
    printf("The Josephus Problem\n");
    printf("Input number of passed(M) : ");
    scanf("%d",&m);
    printf("\n");
    printf("Input number of people(N) : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
               head = insert(head,i);         
    }
    node = head;
    run(m,n);
    system("pause");
}
