// use these guard conditions
#ifndef FILE_NAME_H
#define FILE_NAME_H
// put endif at the end of that header file
#endif

#include <stdio.h>
#include "custom_math.h"
#include "print_ascii_tree.h"

//driver routine
void main()
{
  //A sample use of these functions.  Start with the empty tree
  //insert some stuff into it, and then delete it
  Tree * root = NULL, * a = NULL, * b = NULL;
  int i;

  // make_empty(root);

  a = insert(5, 0, a);
  b = insert(3, 0, b);
  root = insert(7, 0, root);

  a = addNodes(a, root, b);
  root = NULL;
  root = insert(9, 0, root);
  b = addNodes(b, root, root);


  // printf("\nAfter inserting element A..\n");
  // root = insert('A', 1, root);
  print_ascii_tree(a);
  //
  // printf("\nAfter inserting element +..\n");
  // root = insert('+', 1, root);
  // print_ascii_tree(root);
  //
  // printf("\nAfter inserting element 15..\n");
  // root = insert(15, 0, root);
  // print_ascii_tree(root);
  //
  // printf("\nAfter inserting elements 9, B..\n");
  // root = insert(9, 0, root);
  // root = insert('B', 1, root);
  // print_ascii_tree(root);
  //
  // printf("\nAfter inserting elements 2, 6, 12, 14, ..\n");
  // root = insert(2, 0, root);
  // root = insert(6, 0, root);
  // root = insert(12, 0, root);
  // root = insert(14, 0, root);
  // print_ascii_tree(root);
  //
  // printf("%d\n", 'a');
  // printf("%d\n", 'z');
  // printf("%d\n", 'A');
  // printf("%d\n", 'Z');
  // delete some nodes
  // printf("\n\nAfter deleting a node (14) with no child..\n");
  // root = delete(14, root);
  // print_ascii_tree(root);
  //
  // printf("\n\nAfter deleting a node (13) with left child..\n");
  // root = delete(13, root);
  // print_ascii_tree(root);
  //
  // printf("\n\nAfter deleting a node (5) with left and right children..\n");
  // root = delete(5, root);
  // print_ascii_tree(root);
  //
  //   printf("\n\nAfter deleting a node (10, root node) with left and right children..\n");
  // root = delete(10, root);
  // print_ascii_tree(root);

  // make_empty(root);
}
