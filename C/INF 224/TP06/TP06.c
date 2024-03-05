#include <stdio.h>
#include <stdlib.h>
#include "TP06.h"


Node *createNode(int data) 
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isEmpty(Node *root){
    return root==NULL ? 1 : 0;
}


Node *rightRotate(Node *x) 
{
    Node* temp = NULL;
    temp = x->left;
    x->left = temp->right;
    temp->right = x;
    return temp;
}

Node *leftRotate(Node *x) 
{
    Node* temp = NULL;
    temp = x->right;
    x->right = temp->left;
    temp->left = x;
    return temp;
}

// This function brings the key at the root if the key is present in the tree.
// If the key is not present, then it brings the last accessed item at the root.
// This function modifies the tree and returns the new root.
Node *splay(Node *root, int key) {
    // Base cases: root is NULL or key is present at root
    if (isEmpty(root) || root->data == key) {
        return root;
    }
    // Key lies in the left subtree
    if (key < root->data) {
        // Key is not in the tree, we are done
        if (isEmpty(root->left)) {
            return root;
        }
        // Zig-Zig (Left Left)
        if (key < root->left->data) {
            // First recursively bring the key as the root of left-left
            root->left->left = splay(root->left->left, key);
            // Do the first rotation for root, the second rotation is done after else
            root = rightRotate(root);
        } 
        // Zig-Zag (Left Right)
        else if (key > root->left->data) {
             // First recursively bring the key as the root of left-right
            root->left->right = splay(root->left->right, key);
            // Do the first rotation for root->left
            if (!isEmpty(root->left->right)) {
                root->left = leftRotate(root->left);
            }
        }
        // Do the second rotation for root
        return (isEmpty(root->left)) ? root : rightRotate(root);
    } 
    // Key lies in the right subtree
    else {
        // Key is not in the tree, we are done
        if (isEmpty(root->right)) {
            return root;
        }
        // Zag-Zig (Right Left)
        if (key < root->right->data) {
            // Bring the key as the root of right-right
            root->right->left = splay(root->right->left, key);
            // Do the first rotation
            if (!isEmpty(root->right->left)) {
                root->right = rightRotate(root->right);
            }
        }

        // Zag-Zag (Right Right)
        else  if (key > root->right->data) {
            // Bring the key as the root of right-left
            root->right->right = splay(root->right->right, key);
            // Do the first rotation for root->right
            root = leftRotate(root);
        } 
        // Do the second rotation for root
        return (isEmpty(root->right)) ? root : leftRotate(root);
    }
}



Node *insertNode(Node *root, int data) 
{
    if(isEmpty(root)) return createNode(data);
    root = splay(root, data);
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return splay(root, data); 
}

// The search function for the Splay tree. Note that this function
// returns the new root of the Splay Tree. If the key is present in the tree,
// then it is moved to the root.
Node *search(Node *root, int key) 
{
    return splay(root, key);
}

void printTreePreOrder(Node *root) 
{
    if(!isEmpty(root)){
        printf("%d ", root->data);
        printTreePreOrder(root->left); 
        printTreePreOrder(root->right); 
    }
}
