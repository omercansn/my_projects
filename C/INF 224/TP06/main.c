#include <stdio.h>
#include <stdlib.h>
#include "TP06.h"
#define EXIT -1
#define MAX_SIZE 6


int main(int argc, char *argv[]) 
{
	// Values to be added to the Splay tree are: 15 10 17 7 13 16
	Node *root = NULL;
	// ...
	if(argc<2){
		printf("Where is my splay?!?!");
		return EXIT; 
	}
	for(int u=0; u<MAX_SIZE; u++){
		if(argv[u+1]!=NULL) {
			root = insertNode(root, atoi(argv[u+1]));
			printTreePreOrder(root);
			printf("\n");
		}
		else break;
	}
	// Search for a key in the tree and splay it to the root

	int key_to_search = 13;  // Replace this with the key you want to search for
	root = search(root, key_to_search);
	printf("Preorder traversal after searching for %d:\n", key_to_search);
	printTreePreOrder(root);
	printf("\n");
	free(root);

	return 0; 
	
}
