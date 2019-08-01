
//���� 3 (20-10-30-50 -> 30 �����ϱ�_) 
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode { //���Ÿ�� 
	element data;
	struct ListNode *link;
	
}ListNode;


ListNode* insertLastNode(ListNode *head,element value){
	ListNode *temp;
	ListNode *p=(ListNode *)malloc(sizeof(ListNode));
	p->data=value;
	p->link=NULL; 
	temp=head;  
	while(temp->link !=NULL)
		temp=temp->link;
	temp->link=p;
	return head;
	}
	
	
	//�߰� 
	ListNode* search_list(ListNode *head,element value){
	ListNode *p=head;
	while(p !=NULL) {	
		if(p->data==value)
			return p;
		p=p->link;
	}
	return NULL;
}
 


  

	ListNode* insert_first(ListNode *head,element value){
	ListNode *p=(ListNode *)malloc(sizeof(ListNode));
	p->data=value;
	p->link=head; //NULL ��� ���� (�߰� ��带 ����) 
	head=p; // ��� ������ ����  
	return head;
	}
	

		void display(ListNode *head)
	{
		ListNode *p = head;
		for(p=head; p != NULL; p=p->link)
		printf("%d ->",p->data);
		printf("NULL \n");
		
	}
	
	ListNode* insert(ListNode *head,ListNode*pre,element value){
	ListNode *p=(ListNode *)malloc(sizeof(ListNode));
	p->data=value;
	p->link=pre->link; 
	pre->link=p;
	return head;
	}
	
	
	//����
	ListNode* delete_first(ListNode *head){
		ListNode *removed;
		if(head=NULL)
		return NULL;
		removed=head;
		head=removed->link;
		free(removed);
		return head;
	}
	
	ListNode *delete(ListNode *head,ListNode *pre)
	{
		ListNode *removed;
		removed=pre->link;
		pre->link-removed->link;
		free(removed);
		return head;
	}
	 
	
	main(void)
	{
		ListNode *head=NULL;
		head=insert_first(head,10);
		head=insert_first(head,20);
		head=insertLastNode(head,50);
		display(head);
		head=insert(head,search_list(head,10),30);
		display(head);
		//head=delete(head,delete_first(50));
		head=delete_first(head);
		display(head);
		
	
	}

