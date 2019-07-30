//피보나치 수열의 반복구 
#include <stdio.h>

main(){
	int fib_iter(int n)
	{
		if(n==0)
			return 0;
		
		if(n==1)
			return 1;
			
			int i;
			int pp=0;
			int p=1;
			int result=0;
			
			for(i=2; i<=n; i++){
				result=p+pp;
				pp = p;
				p=result;
			
			}
			return result;
			printf("%d",result);
	}
	
}

