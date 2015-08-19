/*Finding the paths from the root to the leaf nodes*/

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

void printArray(int path[], int len){
	for (int i = 0; i < len; i++)
		printf("%d", path[i]);
	printf("\n");
	return;
}

void printPath(struct node* root, int path[], int pathLen){
	if (root == NULL) return;

	path[pathLen] = root->data;
	pathLen++;

	if (root->left == NULL && root->right == NULL)
		printArray(path, pathLen);
	else{
		printPath(root->left, path, pathLen);
		printPath(root->right, path, pathLen);
	}
}

int main(){
	int path[100];
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->left->left = newNode(4);
	root->right = newNode(8);

	printPath(root, path, 0);
}