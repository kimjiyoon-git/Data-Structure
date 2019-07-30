#include <stdio.h>
	int Factorial(int n, int a)
	{
		if(n==0)
			return a;		
		else
		return Factorial(n-1,n*a);		
	}
	
main(){	
    int result,n,a=1;
    
    printf("숫자를 입력하세요: ");
    scanf("%d", &n);
	
	result=Factorial(n,a);
    printf("%d\n",result);
}
