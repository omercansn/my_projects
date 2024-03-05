// Splay tree node structure
typedef struct node 
{
	int data;
	struct node *left;
	struct node *right;
} Node;


Node *createNode(int data) ;
int isEmpty(Node *root);
Node *rightRotate(Node *x) ;
Node *leftRotate(Node *x) ;
Node *splay(Node *root, int key) ;
Node *insertNode(Node *root, int data) ;
Node *search(Node *root, int key) ;
void printTreePreOrder(Node *root) ;
