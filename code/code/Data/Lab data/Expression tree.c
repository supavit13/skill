#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record
{
    char data;
    int v;
    struct record *left,*right;
};
struct s
{
    struct record *data;
    struct s *next;
}*ss = NULL; 
struct record * insert(struct record *head,char data,int v)
{
    struct record *tmp,*p;
    if(head == NULL)
    {
        tmp = malloc(sizeof(struct record));
        tmp->data = data;
        tmp->v = v;
        tmp->right = NULL;
        tmp->left = NULL;
        head = tmp;
    }
    return head;
}
struct s *push(struct s *head,struct record *t)
{
    struct s *tmp;
    tmp = malloc(sizeof(struct s));
    tmp->data = t;
    tmp->next = NULL;
    if(head == NULL)
        head = tmp;
    else
        tmp->next = head;
    return tmp;
}
struct s *pop(struct s *head)
{
    struct s *p = head;
    if(head != NULL)
    {
        head = head->next;
        free(p);
    }
    return head;
}
struct s * chk(struct s *head,struct record *data)
{
    struct s *p;
    if(head!=NULL)
    {
        if(data->v == -1)
        {
            while(head->data->v!=0)
            {
                ss = push(ss,head->data);
                head = pop(head);
            }
            head = pop(head);
            return head;
        }
        else if(data->v==0)
            return push(head,data);
        else if(head->data->v<data->v)
            return push(head,data);
        else
        {
            ss = push(ss,head->data);
            head = pop(head);
            return chk(head,data);
        }
    }
    else
        return push(head,data);
}
struct s* chk1(struct record *d,struct s *tree)
{
    struct record *tmp1,*tmp2;
    if(d->data>='0'&&d->data<='9')
    {
        tree = push(tree,d);
    }
    else
    {
        tmp2 = tree->data;
        tree = pop(tree);
        tmp1 = tree->data;
        tree = pop(tree);
        d->left = tmp1;
        d->right = tmp2;
        tree = push(tree,d);
    }
    return tree;
}
struct s * ansIn(struct s *head,struct s *tree)
{
    if(head->next)
    {
        tree = ansIn(head->next,tree);
    }
    tree = chk1(head->data,tree);
    return tree;
} 
void pre(struct record *tree)
{
     if(tree == NULL)
     return;
     else
     {
         printf("%c",tree->data);
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
         printf("%c",tree->data);
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
         printf("%c",tree->data);
     }
}
int main()
{
    struct s *stack = NULL,*tree = NULL;
    char num[1000],c;
    int i=0;
    printf("Input : ");
    gets(num);
    while(i<strlen(num))
    {
        c = num[i];
        switch(c)
        {
            case '+':
                stack = chk(stack,insert(NULL,c,1));
                break;
            case '-':
                stack = chk(stack,insert(NULL,c,1));
                break;
            case '*':
                stack = chk(stack,insert(NULL,c,2));
                break;
            case '/':
                stack = chk(stack,insert(NULL,c,2));
                break;
            case '%':
                stack = chk(stack,insert(NULL,c,2));
                break;
            case ')':
                stack = chk(stack,insert(NULL,c,-1));
                break;
            case '(':
                stack = chk(stack,insert(NULL,c,0));
                break;
            default :ss = push(ss,insert(NULL,c,c-48));
        }
        i++;
    }
    while(stack)
    {
        if(stack->data->v!=0)
            ss = push(ss,stack->data);
        stack = stack->next;
    }
      tree = ansIn(ss,tree);                                       
      printf("Postfix: ");
      post(tree->data); 
      printf("\n\n");
      printf("Print Preorder : ");
      pre(tree->data);
      printf("\n");
      printf("Print Inorder : ");
      in(tree->data);
      printf("\n");
      printf("Print Postorder : ");
      post(tree->data);
      printf("\n");  
      system("pause"); 
}   
