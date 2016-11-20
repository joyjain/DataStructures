#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 100
void main()
{
	int bst[size], levels, n, i;
	printf("Enter the number of levels in your BST: ");
	scanf("%d",&levels);
	for(i=0;i<levels;i++)
		n = n + pow(2,i);
	printf("Enter the elements for your BST: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bst[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",bst[i]);
	}
}
