#pragma once

// Tournament Tree
#include "custom_math.h"
#include "custom_tree.h"
#include "stack_functions.h"
#define MAX_ARRAY 100

Tree *tournament[MAX_ARRAY];
char tournament_weights[MAX_ARRAY];
char players[MAX_ARRAY];

Tree *TournamentTree();

Tree *TournamentTree()
{
  char user = 'A';
  int rounds = 0, value, i = 0, j = 0, n;
  Tree *root = NULL;
  printf("\t\t\t\t\t\tEnter the number of players in your Tournament initially (In powers of 2): ");
  fflush(stdin);
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    make_empty(tournament[i]);
    players[i] = user;
    printf("\t\t\t\t\t\t\tEnter Player %c\'s winning chance(Scale 0 to 9): ", user++);
    fflush(stdin);
    scanf("%c", &tournament_weights[i]);
    tournament[i] = insert(players[i], 1, tournament[i]);
  }

  for(;n!=1;n/=2)
  {
    i = 0;
    j = 0;
    for(;i<n;i+=2,j++)
    {
      root = NULL;
      if (tournament_weights[i] > tournament_weights[i+1]) {
        root = insert(players[i], 1, root);
        players[j] = players[i];
        tournament_weights[j] = tournament_weights[i];
      }
      else {
        root = insert(players[i+1], 1, root);
        players[j] = players [i+1];
        tournament_weights[j] = tournament_weights[i+1];
      }
      root = addNodes(root, tournament[i], tournament[i+1]);
      tournament[j] = root;
    }
  }
  return tournament[0];
}
