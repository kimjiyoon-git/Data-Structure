#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left,*right;
}TreeNode;

TreeNode n1={1,NULL,NULL};
TreeNode n2={4, &n1,NULL};
TreeNode n3={16,NULL,NULL};
TreeNode n4={25,NULL,NULL};
TreeNode n5={20 , &n3, &n4};
TreeNode n6={15, &n2,&n5};
TreeNode *root = &n6;

//���� ��ȸ

void preorder(TreeNode *root){
	if(root !=NULL){
		printf("[%d]",root->data); //���湮 
		preorder(root->left); // ���ʼ���Ʈ�� ��ȸ 
		preorder(root->right); //������ ����Ʈ�� ��ȸ 
	}
} 

int main(void){
	printf("���� ��ȸ =");
	preorder(root);
	printf("\n");
}

