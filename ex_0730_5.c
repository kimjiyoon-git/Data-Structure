#include <stdio.h>
	int Factorial(int n, int a)
	{
		if(n==0)
			return a;
		
		else
		return Factorial(n-1,n*a);
		
	}
	
main(){
	int n=5,k=3,result;	
	int dp[100][100];
	int i,j;	
	for(i=1;i<=n;i++){
		dp[i][0]= dp[i][i]=1;
			for(j=1;j<i;j++){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];			 	
			}	
	}
	printf("%d\n", dp[n][k]);
	
	result=factorial(n)/(factorial(k)*factorial(n-k));
    printf("%d\n",result);
}
