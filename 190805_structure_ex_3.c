#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int element;
typedef struct StackNode {
	element item;
	struct StackNode *link;
}StackNode;

typedef struct {
	StackNode *top;
}LinkedStackType;

//�ʱ�ȭ �Լ� 
void init(LinkedStackType *s){
	s->top=NULL;
}

//���� ���� ���� �Լ�  
int is_empty(LinkedStackType *s){
	return(s->top==NULL);
} 

int is_full(LinkedStackType *s){
	return 0;
} 

//���� �Լ� 
void push(LinkedStackType *s,element item){
	StackNode *temp=(StackNode *)malloc(sizeof(StackNode));
	temp->item=item;
	temp->link=s->top;
	s->top=temp;
}

void print_stack(LinkedStackType *s){
	StackNode *p;
	for(p=s->top; p !=NULL; p=p->link)
		printf("%d ->",p->item);
	printf("NULL \n");	
}

//���� �Լ� 

element pop(LinkedStackType *s){
	if(is_empty(s)) {
		fprintf(stderr,"������ ������� \n");
		exit(1);
	} 
	else {
		StackNode *temp;
		temp=s->top;
		int item=temp->item;
		s->top=s->top->link;
//		s->top=temp->link;
		free(temp);
		return item;
	}	
}

int main(void){
	LinkedStackType s ;
	init(&s);
	push(&s, 805);
	print_stack(&s);
	
	push(&s, 806);
	print_stack(&s);

	push(&s,807);
	print_stack(&s);
	
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	
	return 0;
	
	
}
 
