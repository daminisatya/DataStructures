/*Finding the maximum Depth of a given tree*/

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

int getMaxDepth(struct node* node){
	if (node == NULL)
		return 0;
	else {
		int lDepth = getMaxDepth(node->left);
		int rDepth = getMaxDepth(node->right);

		if (lDepth > rDepth)
			return (lDepth + 1);
		else return (rDepth + 1);
	}
}

int main(){
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->left->left = newNode(5);
	printf("The maximum depth is %d", getMaxDepth(root));
}