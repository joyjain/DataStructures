#include <stdio.h>
int main()
{
    int i,n,arr[50],position;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
	printf("Enter the location of an element you wish to delete\n");
    scanf("%d", &position);
	if ( position >= n+1 )
      printf("Deletion not possible.\n");
    else
    {
      for (i=position-1;i<n-1;i++)
         arr[i]=arr[i+1];

      printf("Resultant array is\n");
      for(i=0;i<n-1;i++)
      {
         printf("%d",arr[i]);
         if(i<n-1)
         printf(",");
      }
    }
    return 0;
}
