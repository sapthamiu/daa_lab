#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode; 
}

Node* insert(Node* root, int data){
    if(root == NULL) return createNode(data);
    if(root->left == NULL) 
        root->left = createNode(data);
    else if(root->right == NULL)
        root->right = createNode(data);
    else root->left = insert(root->left, data);
    return root;
}

Node* findCCA(Node* root, int n1, int n2, int* found1, int* found2){
    if(root == NULL) return NULL;
    if(root->data == n1){
        *found1 = 1;
        return root;
    }
    if(root->data == n2){
        *found2 = 1;
        return root;
    }
    Node* leftA = findCCA(root->left, n1, n2, found1, found2);
    Node* rightA = findCCA(root->right, n1, n2, found1, found2);
    if(leftA && rightA) return root;
    return (leftA != NULL)? leftA : rightA;
}

void main(){
    Node* root = NULL;
    int n, data, n1, n2;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    printf("Enter the node values: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Enter two nodes to find their CCA: ");
    scanf("%d %d", &n1, &n2);
    int found1 = 0, found2 = 0;
    Node* cca = findCCA(root, n1, n2, &found1, &found2);
    if(found1 && found2)
        printf("CCA of %d and %d is: %d\n", n1, n2, cca->data);
    else printf("No CCA found\n");
}