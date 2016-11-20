#include<stdio.h>
int stack[100], top=-1, i, val, n, op;
void push(int stack[],int val);
void pop(int stack[]);
void display(int stack[]);
void main()
{
	printf("Enter the size of your stack: ");
	scanf("%d",&n);
	printf("\"1\" To push\n\"2\" To pop\n\"3\" To display your stack\n\"4\" To exit");
	do
	{
		printf("\nEnter the operation: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the number to be pushed on stack: ");
				scanf("%d",&val);
				push(stack,val);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				display(stack);
				break;
			case 4:
				break;
			default:
				printf("Option doesn\'t exist try again");
		}
	}while(op!=4);
}
void push(int stack[],int val)
{
	if(top==n-1)
		printf("Stack overflow\n");
	else
	{
		top++;
		stack[top] = val;
	}
}

void pop(int stack[])
{
	if(top==-1)
		printf("Stack underflow\n");
	else
		stack[top--];
}

void display(int stack[])
{
	if(top==-1)
		printf("Stack is empty\n");
	else
	{
		printf("Stack entered is:\n");
		for(i=top;i>=0;i--)
		printf("%d\n",stack[i]);
	}
}
