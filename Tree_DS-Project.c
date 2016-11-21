#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
#define false 0
// max height possible for a tree
#define MAX_HEIGHT 1000
// INFINITY
#define INFINITY (1<<20)
//Following are the codes for colored text
#define BLK   "\x1B[30m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m" //code to reset text to its default value
#define BOLD  "\x1B[1m" //code for bold text
//Following are the codes for colored background
#define BLKBG "\x1B[40m"
#define REDBG "\x1B[41m"
#define GRNBG "\x1B[42m"
#define YELBG "\x1B[43m"
#define BLUBG "\x1B[44m"
#define MAGBG "\x1B[45m"
#define CYNBG "\x1B[46m"
#define WHTBG "\x1B[47m"

typedef struct node
{
	struct node* left, *right;
	int data;
}tree;

typedef struct asciinode_struct
{
	struct asciinode_struct *left, *right;

	//length of the edge from this node to its children
	int edge_length;
	int height;
	int lablen;
	//-1=I am left, 0=I am root, 1=right
	int parent_dir;
	//max supported unit32 in dec, 10 digits max
	char label[11];
}asciinode;

// global variables
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
//adjust gap between left and right nodes
int gap = 3;
//used for printing next node in the same level,
//this is the x coordinate of the next char printed
int print_next;
tree *root = NULL,
*root_copy = NULL,
*mirror = NULL;

// Prototypes
//1st Application
tree *newNode();
tree *btreeToCList(tree *);
tree *concatenate(tree *, tree *);
void displayCList(tree *);

//2nd Application
void storeBSTNodes(tree *);
tree *buildtreeUtil(int, int);
tree *buildTree(tree *);
int n, nm = 0, start, end;
int nodes[50] = {[0 ... 49] = -1};

//3rd Application
int isSymmetric(tree *);
int isMirror(tree *, tree *);
tree *mirrorImage(tree *);

//4th Application
int isFulltree(tree *);

//5th Application
tree *buildTree_2(int [], int [], int);
tree *buildUtil(int [], int [], int, int, int *);
int search(int [], int, int, int);

//Functions for tree creation, deletion, traversal etc.
tree *insertBST(tree *, int);
tree *getNewNode(int);
void InorderTraversal(tree *);
void PreorderTraversal(tree *);
tree *make_empty(tree *);
tree *find_min(tree *);
tree *find_max(tree *);
tree *find(int, tree *);
tree *insert(int, tree *);
tree *delete(int, tree *);

int MIN (int, int);
int MAX (int, int);

void print_ascii_tree(tree *);
void print_level(asciinode *, int, int);
void compute_edge_lengths(asciinode *);
asciinode *build_ascii_tree_recursive(tree *);
asciinode *build_ascii_tree(tree *);
void free_ascii_tree(asciinode *);
void compute_lprofile(asciinode *, int, int);
void compute_rprofile(asciinode *, int, int);

