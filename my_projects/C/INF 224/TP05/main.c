#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TP05.h"
#define MAX_SIZE 9
int main(int argc, char *argv[]) 
{
	// printf("Where is my BST?!?!\n");p
	// for copy-paste: 78 85 56 65 13 79 85 86 43
	
	Node* root = NULL;
	if(argc<2){
		printf("Where is my BST?!?!\n");
		return -1;
	}
	
	int ELEMENT=0;
	// Define and create a BST using the parameters you get from the command line
	for(; ELEMENT<MAX_SIZE; ELEMENT++){
		root = insertNode(root, atoi(argv[ELEMENT+1]));
	}
	// Add a new Node with value 97 to your tree
	// ...
	root = insertNode(root, 97);
	
	// Print the min and max values of the Nodes in the tree to the screen
	printf("Minimum: %d\n", findMin(root));
	printf("Maximum: %d\n", findMax(root));
	
	// Delete Nodes with values 85 and 56 respectively
	// ...
	root = deleteNode(root,85);
	root = deleteNode(root,56);
	// Print the values of the Nodes properly on the screen by traversing the tree using in-order, pre-order, post-order and level-order methods.
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
