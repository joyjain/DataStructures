#pragma once

#include "custom_tree.h"

#define MAX_CUSTOM_STACK 1000

int push_custom_stack(Tree *[], Tree *, int);
int pop_custom_stack(Tree *[], int);

// returns the updated top
int push_custom_stack(Tree *stack[], Tree *val, int top)
{
  if(top == (MAX_CUSTOM_STACK - 1)) {
    printf("\nStack Overflow");
  }
  else
  {
    stack[top + 1] = val;
  }
  return top + 1;
}

// returns updated top
int pop_custom_stack(Tree *stack[], int top)
{
  if(top == -1) {
    printf("\nStack Underflow");
    return top;
  }
  else
  {
    // free(stack[top]);
    return top - 1;
  }
}
