#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
       struct record *prev;
};
int function_menu()
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
struct record *tail;
struct record *insert(struct record *head,int n)
{
       struct record *tmp,*node;
       if(head==NULL)
       {
             head=malloc(sizeof(struct record));
             head->value=n;
             head->next=NULL;
             head->prev=NULL;
             tail=head;        
       }
       else
       {
           tmp=malloc(sizeof(struct record));
           tmp->value = n;
           node = head;  
                if(n < head->value)   //front
                {
                   tmp->next=head;
                   head->prev=tmp;
                   tmp->prev = NULL;
                   head = tmp;  
                }
                else
                {
                    while(node!=NULL)
                    {
                       if(node->next==NULL)    //last
                       {
                            node->next=tmp;
                            tmp->prev= node;
                            tmp->next=NULL;
                            tail=tmp;
                            break;
                       }
                       else if(n < node->next->value) //middle
                       {
                            tmp->next=node->next;
                            node->next=tmp; 
                            tmp->prev=node;
                            tmp->next->prev=tmp;
                            break;
                       }
                       node=node->next;
                    }
                }
         }
               return head;
} 
struct record *delete(struct record *head,int num)
{
    struct record *tmp,*node;
    node = head;
    if(node->value == num)
    {
        tmp = node;
        node = node->next;
        if(node!=NULL) //gun buck list have 1 number
        {
            node->prev=NULL;
            free(tmp);
        }
        else
        {
            tail=NULL;
            free(tmp);
        }
        return node;
    }
    else
    {
        while(node->next!=NULL)
        {
            if(node->next->value == num)
            {
                tmp = node->next;
                if(tmp->next==NULL)
                {
                   node->next = NULL;
                   tail = node;
                   free(tmp); 
                   return head;             
                }
                tmp->next->prev = node;
                node->next = tmp->next;
                free(tmp);
                return head;
            }
            node = node->next; 
        }
       return node;
    }
    return head;
}
void printall(struct record *head)
{
     struct record *node;
     node=head;
     while(node)
     {
                printf("%d ",node->value);
                node = node->next;
     }
     printf("\n");
}
void printreverse(struct record *s)
{
     while(s!=NULL)
     {
                   printf("%d ",s->value);
                   s = s->prev;              
     }
     printf("\n");
}  
int main()
{
    struct record *head=NULL;
    int n,num;
    while(1)
    {
            switch(function_menu())
            {
                     case 1:printf("Enter Number: ");
                            scanf("%d",&n);
                            head = insert(head,n);
                            break;
                     case 2:printf("Print All Data(Min to Max): ");
                            printall(head);
                            break;
                     case 3:printf("Print All Data(Max to Min): ");
                            printreverse(tail);
                            break;
                     case 4:printf("Input Number: ");
                            scanf("%d",&num);
                            head = delete(head,num);
                            break;
                     case 5:exit(0);
            }
    }
}
