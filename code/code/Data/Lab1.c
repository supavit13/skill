#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
};
int function_menu()
{
    int x;
    printf("Menu\n");
    printf("1)Insert\n");
    printf("2)Print All Data(Min to Max)\n");
    printf("3)Print First Node And Last Node\n");
    printf("4)Print Reverse Data(Max to Min)\n");
    printf("5)Exit\n");
    printf("Enter Data>");
    scanf("%d",&x);
    return x;
    system("pause");
         
}
struct record *insert(struct record *head,int n)
{
       struct record *node,*tmp;
       if(head == NULL)
         {
           head=(struct record *)malloc(sizeof(struct record));
           head->value = n;
           head->next = NULL;
         }
       else 
       {
            tmp=(struct record *)malloc(sizeof(struct record));
            tmp->value = n;
            node = head;
            if(node->value > n)
            {
                tmp->next = head;
                head = tmp;
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
       return head;
}
struct record *recur(struct record *head)
{
       if(head->next==NULL)
       {
           printf("%d ",head->value);
           return head;
       }
       else
       {
           head->next = recur(head->next);
           printf("%d ",head->value);
           return head;
       }
}
void printall(struct record *head)
{
     struct record *node;
     node=head;
     if(node!=NULL)
     {
        while(node)
        {
                   printf("%d ",node->value);
                   node=node->next;
        }
        printf("\n");
     }
     else
     printf("List Empty!!!\n");
}
void printtop(struct record *head)
{
    int a=0;
    printf("%d ",head->value);
    while(head->next!=NULL)
    {
       head=head->next;
       a++;                    
    }
    if(a!=0)
    {
           printf("Last Node %d\n",head->value); 
    }
    else    
    printf("Last Node No List");
 }
int main()
{
  struct record *tmp, *node, *p, *head=NULL;
  int num,data,x;
  while (1)
  {
        x=function_menu();
        switch(x)
         {
                 case 1 : printf("Enter number: ");
                          scanf("%d",&data);
                          head = insert(head,data);
                          break;
                 case 2 : printf("All Data(Min to Max): ");
                          printall(head);
                          break;
                 case 3 : printf("First Node ");
                          printtop(head);
                          break;
                 case 4 : printf("Reverse Data(Max to Min): ");
                          head=recur(head);
                          printf("\n");
                          break;
                 case 5 : exit(0);
                 }
 }
}


    
    

