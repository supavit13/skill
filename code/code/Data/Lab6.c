#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *left,*right;
};
int function_menu()
{
    int n;
    printf("=======Menu=======\n");
    printf("1)Insert\n");
    printf("2)Delete\n");
    printf("3)Print Inorder Tree\n");
    printf("4)Exit\n");
    printf("Please Choose : ");
    scanf("%d",&n);
    return n;
    system("pause");
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
void printin(struct record *tree)
{
     if(tree == NULL)
     return;
     else
     { 
         printin(tree->left);
         printf("%d ",tree->value);
         printin(tree->right);
     }
}
struct record *find_min(struct record *tree)
{
       if(tree == NULL)
       return NULL;
       else if(tree->left == NULL)
       return tree;
       else
       return (find_min(tree->left));
} 
struct record *delete(struct record *tree,int m)  
{
       struct record *child,*tmp;
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
                   tmp = find_min(tree->right);
                   tree->value = tmp->value;
                   tree->right = delete(tree->right,tree->value);
               }
           else
           {
               tmp = tree;
               if(tree->left == NULL)
                   child = tree->right;
               if(tree->right == NULL)
                   child = tree->left;
               free(tmp);
               return child;
           }
       }
       return tree;
}
int main()
{
    struct record *tree = NULL;
    int x,n,m;
    while(1)
    {
            x = function_menu();
            switch(x)
            {
                     case 1:printf("Enter : ");
                            scanf("%d",&n);
                            tree = insert(tree,n);
                            break;         
                     case 2:printf("Input Number : ");
                            scanf("%d",&m);
                            tree = delete(tree,m);
                            break; 
                     case 3:printf("Data : ");
                            if(tree==NULL)
                            {
                                printf("No Data");
                            }
                            printin(tree);
                            printf("\n");
                            break;
                     case 4:exit(0); 
            }
    }        
}
