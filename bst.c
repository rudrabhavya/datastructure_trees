#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *smallest_node(struct node *);
struct node *largest_node(struct node *);
struct node *create_node(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("Memory can't be allocated");
        return NULL;
    }
 	new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
 	return new_node;
}
void insert(int data){	
	struct node *new_node = create_node(data);
 	if (new_node != NULL){
        if (root == NULL){
            root = new_node;
            printf("* node having data %d was inserted\n", data);
            return;
        }
 		struct node *temp = root;
        struct node *prev = NULL;
        while (temp != NULL){
            prev = temp;
            if (data > temp->data){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        if (data > prev->data){
            prev->right = new_node;
        }
        else{
            prev->left = new_node;
        }
 
        printf("* node having data %d was inserted\n", data);
    }

struct node *delete (struct node *root, int key){
    if (root == NULL){
        return root;
    }
    if (key < root->data){
        root->left = delete (root->left, key);
    }
    else if (key > root->data){
        root->right = delete (root->right, key);
    }
    else{
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}
int search(int key){
    struct node *temp = root;
 	while (temp != NULL){
        if (key == temp->data){
            return 1;
        }
        else if (key > temp->data){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return 0;
}
struct node *smallest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->left != NULL)
   {
        curr = curr->left;
    }
    return curr;
}
struct node *largest_node(struct node *root){
    struct node *curr = root;
    while (curr != NULL && curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}
void inorder(struct node *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",  root->data);
    inorder(root->right);
}
void preorder(struct node *root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int get_data(){
    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    return data;
}
 
int main(){
    int z;
    int c=1;
    int data;
    struct node* result = NULL;
 
    while (c==1){
        printf("MENU:\n1. Insert\n2. Delete\n3. Search\n4. Maximum Node Data\n5. Minimum Node data\n-- Traversals --\n6. Inorder\n7. Post Order\n8. Pre Oder\n9. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &z);
 
        switch(z)
        {
            case 1:data = get_data();
                insert(data);
                break;
			case 2:data = get_data();
                root = delete(root, data);
                break;
 			case 3:data = get_data();
                if (search(data) == 1){
                    printf("Data was found!\n");
                }
                else{
                    printf("Data does not found!\n");
                }
                break;
			case 4:result = largest_node(root);
                if (result != NULL){
                    printf("Largest Data: %d\n", result->data);
                }
                break;
 			case 5:result = smallest_node(root);
                if (result != NULL){
                    printf("Smallest Data: %d\n", result->data);
                }
                break;
			case 6:inorder(root);
			printf("\n");
                break;
 			case 7:postorder(root);
 			printf("\n");
                break;
 			case 8:preorder(root);
 			printf("\n");
                break;
 			case 9:exit(0);
			default:printf("Invalid Choice");
                break;
        }
 		printf("Do you want to continue? ");
        fflush(stdin);
        scanf(" %d", &c);
    }
 
    return 0;
}

