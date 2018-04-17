#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *left,*right;
};
int menu()
{
    int x;
    printf("=======Menu=======\n");
    printf("1)Insert\n");
    printf("2)Delete\n");
    printf("3)Print min and max\n");
    printf("4)Find\n");
    printf("5)Print Leaf Node\n");
    printf("6)Print Preorder Tree\n");
    printf("7)Print Inorder Tree\n");
    printf("8)Print Postorder Tree\n");
    printf("9)Print non leave node\n"); 
    printf("10)Exit\n");
    printf("Please Choose : ");
    scanf("%d",&x);
    return x;
    
}
struct record *insert(struct record *tree,int n)
{
    if(tree == NULL)
    {
            tree = (struct record *)malloc(sizeof(struct record));
            tree->value = n;
            tree->left = tree->right = NULL;        
    }          
    else if(n < tree->value)
         tree->left = insert(tree->left,n);
    else if(n > tree->value)
         tree->right = insert(tree->right,n);
    return tree;
}
struct record *min(struct record *tree)
{
       if(tree==NULL)
       return NULL;
       else  if(tree->left == NULL)
       return tree;
       else
       return (min(tree->left));
}
struct record *delete(struct record *tree,int m)  
{
       struct record *c,*tmp;
       if(tree==NULL)
          printf("Can't Delete! No Data\n");
       else
       {
           if(m < tree->value)
              tree->left = delete(tree->left,m);
           else 
               if(m > tree->value)
                   tree->right = delete(tree->right,m);
           else 
               if(tree->left && tree->right)
               {
                   tmp = min(tree->right);
                   tree->value = tmp->value;
                   tree->right = delete(tree->right,tree->value);
               }
           else
           {
               tmp = tree;
               if(tree->left == NULL)
                   c = tree->right;
               if(tree->right == NULL)
                   c = tree->left;
               free(tmp);
               return c;
           }
       }
       return tree;
}
void pre(struct record *tree)
{
     if(tree == NULL)
     return;
     else
     {
         printf("%d ",tree->value);
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
         printf("%d ",tree->value);
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
         printf("%d ",tree->value);
     }
}
int fmin(struct record *tree)
{
       if(tree==NULL)
       return 0;
       else if(tree->left == NULL)
       return tree->value;
       else
       return (fmin(tree->left));
}
int fmax(struct record *tree)
{
       if(tree==NULL)
       return 0;
       else if(tree->right == NULL)
       return tree->value;
       else
       return (fmax(tree->right));
}
void lnode(struct record *tree)
{
     if(tree->left == NULL && tree->right == NULL)
     { 
          printf("%d ",tree->value);
     }
     else 
     {
          if(tree->left != NULL)
          lnode(tree->left);
          if(tree->right != NULL)
          lnode(tree->right);
     }
}
void find(struct record *tree,int m)
{
     if(tree != NULL)
     {
             if(tree->value == m)
             printf("Yes");
             else if(tree->value < m)
             find(tree->right,m);
             else
             find(tree->left,m);
     }
     else
     printf("No");
}  
void printnl(struct record *tree)
{
     if(tree == NULL)
         return;
     else
     {
         if(tree->right != NULL || tree->left != NULL)
             printf("%d  ",tree->value);
         printnl(tree->left);
         printnl(tree->right);
     }
     return;
}
  
int main()
{
    struct record *tree = NULL;
    int n,m,o;
    while(1)
    {    
            switch(menu())
            {
                     case 1:printf("Enter : ");
                            scanf("%d",&n);
                            tree = insert(tree,n);
                            break; 
                     case 2:printf("Input Number : ");
                            scanf("%d",&o);
                            tree = delete(tree,o);
                            break; 
                     case 3:printf("Min = %d\nMax = %d",fmin(tree),fmax(tree));
                            printf("\n");
                            break;
                     case 4:printf("Input number : ");
                            scanf("%d",&m);
                            find(tree,m);
                            printf("\n");
                            break;
                     case 5:printf("Leaf Node is : ");
                            lnode(tree);
                            printf("\n");
                            break;
                     case 6:printf("Data : ");
                            if(tree==NULL)
                            {
                                printf("No Data");
                            }
                            pre(tree);
                            printf("\n");
                            break;
                     case 7:printf("Data : ");
                            if(tree==NULL)
                            {
                                printf("No Data");
                            }
                            in(tree);
                            printf("\n");
                            break;
                     case 8:printf("Data : ");
                            if(tree==NULL)
                            {
                                printf("No Data");
                            }
                            post(tree);
                            printf("\n");
                            break;
                     case 9:printf("Non Leaf Node is : ");
                            printnl(tree);
                            printf("\n");
                            break;
                     case 10:exit(0);               
            }
    }  
    system("pause");          
}
