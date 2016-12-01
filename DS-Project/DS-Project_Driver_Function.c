// Compiled and runned on linux based elementary OS 0.3.2 Freya (64-bit)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// Header Files for functions of different Data Structures used here
#include "custom_tree.h"
#include "print_ascii_tree.h"
#include "expression_tree.h"
#include "huffman_coding.h"
#include "tournament_tree.h"
#include "stack_functions.h"
#include "queue_functions.h"

// Following are the codes for colored text
// Note - These colour codes work on linux OS only
#define BLK   "\x1B[30m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m" // code to reset text to its default value
#define BOLD  "\x1B[1m" // code for bold text
// Following are the codes for colored background
#define BLKBG "\x1B[40m"
#define REDBG "\x1B[41m"
#define GRNBG "\x1B[42m"
#define YELBG "\x1B[43m"
#define BLUBG "\x1B[44m"
#define MAGBG "\x1B[45m"
#define CYNBG "\x1B[46m"
#define WHTBG "\x1B[47m"

void main()
{
	int op, value;
	int result;

	Tree * root;

	system("@cls||clear");
	printf(BOLD BLK"======================================================================    ABOUT THIS PROJECT    ======================================================================\n\n" RESET);
	printf("\t\t\t\t\t\t\tSTACK AND ALL ITS FUNCTIONS - DONE BY JAYESH BANSAL\n");
	printf("\t\t\t\t\t\t\tQUEUE AND ALL ITS FUNCTIONS - DONE BY NISHANT ARORA\n");
	printf("\t\t\t\t\t\t\t   TREE AND ALL ITS FUNCTIONS - DONE BY JOY JAIN\n\n");
	printf(BOLD "======================================================================    DATA STRUCTURES    ======================================================================\n\n" RESET);
	printf(YEL "\t\t\t\tA data structure is a particular way of organizing data in a computer so that it can be used efficiently.\n");
	printf("\t\t\t\t\t    Data structures can implement one or more particular abstract data types (ADT),\n");
	printf("\t\t\twhich specify the operations that can be performed on a data structure and the computational complexity of those operations.\n");
	printf("\t\t\t\t    In comparison, a data structure is a concrete implementation of the specification provided by an ADT.\n\n");
	printf("\t\t    Different kinds of data structures are suited to different kinds of applications, and some are highly specialized to specific tasks.\n");
	printf("\t\t\t\t\t    For example, relational databases commonly use B-tree indexes for data retrieval,\n");
	printf("\t\t\t\t\t     while compiler implementations usually use hash tables to look up identifiers.\n\n");
	printf("\t\t\t\t\t     Data structures provide a means to manage large amounts of data efficiently\n");
	printf("\t\t\t\t\t\t   for uses such as large databases and internet indexing services.\n");
	printf("\t\t\t\t\t    Usually, efficient data structures are key to designing efficient algorithms.\n");
	printf("\t\t\t\t\t   Some formal design methods and programming languages emphasize data structures,\n");
	printf("\t\t\t\t\t      rather than algorithms, as the key organizing factor in software design.\n");
	printf("\t\t      Data structures can be used to organize the storage and retrieval of information stored in both main memory and secondary memory.\n" RESET);
	printf(GRN "\n\t\t\t\t\t\t\t    WHICH DATA STRUCTURE DO YOU WANT TO KNOW ABOUT?\n\n");
	printf("\t\t\t\t\t\t\t\t\t  PRESS 1 FOR : STACK\n\t\t\t\t\t\t\t\t\t  PRESS 2 FOR : QUEUE\n\t\t\t\t\t\t\t\t\t  PRESS 3 FOR : TREE\n\t\t\t\t\t\t\t\t\t  PRESS 0 TO  : EXIT\n" RESET);
	printf(GRN "\n\t\t\t\t\t\t\t\t\t  ENTER YOUR OPTION: " RESET);
	scanf("%d",&op);
	system("@cls||clear");
	switch(op)
	{
		case 0:
			printf(BOLD RED "--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n" RESET);
			exit(0);
			break;
		case 1:
			printf(BOLD "\n===========================================================================    STACKS    ===========================================================================\n\n" RESET);
			printf(GRN "\t\t\t\t\t\t\t\tPRESS 1 FOR : INTRODUCTION OF STACKS\n\t\t\t\t\t\t\t\tPRESS 2 FOR : APPLICATIONS OF STACKS\n\t\t\t\t\t\t\t\tPRESS 0 TO : EXIT\n" RESET);
			int op_loop1;
			while(1) {
				printf(GRN "\n\t\t\t\t\t\t\t\tENTER YOUR OPTION: " RESET);
				scanf("%d",&op_loop1);
				system("@cls||clear");
				switch(op_loop1)
				{
					case 0:
					printf(BOLD RED "--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n" RESET);
					exit(0);
					break;
					case 1:
						printf(BOLD "------------------------------------------------------------------------ INTRODUCTION TO STACKS ------------------------------------------------------------------------\n"RESET);
						printf(BLU "\t\t\tStack is an abstract data type with a bounded(predefined) capacity.\n");
						printf("\t\t\tIt is a simple data structure that allows adding and removing elements in a particular order.\n");
						printf("\t\t\tEvery time an element is added, it goes on the top of the stack, the only element that can be\n");
						printf("\t\t\tremoved is the element that was at the top of the stack,\n");
						printf("\t\t\tjust like a pile of objects . \n");
						printf(" \t\t\tStack is an ordered list of similar data type.\n");
						printf("\t\t\tStack is a LIFO structure. (Last in First out).\n");
						printf("\t\t\tpush() function is used to insert new elements into the Stack and pop() is used to delete an element from the 	stack.\n");
						printf("\t\t\tBoth insertion and deletion are allowed at only one end of Stack called Top.\n");
						printf("\t\t\tStack is said to be in Overflow state when it is completely full and is said to be in \n");
						printf("\t\t\tUnderflow state if it is completely empty.\n" RESET);
						break;
					case 2:
						printf(BOLD "\n\n------------------------------------------------------------------------ APPLICATIONS OF STACKS ------------------------------------------------------------------------\n\n " RESET);
						printf(BLU "\t\t\t\t\t\t\tThe simplest application of a stack is to reverse a word.\n");
						printf("\t\t\t\t\tYou push a given word to stack - letter by letter - and then pop letters from the stack.\n");
						printf("\t\t\t\t\t\t\t\tThere are other uses also like : Parsing,\n ");
						printf("\t\t\t\t\t     Expression Conversion(Infix to Postfix, Postfix to Prefix etc) and many more.\n" RESET );
						printf(GRN "\t\t\t\t\t\t\t\t\tPRESS 1 FOR : INFIX TO POSTFIX  \n");
						printf("\t\t\t\t\t\t\t\t\tPRESS 2 FOR : INFIX TO PREFIX   \n");
						printf("\t\t\t\t\t\t\t\t\tPRESS 3 FOR : POSTFIX TO PREFIX \n");
						printf("\t\t\t\t\t\t\t\t\tPRESS 4 FOR : PREFIX TO POSTFIX \n");
						printf("\t\t\t\t\t\t\t\t\tPRESS 5 FOR : POSTFIX EVALUATION\n");
						printf("\t\t\t\t\t\t\t\t\tPRESS 0 TO  : EXIT\n" RESET );
						int op_loop1_1;
						while(1) {
							printf(GRN "\n\t\t\t\t\t\t\t\t\tENTER YOUR OPTION: " RESET);
							fflush(stdin);
							scanf("%d", &op_loop1_1);
							fflush(stdin);
							switch(op_loop1_1)
							{
								case 0:
									printf(BOLD RED "--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n" RESET);
									exit(0);
								break;
								case 1:
									printf(YEL "\n\t\t\t\t\t\t\t\t\t   INFIX TO POSTFIX\n" RESET);
									InfixtoPostfix_call();
									break;
								case 2:
									printf(YEL "\n\t\t\t\t\t\t\t\t\t   INFIX TO PREFIX\n" RESET);
									InfixtoPrefix_call();
									break;
								case 3:
									printf(YEL "\n\t\t\t\t\t\t\t\t\t   POSTFIX TO PREFIX\n" RESET);
									PostfixtoPrefix_call();
									break;
								case 4:
									printf( YEL "\n\t\t\t\t\t\t\t\t\t   PREFIX TO POSTFIX\n" RESET );
									PrefixtoPostfix_call();
									break;
								case 5:
									printf(YEL "\n\t\t\t\t\t\t\t\t\t   POSTFIX EVALUATION\n" RESET);
									PostfixEvaluation_call();
									break;
								default:
								printf("\t\t\tOPTION DOESN\'T EXIST TRY AGAIN\t\t\t");
							}
						}
						break;
					default:
					printf("\t\t\tOPTION DOESN\'T EXIST TRY AGAIN");
				}
			}
			break;
		case 2:
			printf(BOLD "=============================================================================    QUEUES    =============================================================================\n" RESET);
			printf(GRN "\t\t\t\t\t\t\t\t\tPRESS 1 FOR : INTRODUCTION\n\t\t\t\t\t\t\t\t\tPRESS 2 FOR : APPLICATIONS\n\t\t\t\t\t\t\t\t\tPRESS 0 TO : EXIT\n" RESET);
			int op_loop2;
			while(1) {
				printf(GRN "\n\t\t\t\t\t\t\t\t\tENTER YOUR OPTION: " RESET);
				scanf("%d",&op_loop2);
				system("@cls||clear");
				switch(op_loop2)
				{
					case 0:
					printf(BOLD RED "--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n" RESET);
					exit(0);
					break;
					case 1:
					printf(BOLD "------------------------------------------------------------------------ INTRODUCTION TO QUEUES ------------------------------------------------------------------------\n" RESET);
					printf(BLU "\t\t\t\t\tQueue is an important data structure which is extensively used in computer applications. It\n");
					printf("\t\t\t\t\tis a FIFO(First-In,First-Out) data structure in which the element that is inserted first is\n");
					printf("\t\t\t\t\tthe first one to be taken out. The elements in a queue are added at one end called the REAR\n");
					printf("\t\t\t\t\tand removed from the other end called the FRONT. Queues can be implemented by using either \n");
					printf("\t\t\t\t\t\t\t\t\tarrays or linked lists. \n");
					printf("\t\t\t\t       There are four types of queues namely Circular queue,Deque,Priority queue and Multiple queue.\n");
					printf("\t\t\t\t\t  While insertion,it is said to be in Overflow state when it is completely full and while      \n");
					printf("\t\t\t\t\t  deletion of an element, it is said to be in Underflow state if it is completely empty.\n" RESET);
					break;
					case 2:
					printf(BOLD "\n\n------------------------------------------------------------------------ APPLICATIONS OF QUEUES ------------------------------------------------------------------------\n\n" RESET);
					printf(BLU "\t\t\t\t\t\t\t\tQueue can also be implemented using Stacks.\n");
					printf("\t\t\t\t\t\t\t   One of the applications of queues is Josephus problem.\n" RESET);
					printf(GRN "\t\t\t\t\t\t\t\t\tPRESS 1 FOR : LINEAR QUEUE \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 2 FOR : DEQUE \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 3 FOR : PRIORITY QUEUE \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 4 FOR : JOSEPHUS PROBLEM \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 0 TO  : EXIT\n" RESET);
					int op_loop2_1;
					while(1) {
						printf(GRN "\n\t\t\t\t\t\t\t   ENTER YOUR OPTION(FOR MENU OF APPLICATIONS OF QUEUE): " RESET);
						scanf("%d",&op_loop2_1);
						switch(op_loop2_1)
						{
							case 1:
							printf(YEL "\n\t\t\t\t\t\t\t\t\t   LINEAR QUEUE" RESET);
							Linearqueue1();
							break;
							case 2:
							printf(YEL "\n\t\t\t\t\t\t\t\t\t   DEQUE" RESET);
							Deques2();
							break;
							case 3:
							printf(YEL "\n\t\t\t\t\t\t\t\t\t   PRIORITY QUEUE" RESET);
							Priorityqueue3();
							break;
							case 4:
							printf(YEL "\n\t\t\t\t\t\t\t\t\t   JOSEPHUS PROBLEM" RESET);
							Josephusproblem4();
							break;
							case 0:
							printf(BOLD RED "--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n" RESET);
							exit(0);
							default:
							printf("OPTION DOESN\'T EXIST TRY AGAIN");
						}
					}
					break;
					default:
						printf("OPTION DOESN\'T EXIST TRY AGAIN");
				}
			}
			break;
		case 3:
			printf(BOLD "\n============================================================================    TREES    ============================================================================\n\n" RESET " ");
			printf(GRN "\t\t\t\t\t\t\t\tPRESS 1 FOR : INTRODUCTION OF TREES\n\t\t\t\t\t\t\t\tPRESS 2 FOR : APPLICATIONS OF TREES\n\t\t\t\t\t\t\t\tPRESS 0 TO  : EXIT\n" RESET);
			int op_loop3;
			while(1) {
				printf(GRN "\n\t\t\t\t\t\t\t\tENTER YOUR OPTION: " RESET);
				scanf("%d",&op_loop3);
				system("@cls||clear");
				switch(op_loop3)
				{
					case 0:
					printf(BOLD RED "--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n" RESET);
					exit(0);
					break;
					case 1:
						printf(BOLD "------------------------------------------------------------------------ INTRODUCTION TO TREES ------------------------------------------------------------------------\n\n" RESET);
						printf(BLU "\t\t\tA tree is recursively defined as a set of one or more nodes where one node is designated as the root of the tree\n");
						printf("\t\t\t   and all the remaining nodes can be partitioned into non-empty sets each of which is a sub-tree of the root.\n");
						printf("\t\t     tree is a non-linear data structure (Unlike array, stack, queue etc.). There are many different types of trees such as\n");
						printf("\t\t\t\t\tGeneral trees, Binary trees, Binary search trees, Multi-way search trees etc.\n");
						printf("\t\t\t\t\t\t\t\tBasic terminology of a tree:-\n" RESET);
						printf(BOLD "\t\t\tRoot node " RESET BLU "- The root node R is the topmost node in the tree. If R = NULL, then it means the tree is empty.\n" RESET);
						printf(BOLD "\t\t\tSub-trees " RESET BLU "- If the root node R is not NULL, then the trees (i.e the nodes under it) are called the sub-trees of R.\n" RESET);
						printf(BOLD "\t\t\tLeaf node " RESET BLU "- A node that has no children is called the leaf node or the terminal node.\n" RESET);
						printf(BOLD "\t\t\tAncestor node " RESET BLU "- An ancestor of a node is any predecessor node on the path from root to that node. The root node does not have any ancestors.\n" RESET);
						printf(BOLD "\t\t\tDescendant node " RESET BLU "- A descendant node is any successor node on any path from the node to a leaf node. Leaf nodes do not have any descendants.\n" RESET);
						printf(BOLD "\t\t\tDegree " RESET BLU "- Degree of a node is equal to the number of children that a node has. The degree of a leaf node is zero.\n" RESET);
						printf(BOLD "\t\t\tIn-degree " RESET BLU "- In-degree of a node is the number of edges arriving at that node.\n" RESET);
						printf(BOLD "\t\t\tOut-degree " RESET BLU "- Out-degree of a node is the number of edges leaving that node.\n" RESET);
						break;
					case 2:
						printf(BOLD "\n\n------------------------------------------------------------------------- APPLICATIONS OF TREES ------------------------------------------------------------------------\n\n" RESET);
						printf(BLU "\t\t\t\t\t\tThe simplest application of a tree is a binary search tree.\n");
						printf("\t\t\t    In a binary search tree, all the nodes in the left sub-tree have a value less than that of the root node.\n");
						printf("\t\t\tCorrespondingly, all the nodes in the right sub-tree have a value either equal to or greater than the root node.\n");
						printf("\t\t\t\t\t\tThe same rule is applicable to every sub-tree in the tree.\n\n" RESET);
						printf(GRN "\t\t\t\t\t\tPRESS 1 TO : FIND THE EXPRESSION TREE OF A GIVEN INFIX EXPRESSION\n");
						printf("\t\t\t\t\t\tPRESS 2 TO : CREATE A TOURNAMENT TREE FROM THE NUMBER OF PLAYERS\n");
						printf("\t\t\t\t\t\tPRESS 3 TO : COMPRESS A SENTENCE USING HUFFMAN CODING\n");
						printf("\t\t\t\t\t\tPRESS 0 TO : EXIT\n" RESET);
						int op_loop3_1, value;
						while(1) {
							printf(GRN "\n\t\t\t\t\t\t\t\tENTER YOUR OPTION: " RESET);
							scanf("%d",&op_loop3_1);
							switch(op_loop3_1)
							{
								case 0:
								printf(BOLD RED "--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n" RESET);
								exit(0);
								break;
								case 1:
									printf(YEL "\n\t\t\t\t\t\tFOR EXAMPLE, THE EXPRESSION TREE FOR THE EXPRESSION (a+b)*c IS:\n\n" RESET);
									MakeExpressionTree();
									root = TakeExpression();
									printf("\nYOUR EXPRESSION TREE IS:\n\n");
									print_ascii_tree(root);
									printf("\t\t\t\t\t\tENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
									break;
								case 2:
									printf("\n\t\t\t\t\t    WE ALL KNOW THAT IN A TOURNAMENT, SAY OF CHESS, \"N\" NUMBER OF PLAYERS PARTICIPATE.\n");
									printf("\t\t\t\t\t    TO DECLARE A THE WINNER AMONG ALL THESE PLAYERS, A COUPLE OF MATCHES ARE PLAYED\n\n");
									root = TournamentTree();
									printf("\nYOUR TOURNAMENT TREE IS:\n\n");
									print_ascii_tree(root);
									printf("\t\t\t\t\t\tENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
									break;
								case 3:
								{
									char sentence[250], letters[250] = {[0 ... 249] = ' '}, letter = 'a';
									printf("\t\t\t\t\t\t\t    ENTER A SENTENCE TO ENCODE IT: ");
									fflush(stdin);
								  scanf("%[^\n]%*c", sentence);
								  int i = -1, j = 0, m = 0, count = 0, frequency[250];
								  // reset the code counter
								  codeCount = 0;
								  while (letter != '\0') {
								    letter = sentence[++i];
								    for (j = 0; j <= count; j++) {
								      // if found update frequency
								      if (letters[j] == letter) {
								        frequency[j]++;
								        break;
								      }
								      // if last letter and it still hasn't been found
								      if (j == count) {
								        letters[count] = letter;
								        frequency[count++] = 1;
								        break;
								      }
								    }
								  }
								  // pass this info to Huffman algo
								  HuffmanCodes(letters, frequency, count);
								  // the output encoded sentence
								  printf("\t\t\t\t\t\t\t\t\tTHE ENCODED SENTENCE IS\n");
								  // till the end of sentence with length i
									printf("\t\t\t\t\t\t\t\t\t");
								  for (j = 0; j < i; j++) {
								    // till all the letters are scanned to find the matching one
								    for (int k = 0; k < count; k++) {
								      if (sentence[j] == '\0' || sentence[j] == ' ') {
								        printf("%c", sentence[j]);
								        break;
								      }
								      if (codeTable[k] == sentence[j]) {
								        // print the code
								        for (int l = 0; generatedCodes[k][l] != -1; l++, m++) {
								          printf("%d", generatedCodes[k][l]);
								        }
								        break;
								      }
								    }
								  }
									j = 8 * i * sizeof(char);
								  printf("\n\t\t\t\t\t\t\tSTORAGE (IN BITS) - ORIGINAL: %d, NEW: %d, SAVED: %d%%", j, m, (j - m) * 100 / j);
									printf("\n\n\t\t\t\t\t\tENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
									break;
								}
								default:
								printf("\t\t\t\tOPTION DOESN\'T EXIST TRY AGAIN");
							}
						}
						break;
					default:
					printf("\t\t\t\tOPTION DOESN\'T EXIST TRY AGAIN");
				}
			}
			break;
		default:
			system("@cls||clear");
			printf("\t\t\t\tOPTION DOESN\'T EXIST TRY AGAIN");
	}
}
