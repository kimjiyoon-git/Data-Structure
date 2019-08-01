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
		printf("----%d----\n", L->list[position]);
		L->length++;
	}
}
//����Ʈ ���
void display(ArrayListType *L){
	int i;
	for(i=0; i<L->length; i++)
	printf("%d\n", L->list[i]);
} 


/*element delete(ArrayListType *L, int position)
{
	int i,postion,error;
	element item;
	
	if(position <0 || position >= L->length)
	error("��ġ����");
	item=L->list[postion];
	for(i=position; i<(L->length-1);i++)
	L->list[i]=L->list[i+1];
	L->length--;
	return item; 
}
*/

main(){
	ArrayListType list1;
	ArrayListType *plist;
	
	// ListType�� �������� �����ϰ� ����Ʈ Ÿ���� ����Ű�� �����͸� �Լ��� �Ķ���ͷ� �����Ѵ�. 
	
	init(&list1);
	add(&list1,0,10); 
	add(&list1,0,20); 
	add(&list1,0,30); 
	add(&list1,1,40); 
	add(&list1,2,50); 
	display(&list1);
}


//���� ó�� �Լ�
//void error(char *message){
//	fprintf(stderr,"%s\n",message);
//	exit(1);
//} 





