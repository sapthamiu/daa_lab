#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* createnode(int data){
	node* newnode = malloc(sizeof(node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

node* searchIns(node* root, int key){
	if(root == NULL){
		printf("%d not found. Inserting into the tree.\n", key);
		return createnode(key);
	}
	if(root->data == key) 
		printf("%d found in the tree.\n",key);
	else if(key < root->data)
		root->left = searchIns(root->left, key);
	else root->right = searchIns(root->right, key);

	return root;
}

void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(node* root){
	if(root != NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
void main(){

	node* root = NULL;
	int ch, key;

	printf("Menu: \n1. Search/Insert\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder traversal\n5. Exit\n");
	while(1){
		printf("\nYour choice: ");
		scanf("%d", &ch);
		switch(ch){
		case 1: printf("Enter key to insert / search: ");
				scanf("%d", &key);
				root = searchIns(root, key);
				break;
		case 2: printf("Inorder: ");
				inorder(root);
				break;
		case 3: printf("Preorder: ");
				preorder(root);
				break;
		case 4: printf("Postorder: ");
				postorder(root);
				break;
		case 5: exit(0);
		default: printf("Enter valid input.");
		}
	}
}
