#include <stdio.h>
#define MAX_DEGREE 10
#define MAX(a,b) (((a)>(b)) ? (a):(b)) 

typedef struct {
	int degree;
	int coef[MAX_DEGREE];
} polynomial;


// C=A+B ���⼭ A�� B�� ���׽��̴�.  
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C; //��� ���׽� 
	int Apos=0,Bpos=0,Cpos=0; //�迭 �ε��� ���� 
	int degree_a=A.degree;
	int degree_b=B.degree;
	C.degree=MAX(A.degree,B.degree); //ū ������ c�� ������ �ȴ�.  // ���� ������ ���  // ��� ���׽� ����  	
	while(Apos<=A.degree && Bpos <=B.degree) {
		 if(degree_a>degree_b){ //A��>B �� 
		 	C.coef[Cpos++] = A.coef[Apos++];
		 	degree_a--;
		 	
		 	
		 } 
		 
		 else if (degree_a ==degree_b) { //A��==B ��
		 	C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++];
		 	degree_a--;
		 	degree_b--;
		
		 }
		 else {  //A��< B��
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
			printf("%dx^%d + ",p.coef[p.degree - i ],i);
		printf("%d \n",p.coef[p.degree]);
	} 
	
	main()
	{
		int i;
		polynomial a={5,{3,6,0,0,0,10}};
		polynomial b={4,{7,0,5,0,1}};
		polynomial c;
		c=poly_add1(a,b);
		
		print_poly(a);
		print_poly(b);
		printf("---------------------------------------------------------\n");
		//print_ploy(c);
//		printf("%d",c.degree);
//		printf("%d",c.coef[0]);
	print_poly(c);
			
			
		
			
		
	}
