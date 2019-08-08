//트리 노드개수 높이  

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define max(a,b) ((a>b)? (a):(b))
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;
int get_node_count(TreeNode *node) {
	int count=0;
	if(node != NULL)
		count=1+get_node_count(node->left)+get_node_count(node->right);
	return count;
} 

int get_height(TreeNode *node) {
	int height =0, h1=0;
	if(node != NULL)
		height= 1 + max(get_height(node->left), get_height(node->right));
	return height;	
}
//		  15
//	   4		 20
//    1	      16  25
main(void){	
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

printf("트리의 노드 갯수 : %d \n", get_node_count(root));
printf("트리의 높이 : %d \n", get_height(root));
}
