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

int check_matching(char *in){
	StackType s;
	char ch,open_ch;
	int i,n=strlen(in);
	init(&s);
	for(i=0; i<n; i++){
		ch=in[i];
		switch(ch){
			case '(': case '[': case '{':
				push(&s,ch); break;
				
				case ')': case ']': case '}':
				if(is_empty(&s)) return 0;
				else{
					open_ch=pop(&s);
					if((open_ch== '(' && ch != ')' )||(open_ch== '[' && ch != ']' ) ||(open_ch== '{' && ch != '}'))	
						return 0;	 
				}
				break;
		}
	}
	return 1;
}


 int main(void){
 	char *p="{(A[(i+1)]=0);}";
 	if(check_matching(p)==1) 
 		printf("%s 괄호 검사성공 \n",p);
	else
		printf("%s 괄호 괄호 실패  \n",p);
 	return 0;
 }

