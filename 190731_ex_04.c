//희소행렬 표현 방법 

#include<stdio.h>
#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a) { //정렬하면서 전치행렬 구현 
SparseMatrix b;
	int c, i,bindex; //행렬 b에서 현재 저장 위치,c가 열의 오름차순의 기준 
	b.rows=a.rows;
	b.cols=a.cols;
	b.terms=a.terms; //데이터 개수 
	
	if(a.terms>0){
		bindex=0;
		for(c=0;c<a.cols; c++){
			for(i=0;i<a.terms; i++){
				if(a.data[i].col==c){ // 오름 기준 (c=0 인덱스가 열값 ( a배열 data의 열) 
					b.data[bindex].row=a.data[i].col;
					b.data[bindex].col=a.data[i].row;
					b.data[bindex].value=a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b; 
}

void matrix_print(SparseMatrix a){
	printf("====================\n");
	int i;
	for(i=0; i<a.terms; i++){
		printf("(%d %d %d) \n",a.data[i].row,a.data[i].col,a.data[i].value);
		
	}
	printf("====================\n");	
}
int main(void){
	SparseMatrix m = {{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7};
	SparseMatrix result;
	result=matrix_transpose2(m); 
	matrix_print(result);
	return 0;
}
