#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;

node *start=NULL;

void insert_beg();
void insert_end();
void insert_node();
void delete_beg();
void delete_end();
void delete_node();
void display();
void main()
{
	int num,op;
	node *new_node,*ptr;
	printf("Enter the data, \"0\" to abort.\n");
	scanf("%d",&num);
	while(num!=0) {
		new_node = malloc(sizeof(struct node));
		new_node->data = num;
		if(start==NULL)
		{
			new_node->next = NULL;
			new_node->prev = NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr->next!=NULL)
				ptr = ptr->next;
			ptr->next = new_node;
			new_node->next = NULL;
			new_node->prev = ptr;
		}
		printf("Enter the data: ");
		scanf("%d",&num);
	}
	while(1) {
	printf("Enter the operation to perform: ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			insert_beg();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
	}
}
}

void insert_beg()
{
	node *new_node;
	int num;
	printf("Enter the data: ");
	scanf("%d",&num);
	new_node = malloc(sizeof(node));
	new_node->data = num;
	start->prev = new_node;
	new_node->next = start;
	new_node->prev = NULL;
	start = new_node;
}

void insert_end()
{
	node *new_node,*ptr;
	int num;
	printf("Enter the data: ");
	scanf("%d",&num);
	new_node = malloc(sizeof(node));
	new_node->data = num;
	ptr = start;
	while(ptr->next!=NULL)
		ptr = ptr->next;
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = NULL;
}

void display()
{
	node *traverse;
	traverse = start;
	printf("\nYour Doubly Linked List is: ");
	while(traverse!=NULL) {
		printf("%d ",traverse->data);
		traverse = traverse->next;
	}
	printf("\n");
}
