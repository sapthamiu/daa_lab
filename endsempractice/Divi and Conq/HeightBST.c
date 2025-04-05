#include<stdio.h>
#include<stdlib.h>
#define max(a, b)(a > b ? a : b)

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* getnode(int data){
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node* insert(node* root, int data){
    if(root == NULL) return getnode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}
int heightBST(node* root){
    if(root == NULL) return -1;
    return max(heightBST(root->left), heightBST(root->right)) + 1;
}

void main(){
    node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Height of the tree: %d", heightBST(root));
}