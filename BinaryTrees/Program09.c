/*Count the number of leaf nodes*/

#include<stdio.h>
#include<malloc.h>



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

int getLeafNodeCount(struct node *root){
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else{
		return getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
	}
}

int main(){
	struct node* root = createNode(0);

	root->left = createNode(1);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->right->left = createNode(4);

	printf("%d",getLeafNodeCount(root));
}