#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
}*root=NULL,*tail=NULL;
struct node* create(int data){
	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=data;
	new1->right=NULL;
	new1->left=NULL;
	return new1;
}
void inorder(struct node *root){
	if (root!=NULL){
		inorder(root->left);
		printf("%c",root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root){
    if (root!=NULL){
		printf("%c",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root){
    if (root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c",root->data);
	}
}
int main(){
	int c=1,z;
	root=create('a');
	root->left=create('b');
	root->right=create('c');
	while(c==1){
		printf("MENU\n1.Inorder\n2.postorder\n3.preorder\n");
		printf("Enter your choice");
		scanf("%d",&z);
		switch(z){
			case 1:printf("Inorder:");
			inorder(root);
			break;
			case 2:printf("Postorder:");
			postorder(root);
			break;
			case 3:printf("Preorder:");
			preorder(root);
			break;
			default:exit(0);
		}
			printf("\nDo you want to continue:");
			scanf("%d",&c);
	}
	return 0;
}
