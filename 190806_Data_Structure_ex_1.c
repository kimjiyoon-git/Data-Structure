// ť 1 
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
int front;
int rear;
element data[MAX_QUEUE_SIZE];
}QueueType;

//error function
void error(char *message){
	fprintf(stderr,"%\n",message);
	exit(1);
}

void init_queue(QueueType *q){
	q->rear=-1;
	q->front=-1;
}

void queue_print(QueueType *q){
	int i;
	for(i=0; i<MAX_QUEUE_SIZE; i++){
		if(i<q->front || i>q->rear)
		printf(" |");
	else
		printf("%2d |",q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType *q){
	if(q->rear == MAX_QUEUE_SIZE-1)
		return 1;
	else
		return 0;
		
}
int is_empty(QueueType *q){
	if(q->front==q->rear)
		return 1;
	else 
		return 0;
}

void enqueue(QueueType *q,int item){
	if(is_full(q)){
		error("ť�� ��ȭ �����Դϴ�.");
		return; 
	}
	q->data[++(q->rear)]=item;
}
int dequeue(QueueType *q){
		if(is_empty(q)){
		error("ť�� ���� �����Դϴ�");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

main(){
	int item =0;
	QueueType q;
	init_queue(&q);
	enqueue(&q,10); queue_print(&q);
	enqueue(&q,20); queue_print(&q);
	enqueue(&q,30); queue_print(&q);
	dequeue(&q); queue_print(&q);
	dequeue(&q); queue_print(&q);
	dequeue(&q); queue_print(&q);
	
			
}