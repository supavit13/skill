#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value;
       struct record *left,*right;
};

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

void find(struct record *tree,int m)
{
     if(tree != NULL)
     {
             if(tree->value == m)
             	printf("Yes");
             else if(tree->value < m)
             {
             	find(tree->right,m);
			 }
             else
             {
             	find(tree->left,m);
			 }
     }
     else
     printf("No");
} 
   
int main()
{
    struct record *tree = NULL;
    int x,n,m,i;
    for(i=0;i<=14;i++)
    {
		tree = insert(tree,i);
	}
	//printf("Min = %d\nMax = %d",find_min(tree),find_max(tree));
	printf("Input number : ");
    scanf("%d",&m);
    find(tree,m);              
    printf("\n");
              
}
