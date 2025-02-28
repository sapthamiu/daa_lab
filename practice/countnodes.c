#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* newnode(int data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data){
    if(root == NULL) return newnode(data);
    if(root->left == NULL) 
        root->left = newnode(data);
    else if(root->right == NULL)
        root->right = newnode(data);
    else root->left = insert(root->left, data);
    return root;
}

int countnodes(Node* root){
    if(root == NULL) return 0;
    return countnodes(root->left) + countnodes(root->right) + 1;
}

void main(){
    int data;
    Node* root = NULL;
    while(1){
        printf("Enter node value(-1 to exist): ");
        scanf("%d", &data);
        if(data == -1) break;
        root = insert(root, data);
    }
    printf("No. of nodes: %d", countnodes(root));
}