#pragma once

#include <stdio.h>
#include <ctype.h>
#include "custom_math.h"

#define MAX 100

char stack_char[MAX], infix_char[MAX], postfix_char[MAX], prefix_char[MAX], opnds[MAX][MAX], oprs[MAX];
float st[MAX];
int top = -1, topr=-1, topd=-1;

void push_char(char [], char);
char pop_char(char []);
void InfixtoPostfix_call();
void InfixtoPostfix(char [], char []);
int getPriority(char);

void InfixtoPrefix_call();
int pr(char);
char pop_in();
void push_in(char);

void PostfixtoPrefix_call();

void PrefixtoPostfix_call();
void pushd(char *);
char *popd();
void pushr(char);
char popr();
int empty(int);

void PostfixEvaluation_call();
void push_post(float [], float);
float pop_post(float []);
float evaluatePostfixExp(char []);

void InfixtoPostfix_call()
{
	printf("\n\t\t\t\t\t\t\t\t   Enter any infix expression: ");
	fflush(stdin);
	scanf("%[^\n]s", infix_char);
	fflush(stdin);
	strcpy(postfix_char, "");
	InfixtoPostfix(infix_char, postfix_char);
	printf("\n\t\t\t\t\t\t\t   The corresponding postfix expression is: ");
	printf("%s", postfix_char);
}

void InfixtoPrefix_call()
{
	int i=0, k=0;
	char ch, elem;
	printf("\n\t\t\t\t\t\t\t\t   Enter any infix expression: ");
	strcpy(infix_char, "");
	fflush(stdin);
	scanf("%[^\n]s", infix_char);
	fflush(stdin);
	push_in('#');
	strrev(infix_char);
	while((ch = infix_char[i++]) != '\0')
	{
			if( ch == ')') push_in(ch);
			else
					if(isalnum(ch)) prefix_char[k++]=ch;
					else
							if( ch == '(')
							{
									while(stack_char[top] != ')')
											prefix_char[k++] = pop_in();
									elem = pop_in(); /* Remove ) */
							}
							else
							{       /* Operator */
									while( pr(stack_char[top]) >= pr(ch) )
											prefix_char[k++] = pop_in();
									push_in(ch);
							}
	}
	while( stack_char[top] != '#')     /* Pop from stack till empty */
			prefix_char[k++] = pop_in();
	strrev(prefix_char);
	strrev(infix_char);
	printf("\n\t\t\t\t\t\t\t   The corresponding prefix expression is: ");
	printf("%s", prefix_char);
}

void PostfixtoPrefix_call()
{
	int i;
	printf("\n\t\t\t\t\t\t\t\t   Enter any postfix expression: ");
	strcpy(postfix_char, "");
	fflush(stdin);
	scanf("%[^\n]s", postfix_char);
	fflush(stdin);
	strrev(postfix_char);
	strcpy(prefix_char, "");
	strcpy(prefix_char, postfix_char);
	printf("\n\t\t\t\t\t\t\t   The corresponding prefix expression is: ");
	printf("%s",prefix_char);
}

void PrefixtoPostfix_call()
{
	char ch, str[MAX], operand1[MAX], operand2[MAX], opr[MAX];
	int i=0, k=0, operand_count=0;
	printf("\n\t\t\t\t\t\t\t\t   Enter any prefix expression: ");
	strcpy(prefix_char, "");
	fflush(stdin);
	scanf("%[^\n]s", prefix_char);
	fflush(stdin);
	while( (ch=prefix_char[i++]) != '\0')
	{
			if(isalnum(ch))
			{
					str[0] = ch;
					str[1]='\0';
					pushd(str);
					operand_count++;
					if(operand_count >= 2)
					{
							strcpy(operand2,popd());
							strcpy(operand1,popd());
							strcpy(str,operand1);
							strcat(str,operand2);
							ch = popr();
							opr[0] = ch;
							opr[1]='\0';
							strcat(str, opr);
							pushd(str);
							operand_count -= 1;
					}
			}
			else
			{
					pushr(ch);
					if(operand_count==1)
						operand_count = 0;  // operator followed by single operand
			}
	}

	if(!empty(topd))
	{
			strcpy(operand2,popd());
			strcpy(operand1,popd());
			strcpy(str,operand1);
			strcat(str,operand2);
			ch = popr();
			opr[0] = ch;
			opr[1] = '\0';
			strcat(str,opr);
			pushd(str);
	}
	printf("\n\t\t\t\t\t\t\t   The corresponding postfix expression is: ");
	printf("%s\n",opnds);
}

