#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TP05.h"

// New node create function
struct node* newNode(int data) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to recursively add a new node to the tree
struct node* insertNode(struct node* n, int data) 
{
    if (n == NULL) {
        return newNode(data);
    }

    if (data < n->data) {
        n->left = insertNode(n->left, data);
    } else if (data >= n->data) {
        n->right = insertNode(n->right, data);
    }

    return n;
}

// Function to find the minimum value in the tree
int findMin(struct node *tree) 
{
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree->data;
}

// Function to find the maximum value in the tree
int findMax(struct node *tree) 
{
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree->data;
}

// Function to return the address of the node with the maximum value in the tree
struct node* findMaxNode(struct node *tree) 
{
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

// Function to delete a node from the tree
struct node* deleteNode(struct node *tree, int data) 
{
    if (tree == NULL) {
        return tree;
    }

    if (data < tree->data) {
        tree->left = deleteNode(tree->left, data);
    } else if (data > tree->data) {
        tree->right = deleteNode(tree->right, data);
    } else {
        if (tree->left == NULL) {
            struct node* temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct node* temp = tree->left;
            free(tree);
            return temp;
        }

        struct node* temp = findMaxNode(tree->left);
        tree->data = temp->data;
        tree->left = deleteNode(tree->left, temp->data);
    }

    return tree;
}

// Function to traverse the tree in-order and print the values to the screen
void printTreeInOrder(struct node* tree) 
{
    if (tree != NULL) {
        printTreeInOrder(tree->left);
        printf("%d ", tree->data);
        printTreeInOrder(tree->right);
    }
}

// Function to traverse the tree pre-order and print the values to the screen
void printTreePreOrder(struct node* tree) 
{
    if (tree != NULL) {
        printf("%d ", tree->data);
        printTreePreOrder(tree->left);
        printTreePreOrder(tree->right);
    }
}

// Function to traverse the tree post-order and print the values to the screen
void printTreePostOrder(struct node* tree) 
{
    if (tree != NULL) {
        printTreePostOrder(tree->left);
        printTreePostOrder(tree->right);
        printf("%d ", tree->data);
    }
}

// Function to calculate the height of the tree recursively
int findHeight(struct node *tree) 
{
    if (tree == NULL) {
        return -1;
    }

    int leftHeight = findHeight(tree->left);
    int rightHeight = findHeight(tree->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to print nodes at a specific level
void printLevel(struct node *tree, int level) 
{
    if (tree == NULL) {
        return;
    }

    if (level == 0) {
        printf("%d ", tree->data);
    } else {
        printLevel(tree->left, level - 1);
        printLevel(tree->right, level - 1);
    }
}

// Function to traverse the tree level-order and print the values to the screen
void printTreeLevelOrder(struct node* tree) 
{
    int height = findHeight(tree);
    for (int i = 0; i <= height; i++) {
        printLevel(tree, i);
    }
}

int main() 
{
    struct node* root = NULL;

    // Add nodes to the tree
    root = insertNode(root, 78);
    root = insertNode(root, 85);
    root = insertNode(root, 56);
    root = insertNode(root, 65);
    root = insertNode(root, 13);
    root = insertNode(root, 79);
    root = insertNode(root, 85);
    root = insertNode(root, 86);
    root = insertNode(root, 43);
    root = insertNode(root, 97);

    // Print the min and max values
    printf("Minimum: %d\n", findMin(root));
    printf("Maximum: %d\n", findMax(root));

    // Delete nodes with values 85 and 56
    root = deleteNode(root, 85);
    root = deleteNode(root, 56);

    // Print the values using different traversal methods
    printf("In-order   : ");
    printTreeInOrder(root);
    printf("\n");

    printf("Pre-order  : ");
    printTreePreOrder(root);
    printf("\n");

    printf("Post-order : ");
    printTreePostOrder(root);
    printf("\n");

    printf("Level-order: ");
    printTreeLevelOrder(root);
    printf("\n");

    return 0;
}