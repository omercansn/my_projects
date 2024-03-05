typedef struct node
{
	int data;
    struct node* left;
    struct node* right;
} Node;


 Node* newNode(int data) ;
 Node* insertNode( Node* n, int data) ;
int findMin( Node *tree) ;
int findMax( Node *tree) ;
 Node* findMaxNode( Node *tree) ;
 Node* deleteNode( Node *tree, int data) ;
void printTreeInOrder( Node* tree) ;
void printTreePreOrder( Node* tree) ;
void printTreePostOrder( Node* tree) ;
int findHeight( Node *tree) ;
void printLevel( Node *tree, int level);
void printTreeLevelOrder( Node* tree) ;
