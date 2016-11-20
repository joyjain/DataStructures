#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	int priority;
	struct node *next;	
};
struct node *start=NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);
void main()
{
	int option;
	printf("\"1\" To insert\n\"2\" To delete\n\"3\" To display your queue\n\"4\" To exit");
	do
	{
		printf("\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			start = insert(start);
			break;
		case 2:
			start = delete(start);
			break;
		case 3:
			display(start);
			break;
		case 4:
				break;
		default:
			printf("Option doesn\'t exist try again");
		}
	}while(option!=4);
}

struct node *insert(struct node *start)
{
	int val, pri;
	struct node *ptr,*p;
	ptr = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value: ");
	scanf("%d",&val);
	printf("Enter its priority: ");
	scanf("%d",&pri);
	ptr->data = val;
	ptr->priority = pri;
	if(start==NULL||pri<(start->priority))
	{
		ptr->next = start;
		start = ptr;
	}
	else
	{
		p = start;
		while(p->next!=NULL&&p->next->priority<=pri)
			p = p->next;
		ptr->next = p->next;
		p->next = ptr;
	}
	return start;
}

struct node *delete(struct node *start)
{
	struct node *ptr;
	if(start==NULL)
		printf("\nQueue Underflow");
	else
	{
		ptr = start;
		start = start->next;
		free(ptr);
	}
	return start;
}

void display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	if(start==NULL)
		printf("\nQueue Is Empty");
	else
	{
		printf("\nPriority Queue Is: ");
		while(ptr!=NULL)
		{
			printf("%d and priority=%d ",ptr->data,ptr->priority);
			ptr = ptr->next;
		}
	}
}
