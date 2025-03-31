#include<stdio.h>
#include<stdlib.h>
#define max(a, b) (a > b ? a : b)

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
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else
        printf("No duplicates allowed");
    return root;
}

int height(node* root){
    if(root == NULL) return -1;
    return max(height(root->left), height(root->right)) + 1;
}
void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void main(){
    node* root = NULL;
    int n, data;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    printf("Enter nodes: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }
    inorder(root);
    printf("\nHeight of tree: %d",height(root));
}