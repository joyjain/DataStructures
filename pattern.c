#include<stdio.h>
void main()
{
	int i,j,k,n;
	printf("Enter the number if rows upto which pattern is to be printed.\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n-i;j++)
		{
		printf(" ");
		}
		for(k=0;k<i;k++)
		{
			system("COLOR 08");
			printf("*");
		}
		printf("\n");
	}
}
