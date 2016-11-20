#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*start=NULL;
int cont;
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_node(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
void main()
{
	int num,op;
	struct node *new_node,*ptr;
	printf("Enter the data, \"0\" to abort.\n");
	scanf("%d",&num);
	while(num!=0)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
		if(start==NULL)
		{
			new_node->next = NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next = new_node;
			new_node->next = NULL;
			new_node->prev = ptr;
		}
			printf("Enter the data: ");
			scanf("%d",&num);
	}
	do
	{
	printf("Enter the operation to perform: ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			start=insert_beg(start);
			printf("\nEnter 1 to continue performing: ");
			scanf("%d",&cont);
			break;
		case 2:
			start=insert_end(start);
			printf("\nEnter 1 to continue performing: ");
			scanf("%d",&cont);
			break;
	}
	}while(cont==1);
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("Enter the data: ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	start->prev=new_node;
	new_node->next=start;
	new_node->prev=NULL;
	start = new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("Enter the data: ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
	return start;
}
