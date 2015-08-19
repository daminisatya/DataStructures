/*Implementing tree traversals*/

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printPostOrder(struct node *node){
	if (node == NULL)
		return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	printf("%d", node->data);
	return;
}

void printPreOrder(struct node *node){
	if (node == NULL)
		return;
	printf("%d", node->data);
	printPreOrder(node->left);
	printPreOrder(node->right);
	return;
}

void printInOrder(struct node *node){
	if (node == NULL)
		return;
	printInOrder(node->left);
	printf("%d", node->data);
	printInOrder(node->right);
	return;
}

int main() {
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	printf("\nThe preorder traversal");
	printPreOrder(root);

	printf("\nThe postorder traversal");
	printPostOrder(root);

	printf("\nThe Inorder traversal");
	printInOrder(root);

}