void PostfixEvaluation_call()
{
	float val;
	char exp[100];
	printf("\n\t\t\t\t\t\t\t\t   Enter any postfix expression: ");
	gets(exp);
	val = evaluatePostfixExp(exp);
	printf("\n\t\t\t\t\t\t\t   Value of the postfix expression = %.2f", val);
}

int pr(char elem)
{                 // Function for precedence
    switch(elem)
    {
    case '#': return 0;
    case ')': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
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
			push_char(stack_char, source[i]);
			i++;
		}
		else if(source[i] == ')')
		{
			while((top!=-1)&&(stack_char[top]!='('))
			{
				target[j] = pop_char(stack_char);
				j++;
			}
			if(top==-1)
			printf("\nIncorrect exp");
			temp = pop_char(stack_char);
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i]))
		{
			target[j++] = source[i++];
		}
		else if(IsOperator(source[i]))
		{
			while((top!=-1) && (stack_char[top]!= '(') && (getPriority(stack_char[top]) > getPriority(source[i])))
			{
				target[j] = pop_char(stack_char);
				j++;
			}
			push_char(stack_char, source[i]);
			i++;
		}
		else
		printf("\nIncorrect element in exp");
	}
	while((top!=-1) && (stack_char[top]!='('))
	{
		target[j] = pop_char(stack_char);
		j++;
	}
	target[j]='\0';
}

int getPriority(char op)
{
	if(op=='^')
	return 2;
	if(op=='/'||op == '*'||op=='%')
	return 1;
	else
	return 0;
}

void push_char(char stack[], char val)
{
	if(top==MAX-1)
	printf("\nStack Overflow");
	else
	{
		top++;
		stack[top] = val;
	}
}

char pop_char(char stack[])
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

void push_in(char elem)
{                       /* Function for PUSH operation */
    stack_char[++top]=elem;
}

char pop_in()
{                      /* Function for POP operation */
    return(stack_char[top--]);
}

void pushd(char *opnd)
{
    strcpy(opnds[++topd],opnd);
}

char *popd()
{
    return(opnds[topd--]);
}

void pushr(char opr)
{
    oprs[++topr]=opr;
}

char popr()
{
    return(oprs[topr--]);
}

int empty(int t)
{
    if(t==0)
			return 1;
    return 0;
}

float evaluatePostfixExp(char exp[])
{
	int i=0;
	float op1, op2, value;
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
			push_post(st, (float)(exp[i]-'0'));
		else
		{
			op2 = pop_post(st);
			op1 = pop_post(st);
			switch(exp[i])
			{
				case '+':
					value = op1 + op2;
					break;
				case '-':
					value = op1 - op2;
					break;
				case '/':
					value = op1 / op2;
					break;
				case '*':
					value = op1 * op2;
					break;
				case '%':
					value = (int)op1 % (int)op2;
					break;
				}
				push_post(st, value);
			}
			i++;
		}
		return(pop_post(st));
	}

	void push_post(float st[], float val)
	{
		if(top==MAX-1)
			printf("\n STACK OVERFLOW");
		else
		{
			top++;
			st[top] = val;
		}
	}

	float pop_post(float st[])
	{
		float val = -1;
		if(top==-1)
			printf("\n STACK UNDERFLOW");
		else
		{
			val = st[top];
			top--;
		}
	return val;
}
