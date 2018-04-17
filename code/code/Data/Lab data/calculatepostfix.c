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
      s = malloc(sizeof(struct record));
      s->next = NULL;
      return s;
}
void push(int b)
{     struct record *t;
      t = malloc(sizeof(struct record));
      t->value = b;
      t->next = s->next;
      s->next = t;
}
int pop()
{
     struct record *tmp;
     int a;
     tmp = s;
     tmp = tmp->next;
     a = tmp->value;
     s->next = s->next->next;
     free(tmp);
     return a;        
}
int main()
{
    int b,c,sum;
    s = cs();
    char s1;
    printf("Input : ");
    while(1)
    {
         scanf("%c",&s1);
         if(s1 == '\n')
              break;
            if(s1 >= '0' && s1 <= '9')
            {
                b = s1-48;// change to integer
                push(b);          
            }
            else
            {
                switch(s1)
                {
                             case '+' : b = pop();
                                        c = pop();   //c is top
                                        sum = c+b;                                  
                                        push(sum);
                                        break;
                             case '-' : b = pop();
                                        c = pop();
                                        sum = c-b;                                  
                                        push(sum);
                                        break;
                             case '*' : b = pop();
                                        c = pop();
                                        sum = c*b;                                  
                                        push(sum);
                                        break;
                             case '/' : b = pop();
                                        c = pop();
                                        sum = c/b;                                  
                                        push(sum);
                                        break;
                }
            } 
    }
            printf("Output :%d\n",s->next->value);  
            system("pause");        
}

