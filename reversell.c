#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;	
}*start = NULL;
int main(struct node *start)
{
	struct node *new_node,*temp;
	int num,prin;
	printf("Enter the data, 0 to abort: ");
	fflush(stdin);
	scanf("%d,&num");
	while(num!=0)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
	if(start==NULL)
	{
		new_node->next = NULL;
		start = new_node;
	}
	else
	{
		temp = start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = new_node;
		new_node->next = NULL;
	}
	printf("Enter the data: ");
	scanf("%d",&num);
	}
	printf("If you wish to print the entered data, enter 1");
	scanf("%d",&prin);
	if(prin==0)
		print();
}
void print()
{
	struct node *temp;
	temp = start;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
}
