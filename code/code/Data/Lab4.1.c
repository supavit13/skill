#include<stdio.h>
#include<stdlib.h>
struct record
{
    int value;
    struct record *next; 
};
struct record *create()
{
    struct record *s;
    s = (struct record*)malloc(sizeof(struct record));
    s->next = NULL;
    return s;
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
int push(struct record *s,char c)
{     
      struct record *t;
      t = (struct record *)malloc(sizeof(struct record));
      t->value = c;
      t->next = s->next;
      s->next = t;
      return s;
}
int pop(struct record *s)
{
      struct record *f;
      f = s->next;
      s->next = s->next->next;
      free(f);
      return s;
}
int top(struct record *s)
{
     if(s->next != NULL)
         return s->next->value;
     else
         return 0;
}
int main()
{ 
    char s1[10];
    int i=0;
    struct record *s;
    s = create();
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
              while(map(top(s))!= -1)
              {
                 printf("%c",top(s));
                 pop(s);
              } 
              pop(s);
            }
           else if(s->next == NULL || map(top(s)) < map(s1[i])||map(s1[i])== -1)
            {
                 push(s,s1[i]);
            }
            else
            {
                while(map(s1[i]) <= map(top(s)) && top(s)!=NULL)
                {
                    if(map(top(s))!= 0)         
                    printf("%c",top(s));
                    pop(s);
                }
                push(s,s1[i]);
            }
        }           
         i++;        
    }
    while(s->next!=NULL)
    {
       if(map(top(s))!= 0)
       printf("%c",top(s));
       pop(s);
    } 
    printf("\n"); 
    system("pause");
}
