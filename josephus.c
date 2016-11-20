#include<stdio.h>
#include<malloc.h>
struct node
{
	int number;
	struct node *next;
};
void main()
{
	int i,n,k;
	struct node *new_node,*start,*ptr,*preptr;
	printf("Enter the number of persons: ");
	scanf("%d",&n);
	do {
		printf("Enter the frequency of elimination(Every kth person who will be eliminated): ");
		scanf("%d",&k);
	}while(k<2);
	start = (struct node*)malloc(sizeof(struct node));
	start->number = 1;
	start->next = start;
	ptr = start;
	for(i=2;i<=n;i++)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->number = i;
		ptr = start;
		while(ptr->next!=start)
			ptr = ptr->next;
		ptr->next = new_node;
		new_node->next = start;
	}
	ptr = start;
	while(preptr!=ptr)
	{
		for(i=1;i<k;i++)
		{
			preptr = ptr;
			ptr = ptr->next;
		}
	preptr->next = ptr->next;
	ptr = ptr->next;
	}
	printf("The survivor is person in position %d",ptr->number);
}