int main(void)
{
	int op, value;
	printf("======================================================================    TREES    ======================================================================\n");
	printf("PRESS 1 FOR : INTRODUCTION OF TREES\nPRESS 2 FOR : APPLICATIONS OF TREES\nPRESS 0 TO  : EXIT\n");
	do {
		printf("\nENTER YOUR OPTION: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("------------------------------------------------------------------ INTRODUCTION TO TREES ------------------------------------------------------------------\n");
			printf("\nA tree is recursively defined as a set of one or more nodes where one node is designated as the root of the tree\n");
			printf("and all the remaining nodes can be partitioned into non-empty sets each of which is a sub-tree of the root.\n");
			printf("tree is a non-linear data structure (Unlike array, stack, queue etc.). There are many different types of trees such as\n");
			printf("General trees, Binary trees, Binary search trees, Multi-way search trees etc.\n");
			printf("Basic terminology of a tree:-\n");
			printf(BOLD "Root node " RESET "- The root node R is the topmost node in the tree. If R = NULL, then it means the tree is empty.\n");
			printf(BOLD "Sub-trees " RESET "- If the root node R is not NULL, then the trees (i.e the nodes under it) are called the sub-trees of R.\n");
			printf(BOLD "Leaf node " RESET "- A node that has no children is called the leaf node or the terminal node.\n");
			printf(BOLD "Ancestor node " RESET "- An ancestor of a node is any predecessor node on the path from root to that node. The root node does not have any ancestors.\n");
			printf(BOLD "Descendant node " RESET "- A descendant node is any successor node on any path from the node to a leaf node. Leaf nodes do not have any descendants.\n");
			printf(BOLD "Degree " RESET "- Degree of a node is equal to the number of children that a node has. The degree of a leaf node is zero.\n");
			printf(BOLD "In-degree " RESET "- In-degree of a node is the number of edges arriving at that node.\n");
			printf(BOLD "Out-degree " RESET "- Out-degree of a node is the number of edges leaving that node.\n");
			break;
			case 2:
			{
				printf("\n\n------------------------------------------------------------------ APPLICATIONS OF TREES ------------------------------------------------------------------\n\n");
				printf("The simplest application of a tree is a binary search tree.\n");
				printf("In a binary search tree, all the nodes in the left sub-tree have a value less than that of the root node.\n");
				printf("Correspondingly, all the nodes in the right sub-tree have a value either equal to or greater than the root node.\n");
				printf("The same rule is applicable to every sub-tree in the tree.\n\n");
				printf("PRESS 1 TO : CONVERT A BINARY TREE TO A CIRCULAR DOUBLY LINKED LIST\n");
				printf("PRESS 2 TO : CONVERT A NORMAL BST TO BALANCED BST\n");
				printf("PRESS 3 TO : FIND THE MIRROR IMAGE OF A BINARY TREE (ALSO CHECK WHETHER IT IS SYMMETRIC TREE (MIRROR IMAGE OF ITSELF))\n");
				printf("PRESS 4 TO : CHECK WHETHER A BINARY TREE IS A FULL BINARY TREE OR NOT\n");
				printf("PRESS 5 TO : CONSTRUCT A BINARY TREE FROM GIVEN POSTORDER AND INORDER TRAVERSALS\n");
				printf("PRESS 0 TO : EXIT\n");
				int op_loop1, value;
				do {
					printf("\nENTER YOUR OPTION: ");
					scanf("%d",&op_loop1);
					switch(op_loop1)
					{
						case 1:
						{
							root = NULL;
							printf("FOR EXAMPLE:\n");
							printf("\t\t 10\n");
							printf("\t\t/  \\ \n");
							printf("\t       12   15\n");
							printf("\t      / \\   /\n");
							printf("\t     25 30 36\n\n");
							printf("THE ABOVE TREE SHOULD BE IN-PLACE CONVERTED TO FOLLOWING\nCIRCULAR DOUBLY LINKED LIST\n\n");
							printf("\t  ------------------------\n");
							printf("\t  |\t\t         |\n");
							printf("\t--25==12==30==10==36==15--\n");
							printf("\t|\t\t       |");
							printf("\n	------------------------\n\n");
							printf("Enter data (-1 for no data): ");
							root = newNode();
							printf("THE BINARY TREE IS: \n\n");
							print_ascii_tree(root);
							tree *head = btreeToCList(root);
							displayCList(head);
							printf("ENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
							break;
						}
						case 2:
						{
							root = NULL;

							do {
								printf("Enter data (-1 to stop insertion): ");
								scanf("%d",&value);
								if(value!=-1) {
									root = insertBST(root, value);
								}
							}while(value!=-1);
							printf("THE UNBALANCED BST IS: \n\n");
							print_ascii_tree(root);
							root_copy = buildTree(root);
							printf("\nTHE BALANCED BST IS: \n");
							print_ascii_tree(root_copy);
							printf("\n\n");
							printf("ENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
							break;
						}
						case 3:
						{
							int result;
							root = NULL;
							printf("FOR EXAMPLE, THIS BINARY TREE IS SYMMETRIC:\n");
							printf("\t\t 1\n");
							printf("\t\t/ \\ \n");
							printf("\t       2   2\n");
							printf("\t      / \\ / \\\n");
							printf("\t     3  4 4  3\n\n");
							printf("Enter data (-1 for no data): ");
							root = newNode();
							printf("THE BINARY TREE IS: \n\n");
							print_ascii_tree(root);
							result = isSymmetric(root);
							if(result==true) {
								printf("\nTHE GIVEN BINARY TREE IS A SYMMETRIC TREE (MIRROR IMAGE OF ITSELF)\n\n");
							}
							else {
								mirror = mirrorImage(root);
								printf("\nTHE MIRROR IMAGE OF THE GIVEN BINARY TREE IS:\n\n");
								print_ascii_tree(mirror);
								printf("\n");
							}
							printf("ENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
							break;
						}
						case 4:
						{
							int result;
							root = NULL;
							printf("FOR EXAMPLE, THIS BINARY TREE IS FULL:\n");
							printf("\t\t 1\n");
							printf("\t\t/ \\ \n");
							printf("\t       2   3\n");
							printf("\t      / \\ \n");
							printf("\t     4   5\n\n");
							printf("WHEREAS, THIS BINARY TREE IS NOT FULL:\n");
							printf("\t\t 1\n");
							printf("\t\t/ \\ \n");
							printf("\t       2   3\n");
							printf("\t      /\n");
							printf("\t     4\n\n");
							printf("Enter data (-1 for no data): ");
							root = newNode();
							printf("THE BINARY TREE IS: \n\n");
							print_ascii_tree(root);
							result = isFulltree(root);
							if(result==true) {
								printf("\nTHE GIVEN BINARY TREE IS A FULL BINARY TREE\n\n");
							}
							else {
								printf("\nTHE GIVEN BINARY TREE IS NOT A FULL BINARY TREE\n\n");
							}
							printf("ENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
							break;
						}
						case 5:
						{
							int i, j;
							printf("ENTER THE NUMBER OF NODES FOR YOUR BINARY TREE: ");
							scanf("%d",&j);
							int in[j], post[j];
							printf("ENTER THE INORDER TRAVERSAL OF YOUR BINARY TREE:\n");
							for(i=0;i<j;i++)
							{
								scanf("%d",&in[i]);
							}
							printf("ENTER THE POSTORDER TRAVERSAL OF YOUR BINARY TREE:\n");
							for(i=0;i<j;i++)
							{
								scanf("%d",&post[i]);
							}
							int n = sizeof(in)/sizeof(in[0]);
							root = buildTree_2(in, post, n);
							printf("\nTHE BINARY TREE IS: \n\n");
							print_ascii_tree(root);
							printf("\n");
							printf("ENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
							break;
						}
						case 0:
						printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
						exit(0);
						default:
						printf("OPTION DOESN\'T EXIST TRY AGAIN");
					}
				}while(op_loop1!=0);
				break;
			}
			case 0:
			printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
			exit(0);
			default:
			printf("OPTION DOESN\'T EXIST TRY AGAIN");
		}
	}while(op!=0);
}

// Function converts a tree to a circular Linked List and then returns the head of the Linked List
tree *btreeToCList(tree *root)
{
	if(root == NULL)
	return NULL;
	// Recursively convert left and right subtrees
	tree *left = btreeToCList(root->left);
	tree *right = btreeToCList(root->right);
	/* Make a circular linked list of single node
	(or root). To do so, make the right and
	left pointers of this node point to itself */
	root->left = root->right = root;
	/* Step 1 (concatenate the left list with the list
	with single node, i.e., current node)
	Step 2 (concatenate the returned list with the
	right List) */
	return concatenate(concatenate(left, root), right);
}

tree *concatenate(tree *leftList, tree *rightList)
{
	// If either of the list is empty then return the other list
	if(leftList==NULL)
	return rightList;
	if(rightList==NULL)
	return leftList;
	// Store the last Node of left List
	tree *leftLast = leftList->left;
	// Store the last Node of right List
	tree *rightLast = rightList->left;
	// Connect the last node of Left List with the first Node of the right List
	leftLast->right = rightList;
	rightList->left = leftLast;
	// Left of first node points to the last node in the List
	leftList->left = rightLast;
	// Right of last node refers to the first node of the List
	rightLast->right = leftList;
	return leftList;
}

// Display Circular Link List
void displayCList(tree *head)
{
	printf("\nCircular Doubly Linked List is :\n");
	tree *itr = head;
	do
	{
		printf("%d  ",itr->data);
		itr = itr->right;
	}while(head!=itr);
	printf("\n\n");
}

// Create a new Node and return its address
// For 1st application only
tree *newNode()
{
	tree *temp;
	int x;
	scanf("%d",&x);
	if(x==-1)
	return NULL;
	temp = malloc(sizeof(struct node));
	temp->data = x;
	printf("Enter left child of \"%d\" (-1 for no data): ",x);
	temp->left = newNode();
	printf("Enter right child of \"%d\" (-1 for no data): ",x);
	temp->right = newNode();
	return temp;
}

// This functions converts an unbalanced BST to a sorted array
tree *buildTree(tree *root)
{
	// Store nodes of given BST in sorted order
	nm = 0;
	int i;
	storeBSTNodes(root);
	// Constucts BST from nodes[]
	root = NULL;
	return buildtreeUtil(0, nm-1);
}

void storeBSTNodes(tree *root)
{
	if(root!=NULL)
	{
		storeBSTNodes(root->left);
		nodes[nm++] = root->data;
		storeBSTNodes(root->right);
	}
}

// Recursive function to construct a balanced binary tree
tree* buildtreeUtil(int start,int end)
{
	int mid;
	tree * temp = malloc(sizeof(struct node));
	// base case
	if(start > end){
		return NULL;
	}

	// Get the middle element and make it temp root
	mid = (start + end) / 2;
	temp = getNewNode(nodes[mid]);
	// Using index in Inorder traversal, construct left and right subtress
	temp->left  = buildtreeUtil(start, mid - 1);
	temp->right = buildtreeUtil(mid + 1, end);
	return temp;
}

int isSymmetric(tree *root)
{
	// Check if binary tree is mirror of itself
	return isMirror(root, root);
}

int isMirror(tree *root1, tree *root2)
{
	// If both trees are emptu, then they are mirror images
	if (root1==NULL&&root2==NULL)
	return true;
	/* For two trees to be mirror images, the following three conditions must be true
	1 - Their root node's key must be same
	2 - left subtree of left tree and right subtree
	of right tree have to be mirror images
	3 - right subtree of left tree and left subtree
	of right tree have to be mirror images */
	if (root1&&root2&&root1->data == root2->data)
	return isMirror(root1->left, root2->right)&&isMirror(root1->right, root2->left);
	// If neither of above conditions is true then root1 and root2 are not mirror images
	return false;
}

tree *mirrorImage(tree *root)
{
	tree *m_root = NULL;
	if(root==NULL) {
		return NULL;
	}
	m_root = getNewNode(root->data);
	m_root->left = mirrorImage(root->right);
	m_root->right = mirrorImage(root->left);
	return m_root;
}

// Utility function to insert a new node into BST
tree *insertBST(tree *root,int value)
{
	tree *ptr,*node_ptr,*parent_ptr;
	ptr = malloc(sizeof(struct node));
	ptr->data = value;
	ptr->left = NULL;
	ptr->right = NULL;
	if(root==NULL)
	{
		root = ptr;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		parent_ptr = NULL;
		node_ptr = root;
		while(node_ptr!=NULL)
		{
			parent_ptr = node_ptr;
			if(value<node_ptr->data)
			node_ptr = node_ptr->left;
			else
			node_ptr = node_ptr->right;
		}
		if(value<parent_ptr->data)
		parent_ptr->left = ptr;
		else
		parent_ptr->right = ptr;
	}
	return root;
}

tree *getNewNode(int data)
{
	tree *new_node;
	new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

int isFulltree(tree *root)
{
	// If empty tree
	if(root==NULL) {
		return true;
	}
	// If leaf node
	if(root->left==NULL&&root->right==NULL) {
		return true;
	}
	// If both left and right are not NULL, and left & right subtrees are full
	if((root->left)&&(root->right)) {
		return (isFulltree(root->left)&&isFulltree(root->right));
	}
	// We reach here when none of the above if conditions work
	return false;
}

void InorderTraversal(tree *mirror)
{
	if(mirror==NULL)
	return;
	else
	{
		InorderTraversal(mirror->left);
		printf("%d ",mirror->data);
		InorderTraversal(mirror->right);
	}
}

void PreorderTraversal(tree *root)
{
	if(root==NULL) {
		return;
	}
	else
	{
		printf("%d ",root->data);
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

// This function mainly initializes index of and calls buildUtil()
tree *buildTree_2(int in[], int post[], int n)
{
	int pIndex = n-1;
	return buildUtil(in, post, 0, n-1, &pIndex);
}

/* Recursive function to construct binary of size n
from  Inorder traversal in[] and Preorder traversal
post[].  Initial values of inStrt and inEnd should
be 0 and n -1.  The function doesn't do any error
checking for cases where inorder and postorder
do not form a tree */
tree *buildUtil(int in[], int post[], int inStart, int inEnd, int *pIndex)
{
	// Base case
	if(inStart > inEnd) {
		return NULL;
	}
	// Pick current node from Preorder traversal using postIndex and decrement postIndex
	tree *node = getNewNode(post[*pIndex]);
	(*pIndex)--;
	// If this node has no children then return
	if(inStart==inEnd) {
		return node;
	}
	// Else find the index of this node in Inorder traversal
	int iIndex = search(in, inStart, inEnd, node->data);
	// Using index in Inorder traversal, construct left and right subtress
	node->right= buildUtil(in, post, iIndex+1, inEnd, pIndex);
	node->left = buildUtil(in, post, inStart, iIndex-1, pIndex);
	return node;
}

/* Function to find index of value in arr[start...end]
	 The function assumes that value is postsent in in[] */
int search(int arr[], int start, int end, int value)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(arr[i]==value) {
			break;
		}
	}
	return i;
}

// tree helper functions
tree *make_empty(tree *t)
{
	if (t != NULL)
	{
		make_empty(t->left);
		make_empty(t->right);
		free(t);
	}

	return NULL;
}

tree *find_min(tree *t)
{
	if (t == NULL)
	{
		return NULL;
	}
	else if (t->left == NULL)
	{
		return t;
	}
	else
	{
		return find_min(t->left);
	}
}

tree *find_max(tree *t)
{
	if (t == NULL)
	{
		return NULL;
	}
	else if (t->right == NULL)
	{
		return t;
	}
	else
	{
		return find_max(t->right);
	}
}

tree *find(int elem, tree *t)
{
	if (t == NULL)
	{
		return NULL;
	}

	if (elem < t->data)
	{
		return find(elem, t->left);
	}
	else if (elem > t->data)
	{
		return find(elem, t->right);
	}
	else
	{
		return t;
	}
}

/* Insert i into the tree t, duplicate will be discarded
   Return a pointer to the resulting tree. */
tree * insert(int value, tree * t)
{
	tree * new_node;

	if (t == NULL)
	{
		new_node = (tree *) malloc (sizeof (tree));
		if (new_node == NULL)
		{
			return t;
		}

		new_node->data = value;

		new_node->left = new_node->right = NULL;
		return new_node;
	}

	if (value < t->data)
	{
		t->left = insert(value, t->left);
	}
	else if (value > t->data)
	{
		t->right = insert(value, t->right);
	}
	else
	{
		// Duplicate, Ignore it
		return t;
	}
	return t;
}

tree * delete(int value, tree * t)
{
	// Deletes node from the tree
	// Return a pointer to the resulting tree
	tree * x;
	tree *tmp_cell;

	if (t==NULL) return NULL;

	if (value < t->data)
	{
		t->left = delete(value, t->left);
	}
	else if (value > t->data)
	{
		t->right = delete(value, t->right);
	}
	else if (t->left && t->right)
	{
		tmp_cell = find_min(t->right);
		t->data = tmp_cell->data;
		t->right = delete(t->data, t->right);
	}
	else
	{
		tmp_cell = t;
		if (t->left == NULL)
		t = t->right;
		else if (t->right == NULL)
		t = t->left;
		free(tmp_cell);
	}

	return t;
}

int MIN (int X, int Y)
{
	return ((X) < (Y)) ? (X) : (Y);
}

int MAX (int X, int Y)
{
	return ((X) > (Y)) ? (X) : (Y);
}

//Prints ascii tree for given tree structure
void print_ascii_tree(tree * t)
{
	asciinode *proot;
	int xmin, i;
	if (t == NULL) return;
	proot = build_ascii_tree(t);
	compute_edge_lengths(proot);
	for (i=0; i<proot->height && i < MAX_HEIGHT; i++)
	{
		lprofile[i] = INFINITY;
	}
	compute_lprofile(proot, 0, 0);
	xmin = 0;
	for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
	{
		xmin = MIN(xmin, lprofile[i]);
	}
	for (i = 0; i < proot->height; i++)
	{
		print_next = 0;
		print_level(proot, -xmin, i);
		printf("\n");
	}
	if (proot->height >= MAX_HEIGHT)
	{
		printf("(This tree is taller than %d, and may be drawn incorrectly.)\n",
		MAX_HEIGHT);
	}
	free_ascii_tree(proot);
}

// Print tree
// This function prints the given level of the given tree, assuming
// that the node has the given x cordinate.
void print_level(asciinode *node, int x, int level)
{
	int i, isleft;
	if (node == NULL) return;
	isleft = (node->parent_dir == -1);
	if (level == 0)
	{
		for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++)
		{
			printf(" ");
		}
		print_next += i;
		printf("%s", node->label);
		print_next += node->lablen;
	}
	else if (node->edge_length >= level)
	{
		if (node->left != NULL)
		{
			for (i=0; i<(x-print_next-(level)); i++)
			{
				printf(" ");
			}
			print_next += i;
			printf("/");
			print_next++;
		}
		if (node->right != NULL)
		{
			for (i=0; i<(x-print_next+(level)); i++)
			{
				printf(" ");
			}
			print_next += i;
			printf("\\");
			print_next++;
		}
	}
	else
	{
		print_level(node->left, x-node->edge_length-1, level-node->edge_length-1);
		print_level(node->right, x+node->edge_length+1, level-node->edge_length-1);
	}
}

//This function fills in the edge_length and height fields of the specified tree
void compute_edge_lengths(asciinode *node) {
	int h, hmin, i, delta;
	if (node == NULL) return;
	compute_edge_lengths(node->left);
	compute_edge_lengths(node->right);

	// First fill in the edge_length of node
	if (node->right == NULL && node->left == NULL)
	{
		node->edge_length = 0;
	}
	else
	{
		if (node->left != NULL)
		{
			for (i=0; i<node->left->height && i < MAX_HEIGHT; i++)
			{
				rprofile[i] = -INFINITY;
			}
			compute_rprofile(node->left, 0, 0);
			hmin = node->left->height;
		}
		else
		{
			hmin = 0;
		}
		if (node->right != NULL)
		{
			for (i=0; i<node->right->height && i < MAX_HEIGHT; i++)
			{
				lprofile[i] = INFINITY;
			}
			compute_lprofile(node->right, 0, 0);
			hmin = MIN(node->right->height, hmin);
		}
		else
		{
			hmin = 0;
		}
		delta = 4;
		for (i=0; i<hmin; i++)
		{
			delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
		}

		// If the node has two children of height 1, then we allow the two leaves to be within 1, instead of 2
		if (((node->left != NULL && node->left->height == 1) ||
		(node->right != NULL && node->right->height == 1))&&delta>4)
		{
			delta--;
		}

		node->edge_length = ((delta+1)/2) - 1;
	}

	// Now fill in the height of node
	h = 1;
	if (node->left != NULL)
	{
		h = MAX(node->left->height + node->edge_length + 1, h);
	}
	if (node->right != NULL)
	{
		h = MAX(node->right->height + node->edge_length + 1, h);
	}
	node->height = h;
}

asciinode * build_ascii_tree_recursive(tree * t)
{
	asciinode * node;

	if (t == NULL) return NULL;

	node = malloc(sizeof(asciinode));
	node->left = build_ascii_tree_recursive(t->left);
	node->right = build_ascii_tree_recursive(t->right);

	if (node->left != NULL)
	{
		node->left->parent_dir = -1;
	}

	if (node->right != NULL)
	{
		node->right->parent_dir = 1;
	}

	sprintf(node->label, "%d", t->data);
	node->lablen = strlen(node->label);

	return node;
}

// Copy the tree into the ascii node structre
asciinode * build_ascii_tree(tree * t)
{
	asciinode *node;
	if (t == NULL) return NULL;
	node = build_ascii_tree_recursive(t);
	node->parent_dir = 0;
	return node;
}

// Free all the nodes of the given tree
void free_ascii_tree(asciinode *node)
{
	if (node == NULL) return;
	free_ascii_tree(node->left);
	free_ascii_tree(node->right);
	free(node);
}

/* The following function fills in the lprofile array for the given tree.
   It assumes that the center of the label of the root of this tree
   is located at a position (x,y).  It assumes that the edge_length
   fields have been computed for this tree. */
void compute_lprofile(asciinode *node, int x, int y)
{
	int i, isleft;
	if (node == NULL) return;
	isleft = (node->parent_dir == -1);
	lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
	if (node->left != NULL)
	{
		for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
		{
			lprofile[y+i] = MIN(lprofile[y+i], x-i);
		}
	}
	compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
	compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_rprofile(asciinode *node, int x, int y)
{
	int i, notleft;
	if (node == NULL) return;
	notleft = (node->parent_dir != -1);
	rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
	if (node->right != NULL)
	{
		for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
		{
			rprofile[y+i] = MAX(rprofile[y+i], x+i);
		}
	}
	compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
	compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}
