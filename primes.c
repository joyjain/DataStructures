#include<stdio.h>
void push(int []);
int pop();
int stack[10],i,j=-1;
void main()
{
	int primes[8] = {2,3,5,7,11,13,17,19};
	for(i=0;i<8;i++)
	{
		if((i+primes[i])%2==0)
			push(primes);
		else
		{
			printf("%d ",pop());
			primes[i] = i+primes[i];
		}
	}
}

void push(int primes[])
{
	stack[++j] = primes[i];
}

int pop()
{
	return stack[j--];
}
