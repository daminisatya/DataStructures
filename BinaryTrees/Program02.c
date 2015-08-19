/*Size of the tree */

#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

struct node* newNode(int data){
	struct node * node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

int size(struct node* node){
	if (node == NULL)
		return 0;
	return (size(node->left) + 1 + size(node->right));
}

int main(){
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	printf("%d is the size of the tree", size(root));
}