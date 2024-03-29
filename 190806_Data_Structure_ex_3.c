#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}LinkedQueueType;

// Queue 초기화 함수

void init(LinkedQueueType *q){
	q->front=q->rear=0;
} 

//공백 상태 검출 함수
int is_empty(LinkedQueueType *q){
	return (q->front==NULL);
} 

//포화 상태 검출 함수

int is_full(LinkedQueueType *q){
	return 0;
} 



//2

void enqueue(LinkedQueueType *q,element data){
	QueueNode *temp=(QueueNode *) malloc (sizeof(QueueNode));
	temp->data=data; // 데이터 저장 
	temp->link=NULL; // 링크필드를  NULL	
	if(is_empty(q)){ // 큐가 공백이면  
		q->front=temp;
		q->rear=temp;
	}
	else { // 큐가 공백이 아니면 
		q->rear->link=temp; // 순서가 중요 
		q->rear=temp;  
	}
}

//3
//삭제
element dequeue(LinkedQueueType *q){
	QueueNode *temp=q-> front;
	if(is_empty(q)) { //공백상태  
		fprintf(stderr,"스택이 비어있습니다 . \n");
		exit(1);
	}
	else {
		int data=temp->data;  
		q->front= q->front->link; //q->front=temp
		if(q->front==NULL)
			q->rear=NULL;
			free(temp);
			return data;
	}
} 

//4

void print_queue(LinkedQueueType *q){
	QueueNode *p;
	for(p=q->front; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL\n");	
}

main(){
	LinkedQueueType queue;
	init(&queue);
	enqueue(&queue,1); 
	enqueue(&queue,2); 
	enqueue(&queue,3); print_queue(&queue);
	
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	
}
