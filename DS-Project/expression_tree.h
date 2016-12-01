#pragma once

// Expression Tree
#include "custom_math.h"
#include "custom_tree.h"
#include "custom_stack.h"
#include <string.h>
#include "stack_functions.h"

#define CYN   "\x1B[36m"
#define MAG   "\x1B[35m"
#define RESET "\x1B[0m"

Tree *TakeExpression();
Tree *ConstructExpressionTree(char []);
void MakeExpressionTree();

void MakeExpressionTree()
{
  printf(CYN "\t\t\t\t\t\t\t\t\t *\n" RESET);
  printf(MAG "\t\t\t\t\t\t\t\t\t/ \\ \n" RESET);
  printf(CYN "\t\t\t\t\t\t\t\t       +   c\n" RESET);
  printf(MAG "\t\t\t\t\t\t\t\t      / \\\n" RESET);
  printf(CYN "\t\t\t\t\t\t\t\t     a   b\n\n" RESET);
}

Tree *TakeExpression()
{
  char infix[MAX], postfix[MAX];
  printf("\t\t\t\t\t\tEnter any expression to construct its expression tree: ");
  fflush(stdin);
  scanf("%[^\n]s",infix);
  fflush(stdin);
  strcpy(postfix, "");
  InfixtoPostfix(infix, postfix);
  return ConstructExpressionTree(postfix);
}

Tree *ConstructExpressionTree(char postfix[])
{
  Tree *stack[MAX_CUSTOM_STACK] = {[0 ... (MAX_CUSTOM_STACK - 1)] = NULL},
  *t, *t1, *t2;
  // Traverse through every character of input expression
  int i, top = -1;
  for(i = 0;i < strlen(postfix);i++)
  {
    // If operand, simply push into stack
    if (!IsOperator(postfix[i]))
    {
      t = NULL;
      t = insert(postfix[i], 1, t);
      top = push_custom_stack(stack, t, top);
    }
    else // operator
    {
      t = NULL;
      t1 = NULL;
      t2 = NULL;
      t = insert(postfix[i], 1, t);

      // Pop two top nodes
      t1 = stack[top];
      top = pop_custom_stack(stack, top);
      t2 = stack[top];
      top = pop_custom_stack(stack, top);

      // Make them children
      t->right = t1;
      t->left = t2;

      // Add this subexpression to stack
      top = push_custom_stack(stack, t, top);
    }
  }

  // Only element will be root of expression tree
  t = stack[top];
  // top = pop_custom_stack(stack, top);

  return t;
}
