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

// Queue �ʱ�ȭ �Լ�

void init(LinkedQueueType *q){
	q->front=q->rear=0;
} 

//���� ���� ���� �Լ�
int is_empty(LinkedQueueType *q){
	return (q->front==NULL);
} 

//��ȭ ���� ���� �Լ�

int is_full(LinkedQueueType *q){
	return 0;
} 



//2

void enqueue(LinkedQueueType *q,element data){
	QueueNode *temp=(QueueNode *) malloc (sizeof(QueueNode));
	temp->data=data; // ������ ���� 
	temp->link=NULL; // ��ũ�ʵ带  NULL	
	if(is_empty(q)){ // ť�� �����̸�  
		q->front=temp;
		q->rear=temp;
	}
	else { // ť�� ������ �ƴϸ� 
		q->rear->link=temp; // ������ �߿� 
		q->rear=temp;  
	}
}

//3
//����
element dequeue(LinkedQueueType *q){
	QueueNode *temp=q-> front;
	if(is_empty(q)) { //�������  
		fprintf(stderr,"������ ����ֽ��ϴ� . \n");
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
