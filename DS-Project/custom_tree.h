#ifndef CUSTOM_TREE_H
#define CUSTOM_TREE_H

// tree datastructure customised to our needs
#include <stdio.h>

// datastructure prototype
typedef struct Tree Tree;

// function prototype
Tree *make_empty(Tree *);
Tree *find_min(Tree *);
Tree *find_max(Tree *);
Tree *find(int, Tree *);
Tree * addNodes(Tree *,Tree *, Tree *);
Tree * insert(char, int, Tree *);
Tree * delete(int, Tree *);


struct Tree
{
  Tree * left, * right;
  // means it is not an integer but a..z, A..Z or +- etc.
  // it should store 0 or 1 only
  int isSpecial;
  // the actual data
  char element;
};

Tree *make_empty(Tree *t)
{
  if (t != NULL)
  {
    make_empty(t->left);
    make_empty(t->right);
    free(t);
  }

  return NULL;
}

Tree *find_min(Tree *t)
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

Tree *find_max(Tree *t)
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

Tree *find(int elem, Tree *t)
{
  if (t == NULL)
  {
    return NULL;
  }

  if (elem < t->element)
  {
    return find(elem, t->left);
  }
  else if (elem > t->element)
  {
    return find(elem, t->right);
  }
  else
  {
    return t;
  }
}

// left and right
Tree * addNodes(Tree *root,Tree *left , Tree *right) {
  // Tree * new_node;
  // new_node = (Tree *) malloc (sizeof (Tree));

  root->left = left;
  root->right = right;
  return root;
}

//Insert i into the tree t, duplicate will be discarded
//Return a pointer to the resulting tree.
Tree * insert(char value, int isSpecial, Tree * t)
{
  Tree * new_node;

  if (t == NULL)
  {
    new_node = (Tree *) malloc (sizeof (Tree));
    if (new_node == NULL)
    {
	    return t;
    }

    new_node->element = value;
    new_node->isSpecial = isSpecial;

	  new_node->left = new_node->right = NULL;
	  return new_node;
  }

  if (value < t->element)
  {
    t->left = insert(value, isSpecial, t->left);
  }
  else if (value > t->element)
  {
	  t->right = insert(value, isSpecial, t->right);
  }
  //else duplicate, ignore it

  return t;
}

// for delete pass the chars as e.g 'a' and int as e.g 69
Tree * delete(int value, Tree * t)
{
  //Deletes node from the tree
  // Return a pointer to the resulting tree
  Tree * x;
  Tree *tmp_cell;

  if (t==NULL) return NULL;

  if (value < t->element)
  {
    t->left = delete(value, t->left);
  }
  else if (value > t->element)
  {
	  t->right = delete(value, t->right);
  }
  else if (t->left && t->right)
  {
    tmp_cell = find_min(t->right);
    t->element = tmp_cell->element;
    t->right = delete(t->element, t->right);
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

#endif
