/*Compare two trees and return true if same*/

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node * newNode(int data){
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

bool isSame(struct node *a, struct node *b){
	if (a == NULL && b == NULL)
		return true;
	else
		if (a != NULL && b != NULL){
			return(
				(a->data == b->data) &&
				(isSame(a->left, b->left)) &&
				(isSame(a->right, b->right))
				);
		}
	return false;
}

int main(){
	struct node *tree1 = newNode(1);
	tree1->left = newNode(2);
	tree1->right = newNode(3);

	struct node *tree2 = newNode(1);
	tree2->left = newNode(2);
	tree2->right = newNode(3);

	if (isSame(tree1, tree2))
		printf("\nThe trees are same");
	else printf("\nThe trees are not same");
}