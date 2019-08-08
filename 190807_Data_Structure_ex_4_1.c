#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;
	TreeNode n1 = { 50, NULL, NULL };
	TreeNode n2 = { 200, NULL, NULL };
	TreeNode n3 = { 500, NULL, NULL };	
	TreeNode n4 = { 100, &n2, &n3 };	
	TreeNode n5 = { 0, &n1, &n4 };
	TreeNode *root = &n5;	
	
int postorder(TreeNode *root){
	int left_size, right_size, total;
	if (root == NULL) 
		return 0;
	left_size = postorder(root->left);
	right_size = postorder(root->right);
	total = root->data + left_size + right_size;
	return total;
}

int main(void){	
	printf("나의 문서 크기=%d\n", postorder(root));
}
