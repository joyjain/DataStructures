#include<stdio.h>
#define MAX 100
int queue[MAX], front=-1, rear=-1, i, op, val;
void push(int [],int);
void pop(int []);
void display(int []);
void main()
{
	printf("\"1\" To push\n\"2\" To pop\n\"3\" To display your queue\n\"4\" To exit");
	do
	{
		printf("\nEnter the operation: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the number to be pushed on queue: ");
				scanf("%d",&val);
				push(queue,val);
				break;
			case 2:
				pop(queue);
				break;
			case 3:
				display(queue);
				break;
			case 4:
				break;
			default:
				printf("Option doesn\'t exist try again");
		}
	}while(op!=4);
}

void push(int queue[],int val)
{
	if(rear==MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front==-1)
			front=0;
		rear++;
		queue[rear] = val;
	}
}

void pop(int queue[])
{
	if(front==-1||front>rear)
		printf("Queue Underflow\n");
	else
	{
		front++;
		if(front>rear)
			front = rear = -1;
	} 
}

void display(int queue[])
{
	if(front==-1||front>rear)
		printf("Queue is empty\n");
	else
	{
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);
	}
}
