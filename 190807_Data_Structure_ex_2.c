


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;
	TreeNode n1 = {50, NULL, NULL};
	TreeNode n2 = {200, NULL, NULL};
	TreeNode n3 = {500, NULL, NULL};
	TreeNode n4 = {100, &n2, &n3};
	TreeNode n5 = {0, &n1, &n4};
	TreeNode *root = &n5;
	
int postorder(TreeNode *root){
	int v1,v2,v3;
	if(root==NULL)
		return 0;
		v1 = postorder(root->left); //왼쪽 서브트리 순회 
		v2 = postorder(root->right); //오른쪽 서브트리 순회 
		v3=root->data;
		return v1+v2+v3;
}	

int main(void){
	printf("나의 문서의 크기 = %d\n", postorder(root));
}


