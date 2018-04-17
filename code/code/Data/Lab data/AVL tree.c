#include<stdio.h>
#include<stdlib.h>
struct record
{
       int value,height;
       struct record *left,*right;
};
int menu()
{
    int n;
    printf("=======Menu=======\n");
    printf("1)Insert\n");
    printf("2)Print Inorder Tree\n");
    printf("3)Exit\n");
    printf("Please Choose : ");
    scanf("%d",&n);
    return n;
}
int fheight(struct record *p)
{
    if(p == NULL)
     return -1;
    else
     return p->height;
}
int max(int L,int R)
{
    if(L>R)
     return L;
    else
     return R;
}
struct record *srleft(struct record *k2)
{
    struct record *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(fheight(k2->left),fheight(k2->right))+1;  //update k2->height
    k1->height = max(fheight(k1->left),k2->height)+1;  //update k1->height
    return k1;
}
struct record *srright(struct record *k2)
{
    struct record *k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(fheight(k2->left),fheight(k2->right))+1; //update k2->height
    k1->height = max(k2->height,fheight(k1->right))+1;  //update k1->height
    return k1;       
}
struct record *drleft(struct record *k3)
{
    k3->left = srright(k3->left);
    return srleft(k3);
}
struct record *drright(struct record *k3)
{
    k3->right = srleft(k3->right);
    return srright(k3);
}
struct record *insert(int n,struct record *T)
{
       if(T==NULL)
       {
            T = (struct record *)malloc(sizeof(struct record));
            T->value = n;
            T->left = T->right = NULL;
            T->height = 0;
       }
       else if(n < T->value)
       {
            T->left = insert(n,T->left);
            if(fheight(T->left)-fheight(T->right) == 2)
               if(n < T->left->value)
                  T = srleft(T);
               else
                  T = drleft(T);
       }
       else if(n > T->value)
       {
            T->right = insert(n,T->right);
            if(fheight(T->right)-fheight(T->right) == 2)
               if(n > T->right->value)
                  T = srright(T);
               else
                  T = drright(T);
       }
       T->height = max(fheight(T->left),fheight(T->right))+1;
       return T;
}
void printin(struct record *T)
{
     if(T == NULL)
       return;
     else
     { 
         printin(T->left);
         printf("%d ",T->value);
         printin(T->right);
     }
}
int main()
{
    struct record *T = NULL;
    int n;
    while(1)
    {
            switch(menu())
            {
                     case 1:printf("Enter : ");
                            scanf("%d",&n);
                            T = insert(n,T);
                            printf("\n");
                            break;          
                     case 2:printf("Data : ");
                            if(T==NULL)
                            {
                                printf("No Data");
                            }
                            printin(T);
                            printf("\n\n");
                            break;
                     case 3:exit(0); 
            }
    }  
       system("pause");       
}
