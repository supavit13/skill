#include<stdio.h>
struct rec
{
       char value;
       struct rec *next,*prev;
}*tail;
struct rec *insert(struct rec *head,char data)
{ 
       struct rec *node;
       
       if(head==NULL)
       { 
          head = (struct rec*)malloc(sizeof(struct rec));
          head->value = data;
          head->next = NULL;
          head->prev = NULL;
          tail=head;
       }
       else
       { 
          node = (struct rec*)malloc(sizeof(struct rec));       
          node->value = data;
          tail->next = node;
          node->prev = tail;
          node->next = NULL;
          tail = node;
       }  
   return head;  
}
struct rec *encoding(struct rec *head)
{      
       if(head==NULL || head->next==NULL)
          return head; 
       struct rec *tmp=head; 
       head = head->next; 
       while(tmp != NULL)
       {  
          if(tmp->next==NULL)
             break;   
          tmp->next->prev = tmp->prev;
          if(tmp->prev != NULL)
             tmp->prev->next = tmp->next;    
          tmp->prev = tmp->next;
          tmp->next = tmp->next->next;
          tmp->prev->next = tmp;
          if(tmp->next != NULL)
            tmp->next->prev = tmp;
          tmp = tmp->next;
       }
       return head;
}

print(struct rec*head)
{   
    while(head)
    {  printf("%c",head->value);
       head = head->next;
    } 
}

savefile(struct rec *head,FILE *outfile)
{
    while(head)
    {  putc(head->value,outfile);  
       head = head->next;
    }
}

int main()
{
    struct rec *head=NULL;
    char string[30];
    int i;
    FILE *outfile;
    outfile = fopen("loveletter.dat","w");
    printf("Write a letter : ");
    gets(string);
    for(i=0;i<strlen(string);i++)
       head = insert(head,string[i]);
    printf("Encoding : ");
    head = encoding(head);
    print(head);
    savefile(head,outfile);  
    fclose(outfile);              
    getch();
}
