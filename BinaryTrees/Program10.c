/*Checking for sum property*/

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *createNode(int data){
	struct node *node = (struct node*)malloc((sizeof(struct node)));
	node->left = NULL;
	node->right = NULL;
	node->data = data;

	return node;
}

bool isSumProperty(struct node *root){
	int rightNode = 0;
	int leftNode = 0;
	if (root == NULL || root->right == NULL && root->left == NULL)
		return 1;
	if (root->left != NULL)
		leftNode = root->left->data;
	if (root->right != NULL)
		rightNode = root->right->data;
	else if ((root->data == leftNode + rightNode) && isSumProperty(root->left) && isSumProperty(root->right))
		return true;
	return false;
}

int main(){
	struct node* root = createNode(0);
	root->left = createNode(1);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->right->left = createNode(4);
	if (isSumProperty(root))
		printf("True");
	else printf("False");
}