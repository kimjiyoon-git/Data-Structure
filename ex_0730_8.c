#include<stdio.h>

main(){
	int ARR_MAX = 4;
	int a[]={8,0,7,1};
	int b[]= {10,3,0,1};
	int c[3];
	int i;
	
	for(i=0;i<ARR_MAX;i++){
		c[i]=a[i]+b[i];
		
	}
      
	for(i=0;i<ARR_MAX-1;i++){
		printf("%dx^%d + ",c[i],(ARR_MAX-i-1));		
	}
	printf("%d ",c[ARR_MAX-1]);	
	
}
