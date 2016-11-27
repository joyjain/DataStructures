#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node *next;
}node;

node *start = NULL;
void create_ll();
void display();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
void main()
{
	int operation;
	while(1) {
	printf("Enter the operation to perform:\n");
	printf("\"1\" for creation.\n\"2\" for insertion at the beginning.\n\"3\" for insertion at the end.\n\"4\" for deletion at the beginning.\n\"5\" for deletion at the end.\n\"6\" to display\n\"7\" to exit.\nOperation: ");
	scanf("%d",&operation);
	switch(operation)
	{
		case 1:
			create_ll();
			break;
		case 2:
			insert_beg();
			break;
		case 3:
			insert_end();
			break;
		case 4:
			delete_beg();
			break;
		case 5:
			delete_end();
			break;
		case 6:
			display();
			break;
		case 7:
			exit(0);
			break;
	}
}
}
void create_ll()
{
	node *new_node,*ptr;
	int num;
	printf("Enter the data, \"0\" to abort. :");
	scanf("%d",&num);
	while(num!=0)
	{
		new_node = malloc(sizeof(node));
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
				ptr = ptr->next;
			ptr->next = new_node;
			new_node->next = start;
		}
		printf("Enter the data: ");
		scanf("%d",&num);
	}
	}

void display()
{
		node *new_node;
		new_node = start;
		printf("\nThe circular linked is: ");
		while(new_node->next!=start)
		{
			printf("%d ",new_node->data);
			new_node = new_node->next;
		}
		printf("%d",new_node->data);
		printf("\n\n");
}

void insert_beg()
{
	node *new_node,*ptr;
	int num;
	printf("Enter the data:\n");
	scanf("%d",&num);
	new_node = malloc(sizeof(node));
	new_node->data = num;
	ptr = start;
	while(ptr->next!=start)
		ptr = ptr->next;
	ptr->next = new_node;
	new_node->next = start;
	start = new_node;
}

void insert_end()
{
	node *new_node,*ptr;
	int num;
	printf("Enter the data:\n");
	scanf("%d",&num);
	new_node = malloc(sizeof(node));
	new_node->data = num;
	ptr = start;
	while(ptr->next!=start)
		ptr = ptr->next;
	ptr->next = new_node;
	new_node->next = start;
}

void delete_beg()
{
	node *ptr;
	ptr = start;
	while(ptr->next!=start)
		ptr = ptr->next;
	ptr->next = start->next;
	free(start);
	start = ptr->next;
}

void delete_end()
{
	node *ptr,*preptr;
	ptr = start;
	preptr = ptr;
		while(ptr->next!=start)
		{
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = ptr->next;
	free(ptr);
}
