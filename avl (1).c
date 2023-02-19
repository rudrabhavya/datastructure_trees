#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int ht;
}*root = NULL;
 struct node* create(int data){
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    if (new_node == NULL){
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
struct node* rotate_left(struct node* root){
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
    root->ht = height(root);
    right_child->ht = height(right_child);
    return right_child;
}
struct node* rotate_right(struct node* root){
    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
    root->ht = height(root);
    left_child->ht = height(left_child);
    return left_child;
}
int balance_factor(struct node* root){
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}
int height(struct node* root){
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
 
    if (lh > rh)
        return (lh);
    return (rh);
}
struct node* insert(struct node* root, int data){
    if (root == NULL){
        struct node* new_node = create(data);
        if (new_node == NULL)
            return NULL;
        root = new_node;
    }
    else if (data > root->data){
        root->right = insert(root->right, data);
        if (balance_factor(root) == -2){
            if (data > root->right->data)
                root = rotate_left(root);
            else{
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else{
        root->left = insert(root->left, data);
        if (balance_factor(root) == 2){
            if (data < root->left->data)
                root = rotate_right(root);
            else{
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    root->ht = height(root);
    return root;
}
struct node * delete(struct node *root, int x){
    struct node * temp = NULL;
 	if (root == NULL)
        return NULL;
    if (x > root->data){
        root->right = delete(root->right, x);
        if (balance_factor(root) == 2){
            if (balance_factor(root->left) >= 0)
                root = rotate_right(root);
            else{
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    else if (x < root->data){
        root->left = delete(root->left, x);
        if (balance_factor(root) == -2){
            if (balance_factor(root->right) <= 0)
                root = rotate_left(root);
            else{
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else{
        if (root->right != NULL){ 
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
 
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            if (balance_factor(root) == 2)
            {
                if (balance_factor(root->left) >= 0)
                    root = rotate_right(root);
                else{
                    root->left = rotate_left(root->left);
                    root = rotate_right(root);
                }
            }
        }
        else
            return (root->left);
    }
    root->ht = height(root);
    return (root);
}
struct node* search(struct node* root, int key){
    if (root == NULL)
        return NULL;
 	if(root->data == key)
        return root;
 	if(key > root->data)
        search(root->right, key);
    else
        search(root->left, key);
}
void preorder(struct node* root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int z, data;
    char c = 1;
    struct node* result = NULL;
 
    while (c==1){
        printf("------- AVL TREE --------");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Preorder");
        printf("\n5. EXIT");
 
        printf("\nEnter Your Choice: ");
        scanf("%d", &z);
 
        switch(z){
            case 1:printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
 
            case 2:printf("Enter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
 
            case 3:printf("Enter data: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result == NULL)
                    printf("Data not found!\n");
                else 
				printf("Data found\n");
                break;
            case 4:preorder(root);
                break;
 			case 5:exit(0);
 			default:printf("\nInvalid Choice\n");
        }
 		printf("Do you want to continue? ");
        scanf(" %d", &c);
    }
 	return 0;
}

