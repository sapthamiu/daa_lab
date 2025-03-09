#include<stdio.h>
#include<stdlib.h>
#define max(x,y)(x>y ? x : y)
typedef struct node{
    int data, height;
    struct node* left, *right;
}Node;
Node* newnode(int data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
int height(Node* node){
    return node==NULL ? 0 : node->height;
}
int balfactor(Node* node){
    return node==NULL ? 0 : height(node->left) - height(node->right);
}

Node* Right(Node* x){
    Node* y = x->left;
    Node* z = y->right;
    y->right = x;
    x->left = z;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
Node* Left(Node* x){
    Node* y = x->right;
    Node* z = y->left;
    y->left = x;
    x->right = z;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
Node* balanceTree(Node* node){
    node->height = max(height(node->left), height(node->right))+1;
    int balance = balfactor(node);

    if(balance > 1){                            //needs R or LR
        if(balfactor(node->left) >= 0)          //left skewed, needs R
            return Right(node);
        else{                                   //needs LR
            node->left = Left(node->left);
            return Right(node);
        }
    }
    if(balance < -1){                           //needs L or RL
        if(balfactor(node->right) <= 0)         //right skewed, needs L
            return Left(node);
        else{
            node->right = Right(node->right);
            return Left(node);
        }
    }
    return node;
}
Node* insert(Node* root, int data){
    if(root == NULL) return newnode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else return root;
    return balanceTree(root);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

Node* Predecessor(Node* root, int key){
    if(root == NULL) return NULL;
    if(key <= root->data)
        return Predecessor(root->left, key);
    Node* pred =  Predecessor(root->right, key);
    return pred!= NULL ? pred : root;
}
Node* Successor(Node* root, int key){
    if(root == NULL) return NULL;
    if(key >= root->data)
        return Successor(root->right, key);
    Node* succ = Successor(root->left, key);
    return succ!=NULL ? succ : root;
}
void main(){
    Node* root = NULL;
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\nEnter key: ");
    scanf("%d", &data);
    Node* pred = Predecessor(root, data);
    Node* succ = Successor(root, data);
    printf("\nPredecessor: %d \nSuccessor: %d", pred->data, succ->data);
}