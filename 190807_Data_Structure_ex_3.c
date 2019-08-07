#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;
	TreeNode n1 = {3, NULL, NULL};
	TreeNode n2 = {2, NULL, NULL};
	TreeNode n3 = {'*', &n1, &n2};
	TreeNode n4 = {5, NULL, NULL};
	TreeNode n5 = {6, NULL, NULL};
	TreeNode n6 = {'*', &n4, &n5};
	TreeNode n7 = {'+', &n3, &n6};
	TreeNode *root = &n7;

int evaluate(TreeNode *root){
	int op1,op2;
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d�� ����մϴ�. \n", op1, root->data, op2);
		switch(root->data){
			case '+':
				return op1 + op2;
			case '-':
				return op1 - op2;
			case '*':
				return op1 * op2;
			case '/':
				return op1 / op2;
		}
	}
	return 0;
}

			
int main(void){
	printf("����Ʈ�� ���  = %d\n", evaluate(root));
}

