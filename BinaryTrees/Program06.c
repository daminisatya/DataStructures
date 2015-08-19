/*Finding the mirror of the tree and checking using inorder traversal*/

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

void mirror(struct node * node){
	if (node == NULL)
		return;
	else{
		struct node * temp;
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
	return;
}

void inorder(struct node *node){
	if (node == NULL)
		return;
	inorder(node->left);

	printf("%d", node->data);
	inorder(node->right);
	return;
}

int main(){
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->left->left = newNode(4);
	root->right = newNode(8);

	printf("\nThe inorder traversal before mirroring\n");
	inorder(root);

	mirror(root);

	printf("\nThe inorder traversal after mirroring\n");
	inorder(root);

}