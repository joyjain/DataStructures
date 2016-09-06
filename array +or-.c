#include <stdio.h>
void main()
{
    int i,j,m,n,arr[20][20];
    printf("Enter the size of 2D array\n");
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]>=0)
            {
                printf("Entered array element \"%d\" is positive",arr[i][j]);
                if(arr[i][j]>=0&&arr[i][j]<=9)
                printf(" and is a single digit\n",arr[i][j]);
                else
                printf(" and is not a single digit\n",arr[i][j]);
            }
            else
            {
            printf("Entered array element \"%d\" is negative",arr[i][j]);
            if(arr[i][j]<=-1&&arr[i][j]>=-9)
            printf(" and is a single digit\n",arr[i][j]);
            else
            printf(" and is not a single digit\n",arr[i][j]);
            }
        }
    }
}
