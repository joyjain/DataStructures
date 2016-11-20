#include<stdio.h>
void main()
{
	int a, b, c, secl, smal, larg;
	printf("Enter the first number: ");
	scanf("%d",&a);
	printf("Enter the second number: ");
	scanf("%d",&b);
	printf("Enter the third number: ");
	scanf("%d",&c);
	smal = a<b?(a<c?a:c):(b<c?b:c);
	larg = a>b?(a>c?a:c):(b>c?b:c);
	secl = (((larg==a&&smal==b)||(larg==b&&smal==a))?c:(((larg==c&&smal==a)||(larg==a&&smal==c))?b:(((larg==b&&smal==a)||larg==a&&smal==b)?c:c)));
	printf("The second largest number is: %d",secl);
}
