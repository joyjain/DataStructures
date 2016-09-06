#include <stdio.h>
int main()
{
    int i,n,arr[50],insert,position;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
	printf("Enter the location where you wish to insert an element\n");
    scanf("%d", &position);
	printf("Enter the element which you want to insert\n");
	scanf("%d",&insert);
	for (i=n-1;i>=position-1;i--)
      arr[i+1] = arr[i];
	arr[position-1] = insert;
	printf("You entered array\n");
	for(i=0;i<n+1;i++)
    {
    	printf("%d",arr[i]);
    	if(i<n)
    	printf(",");
	}
	return 0;
}
