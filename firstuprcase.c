#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	int i,count=0;
	printf("Enter a string\n");
	scanf("%[^\n]s",str);
	for(i=0;i<100;i++)
	{
		if((str[i]>=65 && str[i]<=90) && (str[i+1]>=97 && str[i+1]<=122))
			++count;
	}
	printf("The number of words with first letter capital is: %d",count);
}
