// 괄호 알고리즘 검사  


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100

typedef char element;

// =========스택 코드의 시작 ========
 
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수  
void init(StackType *s){
	s->top=-1;
} 

// 공백 상태 검출 함수 
int is_empty(StackType *s){
	return (s->top==-1);
}

//포화 상태 검출 함수  
int is_full(StackType *s){
	return (s->top ==(MAX_STACK_SIZE-1));
}

void push(StackType *s,element item)
{
	if(is_full(s)){
		fprintf(stderr,"스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)]=item;
	}
	
element pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType *s)
{
	if(is_empty(s)){
		fprintf(stderr,"스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

eval(char exp[])
{
	int op1,op2,value,i = 0;
	int len=strlen(exp);
	char ch;
	StackType s;
	
	init(&s);
	for(i=0; i<len; i++){
		ch=exp[i];
		if(ch !='+' && ch !='-' && ch != '*' && ch !='/' ){
			value=ch-'0';
			push(&s,value);
		}
		else {
			op2=pop(&s);
			op1=pop(&s);
			switch(ch){
				case '+' : push(&s,op1+op2); break;
				case '-' : push(&s,op1-op2); break;
				case '*' : push(&s,op1*op2); break;
				case '/' : push(&s,op1/op2); break;
			}
		}
	}
	return pop(&s);
 } 
 int main(void){
 	int result;
 	printf("후위 표기식은 82/3-32*+\n");
 	result=eval("82/3-32*+");
 	printf("결과값은 %d\n",result);
 	return 0;
 }

