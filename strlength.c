#include<stdio.h>
#include<string.h>
void main()
{
int i,count=0;
char ch[100];
printf("Type a sentence\n");
scanf("%[^\n]s",ch);
for(i=0;ch[i]!='\0';i++)
{
if(ch[i]==' ')
{
count++;
}
}
printf("Number of words in the sentence=%d\n",count+1);
}
