/*Level order traversal*/

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

int height(struct node *root){
	if (root == NULL)
		return 0;
	else {
		int lheight = height(root->left);
		int rheight = height(root->right);
		if (lheight > rheight)
			return lheight + 1;
		else return rheight + 1;
	}
}


void getLevelTraversal(struct node *root, int level){
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d", root->data);
	else if (level > 1){
		getLevelTraversal(root->left, level - 1);
		getLevelTraversal(root->right, level - 1);
	}
}

void printLevelTraversal(struct node *root){
	int h = height(root);

	for (int i = 1; i <= h; i++)
		getLevelTraversal(root, i);
}


int main(){
	struct node* root = createNode(0);

	root->left = createNode(1);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->right->left = createNode(4);

	printLevelTraversal(root);
}