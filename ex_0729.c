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
	printf("%f ���Դϴ�. \n",duration);
	printf("���� : %d \n ",sum);
}
