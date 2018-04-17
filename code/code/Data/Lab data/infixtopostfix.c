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
    s = (struct record*)malloc(sizeof(struct record));
    s->next = NULL;
    return s;
}

int push(char c)
{     
      struct record *t;
      t = (struct record *)malloc(sizeof(struct record));
      t->value = c;
      t->next = s->next;
      s->next = t;
      return s;
}
int pop()
{
      struct record *f;
      f = s->next;
      s->next = s->next->next;
      free(f);
      return s;
}
int top()
{
     if(s->next != NULL)
         return s->next->value;
     else
         return 0;
}
int map(char c)
{
    switch(c)
    {
         case'(' : return -1;
                   break;
         case')' : return 0;
                   break;
         case'+' : return 1;
                   break;
         case'-' : return 1;
                   break;
         case'*' : return 2;
                   break;
         case'/' : return 2;
                   break; 
         case'%' : return 2;
                   break;
    }
}
int main()
{ 
    char s1[10];
    int i=0;
    s = cs();
    printf("Input : ");
    scanf("%s",&s1[i]);
    printf("Output : ");
    while(s1[i]!='\0')
    {
        if(s1[i]>='0' && s1[i]<='9')
             printf("%c",s1[i]);
        else
        {
            if(map(s1[i])==0)
            {
              while(map(top())!= -1)
              {
                 printf("%c",top());
                 pop();
              } 
              pop();
            }
           else if(s->next == NULL || map(top()) < map(s1[i])||map(s1[i])== -1)
            {
                 push(s1[i]);
            }
            else
            {
                while(map(s1[i]) <= map(top()) && top()!=NULL)
                {
                    if(map(top())!= 0)         
                    printf("%c",top());
                    pop();
                }
                push(s1[i]);
            }
        }           
         i++;        
    }
    while(s->next!=NULL)
    {
       if(map(top())!= 0)
       printf("%c",top());
       pop();
    } 
    printf("\n"); 
    system("pause");
}
