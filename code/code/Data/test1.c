#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *next;
};
struct record *s;
struct record *createstack(void)
{
      struct record *s;
      s = (struct record *)malloc(sizeof(struct record));
      s->next = NULL;
      return s;
}
void push(int b)
{     struct record *tmpcell;
      tmpcell = (struct record *)malloc(sizeof(struct record));
      tmpcell->value = b;
      tmpcell->next = s->next;
      s->next = tmpcell;
}
int pop(void)
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
    s = createstack();
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
