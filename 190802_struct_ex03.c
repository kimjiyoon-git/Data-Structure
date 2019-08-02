#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element[100];
typedef struct ListNode{ // ��� Ÿ�� 
	element data;
	struct ListNode *link;
}ListNode;

typedef struct CListType{
	ListNode *head;
}CListType;

// ����Ʈ�� �׸� ���
void print_list(CListType* L){
	ListNode *p;
	if(L->head==NULL)return;
	p= L->head->link;
	do{
		printf("%s",p->data);
		p=p->link;
	} while(p!=L->head);
	printf("%s->",p->data); //������ ��� ��� 
} 

void insert_first(CListType* L,element data){
	ListNode *node=(ListNode *)malloc(sizeof(ListNode));
	strcpy(node->data,data);
	if(L->head==NULL){
	 L->head=node;
	 node->link=L->head;
	}
	else {
		node->link=L->head->link; //(1)
		L->head->link=node; //(2)
	}
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׎c
 int main(void){
 	CListType list={NULL};
 	
 	insert_first(&list,"KIM");
 	insert_first(&list,"PARK");
 	insert_first(&list,"CHOI");
 	
 	ListNode* p=list.head;
 	int i;
 	for(i=0; i<10; i++){
 		printf("���� ���� : %s \n",p->data);
 		p=p->link;
 		
}
	 }
 

