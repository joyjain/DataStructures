#include<stdio.h>
#include<math.h>
void main()
{
int i,j,m,n,sum=0,det=0,mat[10][10];
printf("Enter the order of the square matrix\n");
scanf("%d%d",&m,&n);
printf("Enter the elements of the matrix\n");
for(i=0;i<m;++i)
{
for(j=0;j<n;++j)
{
scanf("%d",&mat[i][j]);
}
}
for(j=0;j<n;++j)
{
sum=sum+((mat[1][j])*((mat[2][(j+1)])*(mat[3][(j+2)]))-((mat[3][(j+1)])*(mat[2][(j+2)])));
}
printf("\nDeterminant of matrix is %d\n",sum);
}
