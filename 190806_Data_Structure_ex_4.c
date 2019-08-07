#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { //ťŸ�� 
int front;
int rear;
element data[MAX_QUEUE_SIZE];
}DequeType;

//error function
void error(char *message){
	fprintf(stderr,"%\n",message);
	exit(1);
}

//�ʱ�ȭ 
void init_deque(DequeType *q){
	q->front=q->rear=0;
} 

//���� ���� ���� �Լ�  
int is_empty(DequeType *q){
		return (q->front==q->rear);
}

//��ȭ ���� ���� �Լ� 
int is_full(DequeType *q){
	return((q->rear+1) % MAX_QUEUE_SIZE==q->front);
	}

//����ť ��� �Լ�
void deque_print(DequeType *q){
	printf("DEQUE(front=%d rear=%d) = " , q->front, q->rear);
		if(! is_empty(q)){
		int i=q->front;
		do {
			i=(i+1) % (MAX_QUEUE_SIZE);
			printf("%d |", q->data[i] );
			if(i==q->rear)
			break;
	    }while(i != q->front);
			}
		printf("\n");
	
}

void add_rear(DequeType *q,element item)
{
		if(is_full(q))
			error("ť�� ��ȭ�����Դϴ�.");
		q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
		q->data[q->rear]=item; 
}

element delete_front(DequeType *q){
	if(is_empty(q))
	error("ť�� �����Դϴ�.");
	q->front=(q->front+1)%MAX_QUEUE_SIZE;
	return q->data[q->front]; 
}

void add_front(DequeType *q,element val)
{
		if(is_full(q))
			error("ť�� ��ȭ�����Դϴ�.");
		q->data[q->front]=val;
		q->front=(q->front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
}

void enqueue(DequeType *q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}



// ���� �Լ�
element dequeue(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}



element delete_rear(DequeType *q)
{
	int prev=q->rear;
	if(is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->rear=(q->rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_front(DequeType *q) 
{
	if(is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}
 
element get_rear(DequeType *q)
{
	if(is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->rear];
}

main(){

	DequeType queue;
	
	init_deque(&queue);
	int i;
	for(i=0; i<3; i++){
		add_front(&queue,i);
		deque_print(&queue);
	}
	for(i=0; i<3; i++){
		delete_rear(&queue);
		deque_print(&queue);
			
	}
}