#include<stdio.h>
#include<math.h>
void main()
{
	int i=0,count=0;
	char str[100];
	printf("Enter a string\n");
	scanf("%[^\n]s",str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>=65&&str[i]<=90)
		{
			if(str[i+1]>=97&&str[i+1]<=122)
			{
			count++;
			}
		}
	}
	printf("The number of words starting with capital are \"%d\"",count);
}
