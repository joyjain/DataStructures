#include<stdio.h>  
int call(int);
int main()
    {
        int z,num=0;
        z = call(num);
        printf("%d",z); 
        return 0;
        
    }
    
    int call(int num)
    {
	int y=1,x=1;
    if(num<4)
    	{
        x=3*x+num;
        y=call(x+1)+2+call(x+3);  
		} 
        return y;
	}
