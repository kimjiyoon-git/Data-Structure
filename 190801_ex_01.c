#include<stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 10

typedef int element;
typedef struct {
	int list[MAX_LIST_SIZE]; // 배열정리 
	int length; // 현재 배열의 저장된 항목들의 개수 
}ArrayListType;

//리스트 초기화  
void init(ArrayListType *L)
{
	L->length=0;
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환  
int is_empty(ArrayListType *L)
{
	return L->length==0;
}

//리스트가 비어 있으면 1을 반환
//그렇지 않으면 0을 반환 

int is_full(ArrayListType *L){
	return L->length==MAX_LIST_SIZE;
}

void add(ArrayListType *L, int position,element item)
{
	if(!is_full(L)&&(position >=0)&&(position <=L->length)) {
		int i;
		for(i=(L->length-1); i>=position; i--)
			L->list[i+1]=L->list[i];
		L->list[position]=item;
		L->length++;
	}
}
//리스트 출력
void display(ArrayListType *L){
	int i;
	for(i=0; i<L->length; i++)
	printf("%d\n", L->list[i]);
} 

main(){
	ArrayListType list1;
	ArrayListType *plist;
	
	// ListType을 정적으로 생성하고 리스트 타잎을 가리키는 포인터를 함수의 파라미터로 전달한다. 
	
	init(&list1);
	add(&list1,0,10); 
	add(&list1,0,20); 
	add(&list1,0,30); 

	display(&list1);
}









