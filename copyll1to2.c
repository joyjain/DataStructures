#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node1
{
	int data1;
	struct node *next;	
};
struct node2
{
	int data2;
	struct node *next;	
};
struct node1 *start1 = NULL;
struct node2 *start2 = NULL;
int main(void)
{
	struct node1 *new_node1,*ptr1;
	struct node2 *new_node2,*ptr2;
	int num;
	printf("Enter the data, \"0\" to abort. :");
	scanf("%d",&num);
	while(num!=0)
	{
		new_node1 = (struct node1*)malloc(sizeof(struct node1));
		new_node1->data1 = num;
		if(start1==NULL)
		{
			new_node1->next = new_node1;
			start1 = new_node1;
		}
		else
		{
			ptr1 = start1;
			while(ptr1->next != NULL)
				ptr1 = ptr1->next;
			ptr1->next = new_node1;
			new_node1->next = NULL;
		}
		printf("Enter the data: ");
		scanf("%d",&num);
		fflush(stdin);
	}
		while(start1!=NULL)
	{
    struct node2 *ptr2 = (struct node2*)malloc(sizeof(struct node2));
    new_node2->data2 = new_node1->data1;
    if(start2==NULL)
    {
        new_node2->next = new_node2;
        start2 = new_node2;
    }
    else
    {
        ptr2 = start2;
        while(ptr2->next!=NULL)
        	ptr2 = ptr2->next;
		}
    }
    start1=start1->next;
}
