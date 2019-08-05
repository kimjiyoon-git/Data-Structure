#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType *s){
	s->top=-1;
} 

int is_empty(StackType *s){
	return (s->top==-1);
}

int is_full(StackType *s){
	return (s->top ==(MAX_STACK_SIZE-1));
}

void push(StackType *s,element item)
{
	if(is_full(s)){
		fprintf(stderr,"���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)]=item;
	}
	
element pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType *s)
{
	if(is_empty(s)){
		fprintf(stderr,"���� ���� ����\n");
		exit(1);
	}
	else return s->stack[s->top];
}
 int main(void){
 	StackType *s;
 	s=(StackType *)malloc(sizeof(StackType)); //�����Ҵ�  
	init(s);
	push(s,10); 
 	push(s,20);
 	push(s,30); 	
 	printf("%d\n",pop(s));
 	printf("%d\n",pop(s));
 	printf("%d\n",pop(s)); 	
 	return 0;
 }


/*
 int main(void){
 	StackType s;
	init(&s);
	push(&s,10); 
 	push(&s,20);
 	push(&s,30); 	
 	printf("%d\n",pop(&s));
 	printf("%d\n",pop(&s));
 	printf("%d\n",pop(&s)); 	
 	return 0;
 }
 */
