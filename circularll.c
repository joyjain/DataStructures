#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node*);
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
int main(void)
{
	int operation;
	do
	{
	printf("Enter the operation to perform:\n");
	printf("\"1\" for creation.\n\"2\" for insertion at the beginning.\n\"3\" for insertion at the end.\n\"4\" for deletion at the beginning.\n\"5\" for deletion at the end.\nOperation: ");
	scanf("%d",&operation);
	switch(operation)
	{
		case 1:
			start = create_ll(start);
			goto display;
		case 2:
			start = insert_beg(start);
			goto display;
		case 3:
			start = insert_end(start);
			goto display;
		case 4:
			start = delete_beg(start);
			goto display;
		case 5:
			start = delete_end(start);
			goto display;
		display:
			start = display(start);
			break;
	}
	}while(operation<1||operation>5);
}
struct node *create_ll(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("Enter the data, \"0\" to abort. :");
	scanf("%d",&num);
	while(num!=0)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if(start==NULL)
		{
			new_node->next = new_node;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr->next!=start)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;
		}
		printf("Enter the data: ");
		scanf("%d",&num);
	}
		return start;
	}
	
struct node *display(struct node *start)
{
		struct node *new_node;
		new_node=start;
		printf("The circular linked is: ");
		while(new_node->next!=start)
		{
			printf("%d->",new_node->data);
			new_node=new_node->next;
		}
}
	
struct node *insert_beg(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("Enter the data:\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("Enter the data:\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=ptr;
	while(preptr->next!=start)
	{
		ptr=ptr->next;
		preptr=ptr;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
