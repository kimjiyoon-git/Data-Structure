#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void main(void)
{
	clock_t start,finish;
	double duration;
	double sum=0.0;
	int i;
	
	for(i=1;i<=1000000;i++)
	sum=sum+i;
	
	
	start=clock();
	
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("%f 초입니다. \n",duration);
	printf("값은 : %d \n ",sum);
}
