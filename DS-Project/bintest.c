#include <stdio.h>
#include "print_ascii_tree.h"

//driver routine
void main()
{
  //A sample use of these functions.  Start with the empty tree
  //insert some stuff into it, and then delete it
  Tree * root = NULL;
  int i;

  make_empty(root);

  root = insert('e', 1, root);
  root = insert('c', 1, root);
  root = insert('b', 1, root);
  root = insert('e', 1, root);
  print_ascii_tree(root);

  make_empty(root);
}
