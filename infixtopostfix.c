#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push_char(char [], char);
char pop_char(char []);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);
void main()
{
	char infix_char[100], postfix_char[100];
	printf("\nEnter any infix expression: ");
	gets(infix);
	strcpy(postfix,"");
	InfixtoPostfix(infix, postfix);
	printf("\nThe corresponding postfix expression is: ");
	puts(postfix);
}

void InfixtoPostfix(char source[], char target[])
{
	int i=0, j=0;
	char temp;
	strcpy(target, "");
	while(source[i]!='\0')
	{
	if(source[i]=='(')
	{
		push(stack, source[i]);
		i++;
	}
	else if(source[i] == ')')
	{
	while((top!=-1)&&(stack[top]!='('))
	{
		target[j] = pop(stack);
		j++;
	}
	if(top==-1)
		printf("\nIncorrect exp");
	temp = pop(stack);
	i++;
	}
	else if(isdigit(source[i])||isalpha(source[i]))
	{
		target[j] = source[i];
		j++,i++;
	}
	else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
	{
	while((top!=-1) && (stack[top]!= '(') && (getPriority(stack[top]) > getPriority(source[i])))
	{
		target[j] = pop(stack);
		j++;
	}
	push(stack, source[i]);
	i++;
	}
	else
		printf("\nIncorrect element in exp");
	}
	while((top!=-1) && (stack[top]!='('))
  	{
  target[j] = pop(stack);
  j++;
  }
  target[j]='\0';
  }
  int getPriority(char op)
  {
  if(op=='/'||op == '*'||op=='%')
   return 1;
   else if(op=='+'||op=='-')
   return 0;
}

void push(char stack[], char val)
   {
   if(top==MAX-1)
   printf("\nStack Overflow");
   else
   {
   		top++;
   		stack[top] = val;
   }
   }
char pop(char stack[])
   {
   char val=' ';
   if(top==-1)
   		printf("\nStack Underflow");
	else
	{
		val = stack[top];
   		top--;
   	}
   return val;
}
