#include<stdio.h>
#include<stdlib.h>
#define max(a, b)(a > b ? a : b)
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;

node* newnode(int data){
    node* node1 = malloc(sizeof(node));
    node1->data = data;
    node1->left = node1->right = NULL;
    node1->height = 1;
    return node1;
}
int height(node* node1){
    return node1 == NULL ? 0 : node1->height;
}
int balfactor(node* node1){
    return node1 == NULL ? 0 : height(node1->left) - height(node1->right);
}
node* L(node* x){
    node* y = x->right;
    node* z = y->left;
    y->left = x;
    x->right = z;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
node* R(node* x){
    node* y = x->left;
    node* z = y->right;
    y->right = x;
    x->left = z;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
node* successor(node* root, int key){
    node* succ = NULL;
    while(root){
        if(key >= root->data)
            root = root->right;
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}
node* predecessor(node* root, int key){
    if(root == NULL) return NULL;
    if(key <= root->data)
        return predecessor(root->left, key);
    node* pred = predecessor(root->right, key);
    return pred != NULL ? pred : root;
}
node* baltree(node* node1){
    node1->height = max(height(node1->left), height(node1->right)) + 1;
    int bf = balfactor(node1);
    if(bf > 1){     //left skewed, needs R or LR
        if(balfactor(node1->left) >= 0)  //R
            return R(node1);
        else{                           //LR
            node1->left = L(node1->left);
            return R(node1);
        }
    }
    else if(bf < -1){//right skewed, needs L or RL
        if(balfactor(node1->right) <= 0) //L
            return L(node1);
        else{
            node1->right = R(node1->right);
            return L(node1);
        }
    }
    return node1;
}
void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
node* insert(node* root, int data){
    if(root == NULL)
        return newnode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else {
        printf("Duplicates not allowed");
        return root;
    }
    return baltree(root);
}

void main(){
    node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    inorder(root);
    node* pred = predecessor(root, 80);
    node* succ = successor(root, 80);
    printf("\npredecessor: %d", pred->data);
    printf("\nsuccessor: %d", succ->data);

}