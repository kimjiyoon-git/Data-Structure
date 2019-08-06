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

//전위 순회

void preorder(TreeNode *root){
	if(root !=NULL){
		printf("[%d]",root->data); //노드방문 
		preorder(root->left); // 왼쪽서브트리 순회 
		preorder(root->right); //오른쪽 서브트리 순회 
	}
} 

int main(void){
	printf("전위 순회 =");
	preorder(root);
	printf("\n");
}

