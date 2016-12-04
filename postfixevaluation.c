#include<stdio.h>
#define MAX 100
float stack[MAX];
int top=-1;
float push(float [], float);
float pop(float []);
float evaluatePostfixExp(char []);
void main()
{
	float val;
	char exp[100];
	printf("\nEnter any postfix expression: ");
	gets(exp);
	val = evaluatePostfixExp(exp);
	printf("\nValue of the postfix expression = %.2f", val);
}

float evaluatePostfixExp(char exp[])
{
	int i=0;
	float op1, op2, value;
	while(exp[i]!='\0')
	{
	if(isdigit(exp[i]))
		push(stack, (float)(exp[i]-'0'));
   	else
   	{
   		op2 = pop(stack);
   		op1 = pop(stack);
   		switch(exp[i])
   		{
   		case '+':
   			value = op1+op2;
   			break;
   		case '-':
   			value = op1-op2;
   			break;
   		case '/':
   			value = op1/op2;
			break;
   		case '*':
   			value = op1*op2;
   			break;
   		case '%':
   			value = (int)op1%(int)op2;
   			break;
   		}
   push(stack, value);
   }
   i++;
   }
   return(pop(stack));
}

float push(float stack[], float val)
{
   if(top==MAX-1)
   		printf("\nStack Overflow");
   else
   {
   top++;
   stack[top] = val;
   }
}

float pop(float stack[])
{
   float val=-1;
   if(top==-1)
		printf("\nStack Underflow");
   else
   {
   		val = stack[top];
   		top--;
   }
   return val;
}
