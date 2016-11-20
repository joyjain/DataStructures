#include<stdio.h>

int getArrayFilledSize(int []);

void main()
{
	int array[10] = {[0 ... 9] = -1}, n=0, i;
//	array[0] = 25;
//	array[1] = 25;
	for(i=0;i<10;i++)
		printf("%d ",array[i]);
	n = getArrayFilledSize(array);
    printf("size: %d",n); //result 10
}

int getArrayFilledSize(int nodes[])
{
	int length=0;
	while(nodes[length] != -1){
		length++;
	}
	return length;
}
