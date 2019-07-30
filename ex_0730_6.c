#include <stdio.h>
	int Factorial(int n, int a)
	{
		if(n==0)
			return a;		
		else
		return Factorial(n-1,n*a);		
	}
	
main(){	
    int result,n=6,a;
	result=Factorial(n,a);
    printf("%d\n",result);
}
