#include<stdio.h>
#include<process.h>
#define MAX 20
int deque[MAX],left=-1,right=-1;
void input_deque();
void output_deque();
void insert_right();
void insert_left();
void delete_right();
void delete_left();
void display();
void main()
{
	int option;
	printf("\"1\" For input restricted deque\n\"2\" For output restricted deque\nEnter your option: ");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			input_deque();
			break;
		case 2:
			output_deque();
			break;
	}
}

void input_deque()
{
	int option;
	printf("\n\"1\" To insert at right end\n\"2\" To delete from left end\n\"3\" To delete from right end\n\"4\" To display your input deque\n\"5\" To exit");
	do
	{
		printf("\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				insert_right();
				break;
			case 2:
				delete_left();
				break;
			case 3:
				delete_right();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Option doesn\'t exist try again");
		}
	}while(option!=5);
}

void output_deque()
{
	int option;
	printf("\n\"1\" To insert at right end\n\"2\" To insert at left end\n\"3\" To delete from left end\n\"4\" To display your output deque\n\"5\" To exit");
	do
	{
		printf("\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				insert_right();
				break;
			case 2:
				insert_left();
				break;
			case 3:
				delete_left();
				break;
			case 4:
				display();
				break;
		}
	}while(option!=5);
}

void insert_right()
{
	int num;
	printf("\nEnter the number to be pushed on queue: ");
	scanf("%d",&num);
	if((left==0&&right==MAX-1)||(left==right+1))
		printf("Deque Overflow\n");
	if(left==-1)
	{
		left = 0;
		right = 0;
	}
	else
	{
		if(right==MAX-1)
			right = 0;
		else
			right++;
	}
	deque[right] = num;
}

void insert_left()
{
	int num;
	printf("\nEnter the number to be pushed on queue: ");
	scanf("%d",&num);
	if((left==0&&right==MAX-1)||(left==right+1))
		printf("Deque Overflow\n");
	if(left==-1)
	{
		left = 0;
		right = 0;
	}
	else
	{
		if(left==MAX-1)
			left = 0;
		else
			left--;
	}
	deque[left] = num;
}

void delete_left()
{
	if(left==-1)
		printf("Deque Underflow\n");
	if(left==right)
	{
		left = -1;
		right = -1;
	}
	else
	{
		if(left==MAX-1)
			left = 0;
		else
			left++;
	}
}

void delete_right()
{
	if(left==-1)
		printf("Deque Underflow\n");
	if(left==right)
	{
		left = -1;
		right = -1;
	}
	else
	{
		if(right==0)
			right = MAX-1;
		else
			right--;
	}
}

void display()
{
	int front=left,rear=right;
	if(front==-1)
		printf("\nDeque Is Empty");
	printf("\nThe elements of the deque are : ");
 	if(front<=rear)
	{
		for(;front<=rear;front++)
			printf("%d ",deque[front]);
	}
	else
	{
		for(;front<=MAX-1;front++)
			printf("%d ",deque[front]);
		front = 0;
		for(;front<=rear;front++)
			printf("%d ",deque[front]);
 	}
 	printf("\n");
}
