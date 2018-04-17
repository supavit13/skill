#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
       struct record *prev;
};
int menu()
{
    int x;
    printf("Menu\n");
    printf("1)Insert\n");
    printf("2)Print All Data(Min to Max)\n");
    printf("3)Print All Data(Max to Min)\n");
    printf("4)Delete\n");
    printf("5)Exit\n");
    printf("Enter Data>>");
    scanf("%d",&x);
    return x;
    system("pause");  
}
struct record *insert(struct record *head,int n)
{
    struct record *p,*t;
    p = malloc(sizeof(struct record));
    p->value = n;
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL)
        head = p;
    else
    {
        t = head;
        if(head->value>=n)
        {
            p->next = head;
            head->prev = p;
            head = p;
        }
        else
        {
            while(t)
            {
                if(t->next == NULL)
                {
                    t->next = p;
                    p->prev = t;
                    break;
                }
                else if(t->next->value>=n)
                {
                    p->next = t->next;
                    t->next = p;
                    p->prev = t;
                    p->next->prev = p;
                    break;
                }
                t = t->next;
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
            if(head!=NULL)
                head->prev = NULL;
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
                    if(p->next != NULL)
                        p->next->prev = p;
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
    return head;
}
void printall(struct record*head,int c)
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
int main()
{
    struct record *head=NULL;
    int n,num;
    while(1)
    {
            switch(menu())
            {
                     case 1:printf("Enter Number: ");
                            scanf("%d",&n);
                            head = insert(head,n);
                            break;
                     case 2:printf("Print All Data(Min to Max): ");
                            printall(head,1);
                            printf("\n");
                            break;
                     case 3:printf("Print All Data(Max to Min): ");
                            printall(head,0);
                            printf("\n");
                            break;
                     case 4:printf("Input Number: ");
                            scanf("%d",&num);
                            head = delete(head,num);
                            break;
                     case 5:exit(0);
                     default : printf("Please input only 1-5\n");
            }
    }
}
