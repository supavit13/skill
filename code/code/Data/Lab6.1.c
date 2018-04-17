#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record
{
    char a[1];
    struct record *next; 
    struct record *prev;
    struct record *left; 
    struct record *right;  
};
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
    }
}
void postfix(struct record *tree)
{
     if(tree!=NULL)
     { 
         postfix(tree->left);
         postfix(tree->right);
         printf("%c",tree->a[0]);   
     }
}      
void pre(struct record *tree)
{
     if(tree == NULL)
     return;
     else
     {  
         printf("%c",tree->a[0]);
         pre(tree->left);
         pre(tree->right);
     }
}
void in(struct record *tree)
{
     if(tree == NULL)
     return;
     else
     { 
         in(tree->left);
         printf("%c",tree->a[0]);
         in(tree->right);
     }
}
void post(struct record *tree)
{
     if(tree == NULL)
     return;
     else
     { 
         post(tree->left);
         post(tree->right);
         printf("%c",tree->a[0]);   
     }
}
int main()
{ 
    char s[20];
    int n,i,m=0;
    struct record *tree,*p=NULL,*t=NULL,*node,*tmp,*tmp1;
    printf("Input: ");
    gets(s);
    n = strlen(s);
    for(i=0;i<n;i++)
    {
      if(p == NULL)
      {
          node = malloc(sizeof(struct record));
          p = t =node;
          node->next = node->prev = NULL;
          node->a[0]=s[i];
          node->left = node->right = NULL;
      }
      else
      {
          node = malloc(sizeof(struct record));
          t->next = node;
          node->next = NULL;
          node->prev = t;
          t = node;
          node->a[0] = s[i];
          node->left = node->right = NULL;                                     
      }             
    }
    for(tmp=t;tmp!=NULL;tmp=tmp->prev)
    {
         if(tmp->a[0] == '+' || tmp->a[0] == '-' || tmp->a[0] == '*' || tmp->a[0] == '/' || tmp->prev == NULL)
         {
            if(m<=map(tmp->a[0]))
            {
                m = map(tmp->a[0]);                      
            }
            if(m>map(tmp->a[0]) || tmp->prev == NULL)
            {
               for(tmp1=tmp->next;tmp1!=NULL;tmp1=tmp1->next)
               {
                     if(tmp1->a[0] == '+' || tmp1->a[0] == '-' || tmp1->a[0] == '*' || tmp1->a[0] == '/')
                     {
                          tmp1->left = tmp1->prev; 
                          tmp1->right = tmp1->next; 
                          tmp1->next = tmp1->next->next;
                          tmp1->prev = tmp1->prev->prev; 
                          if(tmp1->prev!=NULL)
                          {
                               tmp1->prev->next = tmp1;
                          }
                          if(tmp1->next!=NULL)
                          { 
                               tmp1->next->prev = tmp1;
                          }
                          tree = tmp1;      
                          m = map(tmp1->a[0]);                                                                                                                                                                                                                                        
                     }
               }   
            }       
         }                                                      
    }                                          
      printf("Postfix: ");
      postfix(tree); 
      printf("\n\n");
      printf("Print Preorder : ");
      pre(tree);
      printf("\n");
      printf("Print Inorder : ");
      in(tree);
      printf("\n");
      printf("Print Postorder : ");
      post(tree);
      printf("\n");  
      system("pause"); 
}   
