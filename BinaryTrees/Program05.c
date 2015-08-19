/*Deleting the tree by visiting each node using postorder traversal*/

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node * newNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void deleteNode(struct node *node){
	if (node == NULL)
		return;
	deleteNode(node->left);
	deleteNode(node->right);

	printf("\nThe node deleted is %d", node->data);
	free(node);
	return;
}

int main(){
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->left->left = newNode(4);
	root->right = newNode(8);

	deleteNode(root);
	root = NULL;
	printf("\n\nTree is deleted");
}