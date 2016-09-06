#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort()
{
char name[10][8],tname[10][8],temp[8],thename[8];
    int i,j,n;
    printf("Enter the number of names\n");
    scanf("%d",&n);
    printf("Enter %d names\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i]);
        strcpy(tname[i],name[i]);
    }
   for(i=0;i<n-1;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(strcmp(name[i],name[j])>0)
           {
               strcpy(temp,name[i]);
               strcpy(name[i],name[j]);
               strcpy(name[j],temp);
           }
       }
   }
   printf("Enter the name to compare");
   scanf("%s", thename);
   //compare the two strings using strcmp
   for(i=0;i<n-1;i++)
   {
        int comparison = strcmp(thename,name[i]);
        if(comparison<0)
		{
            printf("%s is less than %s",thename,name);
        }
        else if(comparison>0)
        {
            printf("%s is greater than %s",thename,name);
        }
        else
		{
            printf("%s is equal to %s",thename,name);
        }
   }
}
