#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* newnode(int data){
    node* node = malloc(sizeof(node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

node* insert(node* root, int data){
    node* node = newnode(data);
    if(root == NULL)
        return node;
    if(root->left == NULL)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int count(node* root){
    if(root == NULL) return 0;
    return count(root->left) + count(root->right) + 1;
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void main(){
    node* root = NULL;
    int data;
    printf("Enter nodes(-1 to stop): ");
   while(1){
        scanf("%d", &data);
        if(data == -1) break;
        root = insert(root, data);
    }

    inorder(root);
    printf("\nNo. of nodes: %d",count(root));
}