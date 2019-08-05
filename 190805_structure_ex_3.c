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

//초기화 함수 
void init(LinkedStackType *s){
	s->top=NULL;
}

//공백 상태 검출 함수  
int is_empty(LinkedStackType *s){
	return(s->top==NULL);
} 

int is_full(LinkedStackType *s){
	return 0;
} 

//삽입 함수 
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

//삭제 함수 

element pop(LinkedStackType *s){
	if(is_empty(s)) {
		fprintf(stderr,"스택이 비어있음 \n");
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
 
