#include<stdio.h>
#include<stdlib.h>
struct rec
{
	int value;
	struct rec *next;
};

struct rec *Insert(struct rec *head,int data)
{
	struct rec *tmp,*node = NULL;
	tmp = (struct rec *)malloc(sizeof(struct rec));
	tmp->value = data;
	if(head == NULL)//insert first data
	{
		head = tmp;
		tmp->next = NULL;		
	}
	else
	{
		if(data < head->value)//insert front & have new head
		{
			tmp->next = head;
			head = tmp;
		}
		else
		{
			node = head;
			while(node->next != NULL)//insert between own data
			{
				if(node->next->value > data )
				{
					tmp->next = node->next;
					node->next = tmp;
					break;
				}
				node = node->next;//check
			}
			if(node->next == NULL)//insert back
			{
				node->next = tmp;
				tmp->next = NULL;
			}
		}
	}
	return head;
}

struct rec *Delete(struct rec *head,int data)
{
	struct rec *node = NULL,*tmp = NULL;
	if(head != NULL)
	{
		if(head->value == data)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
		else
		{
			tmp = head;
			node = head->next;
			while(node != NULL)
			{
				if(node->value == data)
				{
					tmp->next = node->next;
					free(node);
					break;
				}
				node = node->next;
				tmp = tmp->next;
			}
		
			if(node == NULL)
			{
				printf("Not Found %d in List",data);
			}
		}
	}
	else
	{
		printf("List is Empty!!!\n");
	}
	return head;
}

void PrintNormal(struct rec *head)
{
	if(head == NULL)//No data in List
	{
		printf("No Data!!\n");
	}
	else 
	{
		printf("Data is : ");
		while(head != NULL)
		{
			printf("%d ",head->value);
			head = head->next;
		}
		printf("\n");
	}
}

int menu()
{
	int x;
	printf("=====MENU====\n");
	printf("1) Insert\n");
	printf("2) Delete\n");
	printf("3) Print\n");
	printf("4) Exit\n");
	printf("Please Choose > ");
	scanf("%d",&x);
	return x;
}

int main()
{
	struct rec *head=NULL;
	int x,data;
	while(1)
	{
		x = menu();
		switch(x)
		{
		  case 1 : printf("Input Data to Insert : ");
				   scanf("%d",&data);
				   head = Insert(head,data);
			       printf("\n");
			       break;
		  case 2 : printf("Input Data to Delete : ");
			       scanf("%d",&data);
				   head = Delete(head,data);
			       printf("\n");
				   break;
		  case 3 : PrintNormal(head);
				   printf("\n");
				   break;
		  case 4 : exit(1);
			       break;
		}
	}
}
