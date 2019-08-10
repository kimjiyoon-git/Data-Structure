//
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t)((t)=(x) , (x)=(y),(y)=(t))



//���Կ���
 
void insertion_sort(int list[], int n) 
{
	int i,j,key;
	for(i=1; i<n; i++) {
		key=list[i];
		for(j=i-1; j>=0 && list[j]>key; j--)
			list[j+1]=list[j]; //���ڵ��� ������ ���� 
		list[j+1]=key; 
	}
}
int list[MAX_SIZE];
int n;
void selection_sort(int list[],int n){
	int i,j,least,temp;
	for(i=0; i<n-1; i++){
		least=i;
		for(j=i+1;j<n;j++)
			if(list[j]<list[least])
				least=j;
		SWAP(list[i],list[least],temp);
	}
}

//

int main(void){
	int i;
	n=MAX_SIZE;
	srand(time(NULL));
	for(i=0; i<n; i++) //���� ���� �� ��� 
		list[i]=rand()%100; // ���� �߻� ���� 0~99 
		
		selection_sort(list,n);
		for(i=0; i<n; i++)
			printf("%d ", list[i]);
		printf("\n");
		
		insertion_sort(list,n);
		for(i=0; i<n; i++)
			printf("%d ", list[i]);
		printf("\n");
		return 0;
}
