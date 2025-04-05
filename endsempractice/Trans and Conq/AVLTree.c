#include<stdio.h>
#include<stdlib.h>
#define max(a, b)(a > b ? a : b);
typedef struct node{
    int data;
    int height;
    struct node* left;
    struct node* right;
}node;
node* getnode(int data){
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->height = 0;
    newnode->right = newnode->left = NULL;
    return newnode;
}

int height(node* nod){
    if(nod == NULL) return -1;
    return max(height(nod->left), height(nod->right)) + 1;
}

int balfactor(node* nod){
    if(nod == NULL) return -1;
    return height(nod->left) - height(nod->right);
}
node* L(node* x){
    node* y = x->right;
    node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = height(x);
    y->height = height(y);
    return y;
}
node* R(node* x){
    node* y = x->left;
    node* z = y->right;

    y->right = x;
    x->left = z;

    x->height = height(x);
    y->height = height(y);
    return y;
}
node* balancetree(node* root){
    root->height = height(root);
    int balance = balfactor(root);
    if(balance > 1){
        if(balfactor(root->left) >= 0)
            return R(root);
        else{
            root->left = L(root->left);
            return R(root);
        }
    }
    if(balance < -1){
        if(balfactor(root->right) <= 0)
            return L(root);
        else{
            root->right = R(root->right);
            return L(root);
        }
    }
    return root;
}
node* insert(node* root, int data){
    if(root == NULL) return getnode(data);
    if(root->data > data)
        root->left = insert(root->left, data);
    else if(root->data < data)
        root->right = insert(root->right, data);
    else return root;
    return balancetree(root);
}
void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

node* predecessor(node* root, int key){
    if(root == NULL) return NULL;
    if(key <= root->data)   //key on left subtree, so its left child will be pred
        return predecessor(root->left, key);
    //key on right subtree, parent is a potential pred
    node* pred = predecessor(root->right, key);
    return pred != NULL ? pred : root;
}
node* successor(node* root, int key){
    if(root == NULL) return NULL;
    if(key >= root->data) 
        return successor(root->right, key);
    node* suc = successor(root->left, key);
    return suc != NULL ? suc : root;
}

node* delete(node* root, int data){
    if(root == NULL) return root;
    if(data < root->data)
        root->left = delete(root->left, data);
    else if(data > root->data)
        root->right = delete(root->right, data);
    else{
        //node with only one or no child
        if((root->left == NULL) || (root->right == NULL)){
            node* temp = root->left ? root->left : root->right;
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            free(temp);
        }
        else{
            //node with 2 children; get inorder successor
            node* temp = root->right;
            while(temp && temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    if(root == NULL) return root;
    return balancetree(root);
}
void main(){
    node* root = NULL;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 22);
    root = insert(root, 5);
    root = insert(root, 27);
    root = insert(root, 35);
    root = insert(root, 50);
    inorder(root);
    printf("\nPredeccessor of 40: %d\nSuccessor of 40: %d\n", predecessor(root, 40)->data, successor(root, 40)->data);
    root = delete(root, 5);
    inorder(root);
}
    