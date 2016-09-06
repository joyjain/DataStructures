#include<stdio.h>
#include<stdlib.h>
void main()
{
	char ch;
	FILE *fp;
	fp=fopen("randikailash.txt","w");
	if(fp==NULL)
	{
		printf("\nCannot open file");
	}
ch=getch();
while(ch!=EOF)
{
	fputc(ch,fp);
	ch=getch();
}
}
