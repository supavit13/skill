#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
};
struct record *s;
struct record *cs()
{
      s = (struct record *)malloc(sizeof(struct record));
      s->next = NULL;
      return s;
}
void push(char c)
{     struct record *t;
      t = (struct record *)malloc(sizeof(struct record));
      t->value = c;
      t->next = s->next;
      s->next = t;
}
void pop()
{
      struct record *f;
      f = (struct record *)malloc(sizeof(struct record));
      f = s->next;
      s->next = s->next->next;
      free(f);
}
void top()
{
      if(s->next != NULL)
      {
                 printf("%c\n",s->next->value);
      }
      else  
                 printf("No Data\n");
}     
int menu()
{
    int x;
    printf("MENU\n");
    printf("1)Push\n");
    printf("2)Pop\n");
    printf("3)Top\n");
    printf("4)Exit\n");
    printf("Enter Choice >>");
    scanf("%d",&x);
    return x;
    system("pause");
}
int main()
{
    
    int num;
    char c;
    s = cs();
    while(1)
    {       
            switch(menu())
            {        
                     case 1 : printf("Input Character : ");
                              scanf("%s",&c);
                              push(c);
                              break;
                     case 2 : if(s->next!=NULL)
                              {
                                 pop();
                              }
                              else
                              {
                                printf("List Empty!!\n");    
                              }
                              break;
                     case 3 : top();
                              break;              
                     case 4 : exit(0);  
            }
    } 
    system("pause"); 
}
