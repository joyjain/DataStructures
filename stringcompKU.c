#include<stdio.h>
#include<string.h>
void sort(char s1[10][10]);
int comp(char s2[10],char s3[10]);
void main()
{
int i,s[10];
printf("\nEnter 10 names\n");
for(i=0;i<10;i++)
scanf("%[^\n]s",s[i]);
sort (s);
}
void sort(char s1[10][10])
{
char temp[10][10];
int i,j,n;
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if (comp(s1[i],s[j])>0)
{
strcpy(temp,s1[i]);
strcpy(s1[i],s1[j]);
strcpy(s1[j],temp);
}
}
}
printf("\nSorted Names\n");
for(i=0;i<10;i++)
printf("%s",s1[i]);
}
int comp(char s2[10],char s3[10])
{
if(strcmp(s2,s3)>0)
return 1;
else
return -1;
}
