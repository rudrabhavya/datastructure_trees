#include <stdio.h>
#include<stdlib.h>
int n;
int tree[100] ;
int right_child(int index){
    if(tree[index]!='-' && ((2*index)+2)<=n)
        return (2*index)+2;
    return -1;
}
int left_child(int index){
    if(tree[index]!='-' && (2*index)+1<=n)
        return (2*index)+1;
    return -1;
}
void preorder(int index){
    if(index>=0 && tree[index]!='-'){
        printf("%c",tree[index]); 
        preorder(left_child(index));
        preorder(right_child(index));
    }
}
void postorder(int index){
    if(index>=0 && tree[index]!='-'){
        postorder(left_child(index));
        postorder(right_child(index)); 
        printf("%c",tree[index]);
    }
}
void inorder(int index){
    if(index>=0 && tree[index]!='-'){
        inorder(left_child(index));
        printf("%c",tree[index]); 
        inorder(right_child(index)); 
    }
}
int main(){
	int c=1,z,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for (i=0;i<n;i++)
		scanf("%c",&tree[i]);
	while(c==1){
		printf("MENU\n1.Inorder\n2.postorder\n3.preorder\n");
		printf("Enter your choice: ");
		scanf("%d",&z);
		switch(z){
			case 1:printf("Inorder:");
			inorder(0);
			break;
			case 2:printf("Postorder:");
			postorder(0);
			break;
			case 3:printf("Preorder:");
			preorder(0);
			break;
			default:exit(1);
		}
			printf("\nDo you want to continue:");
			getch();
			scanf("%d",&c);
	}
	return 0;
}
