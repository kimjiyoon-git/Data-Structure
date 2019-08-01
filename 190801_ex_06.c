#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;
ListNode* insert_first(ListNode *head, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	
	p->data = value;					
	p->link = head;	// NULL 대신 복사(추가 노드를 위해) 
	head = p;	// 헤드 포인터 변경		
	return head;
}





ListNode* insertLastNode(ListNode *head, element value) {
	ListNode *temp;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;	
	temp = head;
	while (temp->link != NULL) 
		temp = temp->link;	// 현재 리스트의 마지막 노드를 찾음
	temp->link = p;	
	return head;						// 새 노드를 마지막 노드(temp)의 다음 노드로 연결 
}

ListNode* search_list(ListNode *head, element value) {
	ListNode *p = head;
	while (p != NULL) {
		if (p->data == value) 
			   return p;  //return <==> p=p->link 순서에 따라 앞 뒤 추가가 가능		
		p = p->link; 		
	}
	return NULL;	// 탐색 실패
}
// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode *head){
	ListNode *removed;
	if (head == NULL) 
		return NULL;
	removed = head;	
	head = removed->link;	
	free(removed);		
	return head;		
}
//// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void display(ListNode *head){
	ListNode *p=head;
	while(p!=NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
//	for (p = head; p != NULL; p = p->link)
//		printf("%d->", p->data);
	printf("NULL \n");
}

int main(void){
	ListNode *head = NULL;
	head = insert_first(head, 10);	
	head = insert_first(head, 20);
	display(head);
	head = insertLastNode(head, 50);
	display(head);
	head = insert_first(head, 30);
	display(head);
//	p = search_list(head, 20);	
	head = insert(head, search_list(head, 20), 111);
	display(head);
	head = delete_first(head);
	display(head);
//head = delete(head, search_list(head, 10));
	//display(head);	
}
	
	

