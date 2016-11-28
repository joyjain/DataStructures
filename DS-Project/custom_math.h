#pragma once

// our custom math functions and stuff
#include <stdio.h>

int MIN_VAL (int, int);
int MAX_VAL (int, int);
int IsOperator(char);

// find minimum of two or more numbers
int MIN_VAL (int X, int Y)
{
  return ((X) < (Y)) ? (X) : (Y);
}

// find maximum of two or more numbers
int MAX_VAL (int X, int Y)
{
  return ((X) > (Y)) ? (X) : (Y);
}

// A utility function to check if 'c' is an operator
int IsOperator(char c)
{
  int i = 21,
  operators[21] = {
    '+',
    '-',
    '*',
    '/',
    '^',
    '%',
    '>',
    '<',
    '=',
    '!',
    '|',
    '\\',
    '.',
    ':',
    '(',
    ')',
    '[',
    ']',
    '{',
    '}',
    '&'
  };
  while (i--) {
    if (operators[i] == c) {
      return 1;
    }
  }
  return 0;
}
