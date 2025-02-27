#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left, * right;
}Node;

Node* newnode(int data){
    Node* node = malloc(sizeof(Node));
    node ->data = data;
    node ->left = node->right = NULL;
    return node;
}
Node* insert(Node* root, int data){
    if(root == NULL) return newnode(data);
    if(root->left == NULL) root->left = newnode(data);
    else if(root ->right == NULL) root->right = newnode(data);
    else root->left = insert(root->left, data);
    return root;
}
int countnodes(Node* root, int *opcount){
    if(root == NULL)
        return 0;
    (*opcount)++;
    return countnodes(root->left, opcount) + countnodes(root->right, opcount) + 1;
}

void main(){
    Node* root = NULL;
    int data, opcount = 0;
    printf("Enter node values(-1 to stop): ");
    while(1){
        scanf("%d", &data);
        if(data == -1) break;
        root = insert(root, data);
    }
    int n = countnodes(root, &opcount);
    printf("Total nodes in the tree: %d\nOpcount: %d", n, opcount);
}