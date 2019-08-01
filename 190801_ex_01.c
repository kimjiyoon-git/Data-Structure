#include<stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 10

typedef int element;
typedef struct {
	int list[MAX_LIST_SIZE]; // �迭���� 
	int length; // ���� �迭�� ����� �׸���� ���� 
}ArrayListType;

//����Ʈ �ʱ�ȭ  
void init(ArrayListType *L)
{
	L->length=0;
}

// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ  
int is_empty(ArrayListType *L)
{
	return L->length==0;
}

//����Ʈ�� ��� ������ 1�� ��ȯ
//�׷��� ������ 0�� ��ȯ 

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
//����Ʈ ���
void display(ArrayListType *L){
	int i;
	for(i=0; i<L->length; i++)
	printf("%d\n", L->list[i]);
} 

main(){
	ArrayListType list1;
	ArrayListType *plist;
	
	// ListType�� �������� �����ϰ� ����Ʈ Ÿ���� ����Ű�� �����͸� �Լ��� �Ķ���ͷ� �����Ѵ�. 
	
	init(&list1);
	add(&list1,0,10); 
	add(&list1,0,20); 
	add(&list1,0,30); 

	display(&list1);
}









