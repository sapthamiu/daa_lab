#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/**
 * Function to find the Closest Common Ancestor (CCA) of two nodes
 */
struct Node* findCCA(struct Node* root, int n1, int n2) {
    // Base case: If root is NULL or matches one of the nodes
    if (root == NULL || root->data == n1 || root->data == n2) {
        return root;
    }

    // Search in the left and right subtrees
    struct Node* left = findCCA(root->left, n1, n2);
    struct Node* right = findCCA(root->right, n1, n2);

    // If both left and right are not NULL, this is the common ancestor
    if (left != NULL && right != NULL) {
        return root;
    }

    // Return the non-NULL child (either left or right)
    return (left != NULL) ? left : right;
}

int main() {
    // Example binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int n1 = 4, n2 = 5;
    struct Node* ancestor = findCCA(root, n1, n2);

    if (ancestor != NULL) {
        printf("Closest Common Ancestor of %d and %d is: %d\n", n1, n2, ancestor->data);
    } else {
        printf("No common ancestor found.\n");
    }

    return 0;
}