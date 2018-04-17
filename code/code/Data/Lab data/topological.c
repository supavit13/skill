#include<stdio.h>
#include<stdlib.h>
struct rec
{
    int value;
    struct rec*next;
};
struct rec*adj[8];
struct rec*insert(struct rec*head,int data)
{
    if(head==NULL)
    {
        head=(struct rec*)malloc(sizeof(struct rec));
        head->value=data;
        head->next=NULL;
    }
    else
    {
        if(data > head->value)
            head->next=insert(head->next,data);
        else
        {
            struct rec*node=(struct rec*)malloc(sizeof(struct rec));
            node->value=data;
            node->next=head;
            head=node;
        }
    }
    return head;
}

void print(struct rec*head)
{
        while(head)
        {
            printf("%d",head->value);
            if(head->next!=NULL)
                printf(",");
            head=head->next;
        }
}
int main()
{
    int x,data,i,j,a[8][8],b[8][8];
    struct rec*temp;
    while(1)
    {
        printf("    MENU    \n");
        printf("1.Insert\n");
        printf("2.Print\n");
        printf("3.Exit\n");
        printf("Please choose menu : ");
        scanf("%d",&x);
        switch(x)
        {
            case 1 : for(i=0;i<6;i++)
                         adj[i]=NULL;
                     for(i=0;i<6;i++)
                     {
                         printf("Insert # %d : ",i);
                         while(1)
                         {
                             scanf("%d",&data);
                             if(data==99)
                                 break;
                             else
                                 adj[i]=insert(adj[i],data);
                         }
                     }
                     for(i=0;i<6;i++)
                         for(j=0;j<6;j++)
                             a[i][j]=0;
                     for(i=0;i<6;i++)
                     {
                         temp=adj[i];
                         if(temp==NULL)
                         {
                             for(j=0;j<6;j++)
                             a[i][j]=0;
                         }
                         else
                         {
                             while(temp)
                             {
                                 for(j=0;j<6;j++)
                                 {
                                     if(temp->value==j)
                                         a[i][j]=1;
                                     else
                                         if(a[i][j]!=1)
                                             a[i][j]=0;
                                 }
                                 temp=temp->next;
                             }
                         }
                     }
                     for(i=0;i<6;i++)
                         for(j=0;j<6;j++)
                             b[i][j]=a[j][i];
                     for(i=0;i<6;i++)
                         adj[i]=NULL;
                     for(i=0;i<6;i++)
                     {
                         for(j=0;j<6;j++)
                         {
                             if(b[i][j]==1)
                                 adj[i]=insert(adj[i],j);
                         }
                     }
                     break;
            case 2 : for(i=0;i<6;i++)
                     {
                         printf("Set %d : ",i);
                         printf("{ ");
                         print(adj[i]);
                         printf(" }");
                         printf("\n");
                     }
                     break;
            case 3 : exit(0);
        }
    }system("pause");
}
