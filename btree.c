#include <stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};struct node* root;

BinaryTree() {
	root = NULL;
}

void addNode(int data) {
	struct node* newNode = (struct node *)malloc(sizeof(struct node));

	if (root == NULL) {
	root = newNode;
	} 
	else {
	struct node* temp = root;
	struct node* parent;

	while (1) {
		parent = temp;

		if (data < temp->data) {
		temp = temp->left;
		if (temp == NULL) {
			parent->left = newNode;
			return;
		}
		} else {
		temp = temp->right;
		if (temp == NULL) {
			parent->right = newNode;
			return;
		}
		}
	}
	}
}



int main() {
BinaryTree();

addNode(50);
addNode(25);
addNode(75);
addNode(12);
addNode(37);
addNode(43);
addNode(30);

printf ("Successful");
return 0;
}

