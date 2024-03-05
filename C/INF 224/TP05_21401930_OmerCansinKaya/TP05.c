#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TP05.h"

// New Node create function
 Node* newNode(int data) 
{
    Node* new = (Node*) malloc(sizeof(Node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	
	return new;
}

// Write a function that recursively adds a new Node to the tree.
 Node* insertNode( Node* n, int data) 
{
	if(n==NULL){
		return newNode(data);
	}
	if(data < n->data){
		n->left = insertNode(n->left, data);
	} else {
		n->right = insertNode(n->right, data);
	}
	return n;
}

// Write a function that finds the lowest value in the tree and returns it
int findMin( Node *tree) 
{
	return (tree->left == NULL ? tree->data : findMin(tree->left));
}

// Write a function that finds the max value in the tree and returns it
int findMax( Node *tree) 
{
	return (tree->right == NULL ? tree->data : findMax(tree->right));
}

// Write a function that returns the address of the highest value Node in the tree.
 Node* findMaxNode( Node *tree) 
{
	return (tree->right == NULL ? tree : findMaxNode(tree->right));
}

// Write a function that recursively deletes Nodes from the tree. If the Node to be deleted has 2 children, update the deleted Node as the maximum valued Node of the left sub-tree.
// (like the Delete function at https://www.cs.usfca.edu/~galles/visualization/BST.html)
 Node* deleteNode(struct node *tree, int data) 
{
	Node* temp = NULL;
    if (tree == NULL) {
        return tree;
    }

    if (data < tree->data) {
        tree->left = deleteNode(tree->left, data);
    } else if (data > tree->data) {
        tree->right = deleteNode(tree->right, data);
    } else {
        if (tree->left == NULL) {
            temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            temp = tree->left;
            free(tree);
            return temp;
        }
		// if tree->left != NULL && tree->right != NULL
        temp = findMaxNode(tree->left);
        tree->data = temp->data;
        tree->left = deleteNode(tree->left, temp->data);
    }

    return tree;
}

// Write a function that traverses the tree recursively using the "in-order" method and prints the values to the screen.
void printTreeInOrder( Node* tree) 
{
	if(tree!=NULL){
		printTreeInOrder(tree->left);
		printf("%d ", tree->data);
		printTreeInOrder(tree->right);
	}
}
	
	// ...

// Write a function that traverses the tree recursively using the "pre-order" method and prints the values to the screen.
void printTreePreOrder( Node* tree) 
{
	if(tree!=NULL){
		printf("%d ", tree->data);
		printTreePreOrder(tree->left);
		printTreePreOrder(tree->right);
	}
}

// Write a function that traverses the tree recursively using the "post-order" method and prints the values to the screen.	
void printTreePostOrder( Node* tree) 
{
	
	if(tree!=NULL){
		printTreePostOrder(tree->left);
		printTreePostOrder(tree->right);
		printf("%d ", tree->data);
	}	
}


// Level-order method
// Function that calculates the height of the tree recursively
int findHeight( Node *tree) 
{
	// ...
	int height = 1;
	
	if(tree==NULL) return 0;
	
	if(tree->left==NULL && tree->right==NULL) return height;
	else{
		if(tree->left==NULL) return 1+findHeight(tree->right);
		else if(tree->right==NULL) return 1+findHeight(tree->left);
		else{
			if((tree->right->right!=NULL) || (tree->right->left!=NULL)) return 1+findHeight(tree->right);
			if((tree->left->right!=NULL) || (tree->left->left!=NULL)) return 1+findHeight(tree->left);
		}
	}
	return height;
}

// Function that recursively suppresses Nodes in the same alignment (level)
void printLevel( Node *tree, int level)
{
	if(tree==NULL) return;
	
	if(level==0){
		printf("%d ", tree->data);
	}
	else{
		printLevel(tree->left, level-1);
		printLevel(tree->right, level-1);
	}
}


// Using the two functions above, write the function that traverses the tree with the "level-order" method and prints the values to the screen	
void printTreeLevelOrder( Node* tree)
{
	for(int j=0; j<findHeight(tree); j++) printLevel(tree, j);
}
