#include <stdio.h>
#define MAX_DEGREE 10
#define MAX(a,b) (((a)>(b)) ? (a):(b)) 

typedef struct {
	int degree;
	int coef[MAX_DEGREE];
} polynomial;



polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;  
	int Apos=0,Bpos=0,Cpos=0; 
	int degree_a=A.degree;
	int degree_b=B.degree;
	C.degree=MAX(A.degree,B.degree);
	
	while(Apos<=A.degree && Bpos <=B.degree) {
		 if(degree_a>degree_b){ //A항>B 항 
		 	C.coef[Cpos++] = A.coef[Apos++];
		 	degree_a--;
		 	
		 	
		 } 
		 
		 else if (degree_a ==degree_b) { //A항==B 항
		 	C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++];
		 	degree_a--;
		 	degree_b--;
		
		 }
		 else {  //A항< B항
		 	C.coef[Cpos++] = B.coef[Bpos++];
		 	degree_b--;
		 	
		 }
		
	}
	return C;
	
}



	void print_poly(polynomial p)
	{
		int i;
		for(i=p.degree; i>0; i--)
			printf("%dx^%d+",p.coef[p.degree - i ],i);
		printf("%d \n",p.coef[p.degree]);
	} 
	
	main()
	{
		int i;
		polynomial a={5,{3,6,0,0,0,10}};
		
			polynomial b={4,{7,0,5,0,1}};
			polynomial c;
			print_poly(a);
			print_poly(b);
			c=poly_add1(a,b);
			printf("---------------------------------------------------------\n");
			print_poly(c);
			
			
		
			
		
	}
