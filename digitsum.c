#include<stdio.h>
#include<math.h>
void main()
{
	int num,sum,x,y;
	printf("Enter a number\n");
	scanf("%d",&num);
	y=num;
	while(y!=0)
	{
		x=y%10;
		sum+=x;
		y=y/10;
	}
	/*if(num>=10&&num<=99)
	{
		x=num%10;
		num/=10;
		sum=num+x;
	}
	else if(num>=100&&num<=999)
	{
		x=num%100;
		y=x/10;
		num/=100;
		x%=10;
		sum=num+x+y;
	}*/
	printf("Sum of the digits of number \"%d\" is %d\n",num,sum);
}
