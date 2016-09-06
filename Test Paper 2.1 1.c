#include<stdio.h>
#include<math.h>
void main()
{
	int array[]={2,1,3,5,4,6};
    float fsize=sizeof(array)/sizeof(int),
    fhalfsize=ceil(fsize/2.000000);
    int i,j,swap,size=fsize,halfsize=fhalfsize;
    //print before sorting
    printarray(array,size);
    //sort the first half of the array
    for(i=0;i<halfsize;i++){
    	for(j=i;j<halfsize;j++){
    		if(array[j]<array[i]){
    			//swap them
    			swap=array[i];
    			array[i]=array[j];
    			array[j]=swap;
    		}
    	}
    }
    //sort the second half of the array
    for(i=halfsize;i<size;i++){
    	for(j=i;j<size;j++){
    		if(array[j]>array[i]){
    			//swap them
    			swap=array[i];
    			array[i]=array[j];
    			array[j]=swap;
    		}
    	}
    }
    //print after sorting array    
    printarray(array,size);
}
void printarray(int *p,int size){
	int i;
	printf("\nArray is ");
	for(i=0;i<size;i++,p++){
		printf("%d",*p);
	}
}
