#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
};

//insert
struct record *insert(struct record *head,int n)
{
       struct record *tmp;
       if(head==NULL)
       {   
          head=malloc(sizeof(struct record));
          head->value=n;
          head->next=NULL;
       }
       else if(head->value < n)
       {
          tmp=malloc(sizeof(struct record));
          tmp->value=n;
          tmp->next=head;
          head=tmp;
       }
       else
       {
           p=head;
           while(tmp->next->value > n)
           }
           tmp=tmp->next;
           }
    return head;
    
}
int main()
{
    struct record *head=NULL, *p;
    int num,n;
    printf("1)Insert\n");
    scanf("%d",&num);
    if(num==1)
    {       
            scanf("%d",&n);
            head=insert(head,n);
    }
    //print all
    p=head;
    while(p!=NULL)
    {
                  printf("%d",p->value);
                  p=p->next;
    }
    system("pause");
}
