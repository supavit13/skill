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
    printf("2)Print Preorder Tree\n");
    printf("3)Print min and max\n");
    printf("4)Find\n");
    printf("5)Print Leaf Node\n");
    printf("6)Exit\n");
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
void printpre(struct record *tree)
{
     if(tree == NULL)
     return;
     else
     {
         printf("%d ",tree->value);
         printpre(tree->left);
         printpre(tree->right);
     }
}
int find_min(struct record *tree)
{
       if(tree->left == NULL)
       return tree->value;
       else
       return (find_min(tree->left));
}
int find_max(struct record *tree)
{
       if(tree->right == NULL)
       return tree->value;
       else
       return (find_max(tree->right));
}
void printleaf_node(struct record *tree)
{
     if(tree->left == NULL && tree->right == NULL)
     { 
      printf("%d ",tree->value);
     }
     else 
     {
          if(tree->left != NULL)
          printleaf_node(tree->left);
          if(tree->right != NULL)
          printleaf_node(tree->right);
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
                     case 2:printf("Data : ");
                            printpre(tree);
                            printf("\n");
                            break;
                     case 3:printf("Min = %d\nMax = %d",find_min(tree),find_max(tree));
                            printf("\n");
                            break;
                     case 4:printf("Input number : ");
                            scanf("%d",&m);
                            find(tree,m);
                            printf("\n");
                            break;
                     case 5:printf("Leaf Node is : ");
                            printleaf_node(tree);
                            printf("\n");
                            break;
                     case 6:exit(0);
                     
            }
    }
              
}
