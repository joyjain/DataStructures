#include<stdio.h>
#define MAX 10
int queue[MAX],front=-1,rear=-1,i,op,val; 
void insert(int [],int);
void delete(int []);
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
				printf("Enter the number to be pushed on the queue: ");
				scanf("%d",&val);
				insert(queue,val);
				break;
			case 2:
				delete(queue);
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

void insert(int queue[],int val)
{
	if(front==0||rear==MAX-1)
		printf("Queue Overflow\n");
	if(front==-1&&rear==-1)
		front = rear = 0;
	else if(front!=0&&rear==MAX-1)
		rear = 0;
	else
	{
		rear++;
		queue[rear] = val;
	}
}

void delete(int queue[])
{
	if(front==-1&&rear==-1)
		printf("Queue Underflow\n");
	if(front==rear)
		front = rear = -1;
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
	}
}

void display(int queue[])
{
int i;
printf("\n");
if(front==-1&&rear==-1)
	printf ("Queue is empty\n");
else
{
	if(front<rear)
	{
		for(i=front;i<=rear;i++)
			printf("\t%d", queue[i]);
	}
	else
	{
		for(i=front;i<MAX;i++)
			printf("\t%d", queue[i]);
		for(i=0;i<=rear;i++)
			printf("\t%d",queue[i]);
	}
}
}
