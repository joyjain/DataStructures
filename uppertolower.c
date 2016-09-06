#include<stdio.h>
void main()
{
	int i,*p;
	char str[100],ch;
	printf("Enter a sentence\n");
	for(i=0;i<2;i++)
	{
	scanf("%c",&ch);
	*p=*(&ch);
	}
	if(*p>=97&&*p<=122)
	ch=ch-32;
	printf("String in uppercase is %c",ch);
}
