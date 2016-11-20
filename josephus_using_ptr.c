#include<stdio.h>
#include<malloc.h>
struct node
{
	int number;
	struct node *next;
}*start=NULL;
void main()
{
	struct node *new_node,*ptr;
	int n,k,i;
	printf("Enter the number of persons: ");
	scanf("%d",&n);
	do {
		printf("Enter the frequency of elimination(Every kth person who will be eliminated): ");
		scanf("%d",&k);
	}while(k<2);
	start = (struct node *)malloc(sizeof(struct node));
	start->number = 1;
	start->next = start;
	for(i=2;i<=n;i++)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		ptr = start;
		while(ptr->next!=start)
			ptr = ptr->next;
		ptr->next = new_node;
		new_node->number = i;
		new_node->next = start;
	}
	ptr = start;
	while(ptr->next!=ptr)
	{
		for(i=1;i<k-1;i++)
			ptr = ptr->next;
		ptr = ptr->next = ptr->next->next;
	}
	printf("The survivor is person in position %d",ptr->number);
}
