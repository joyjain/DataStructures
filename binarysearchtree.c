#include<stdio.h>
#include<malloc.h>
#include<process.h>
typedef struct node
{
	struct node *left, *right;
	int data;
}tree;

tree *root = NULL;
tree *insert(tree *, int);
tree *delete(tree *, int);
tree *find_min(tree *);
void PreorderTraversal(tree *);
void main()
{
	int value,option;
	printf("\"1\" To insert an element\n\"2\" To display tree in preorder\n\"3\" To delete an element\n\"4\" To exit\n");
	do
	{
		printf("Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the data to insert in your tree: ");
				scanf("%d",&value);
				root = insert(root,value);
				break;
			case 2:
				printf("The elements of the tree are:\n");
				PreorderTraversal(root);
				printf("\n");
				break;
			case 3:
				printf("Enter the element to delete from your tree: ");
				scanf("%d",&value);
				root = delete(root,value);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Option doesn\'t exist try again");
		}
	}while(option!=4);
}

tree *insert(tree *root, int value)
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

void PreorderTraversal(tree *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

tree * delete(tree *root, int value)
{
	// Deletes node from the tree
	// Return a pointer to the resulting tree
	tree *x, *tmp_cell;

	if(root==NULL)
		return NULL;

	if(value<root->data)
	{
		root->left = delete(root->left, value);
	}
	else if(value>root->data)
	{
		root->right = delete(root->right, value);
	}
	else if(root->left&&root->right)
	{
		tmp_cell = find_min(root->right);
		root->data = tmp_cell->data;
		root->right = delete(root->right, root->data);
	}
	else
	{
		tmp_cell = root;
		if(root->left == NULL)
			root = root->right;
		else if(root->right == NULL)
			root = root->left;
		free (tmp_cell);
	}

	return root;
}

tree *find_min(tree *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->left==NULL)
	{
		return root;
	}
	else
	{
		return find_min(root->left);
	}
}
