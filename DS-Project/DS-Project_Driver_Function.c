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

	printf("======================================================================    ABOUT THIS PROJECT    ======================================================================\n\n");
	printf("\t\t\t\t\t\t\tSTACK AND ALL ITS FUNCTIONS - DONE BY JAYESH BANSAL\n");
	printf("\t\t\t\t\t\t\tQUEUE AND ALL ITS FUNCTIONS - DONE BY NISHANT ARORA\n");
	printf("\t\t\t\t\t\t\t   TREE AND ALL ITS FUNCTIONS - DONE BY JOY JAIN\n\n");
	printf("======================================================================    DATA STRUCTURES    ======================================================================\n\n");
	printf("A data structure is a particular way of organizing data in a computer so that it can be used efficiently.\n");
	printf("Data structures can implement one or more particular abstract data types (ADT),\n");
	printf("which specify the operations that can be performed on a data structure and the computational complexity of those operations.\n");
	printf("In comparison, a data structure is a concrete implementation of the specification provided by an ADT.\n\n");
	printf("Different kinds of data structures are suited to different kinds of applications, and some are highly specialized to specific tasks.\n");
	printf("For example, relational databases commonly use B-tree indexes for data retrieval,\n");
	printf("while compiler implementations usually use hash tables to look up identifiers.\n\n");
	printf("Data structures provide a means to manage large amounts of data efficiently\n");
	printf("for uses such as large databases and internet indexing services.\n");
	printf("Usually, efficient data structures are key to designing efficient algorithms.\n");
	printf("Some formal design methods and programming languages emphasize data structures,\n");
	printf("rather than algorithms, as the key organizing factor in software design.\n");
	printf("Data structures can be used to organize the storage and retrieval of information stored in both main memory and secondary memory.\n");
	printf("\nWHICH DATA STRUCTURE DO YOU WANT TO KNOW ABOUT?\n\n");
	printf("PRESS 1 FOR : STACK\nPRESS 2 FOR : QUEUE\nPRESS 3 FOR : TREE\nPRESS 0 TO  : EXIT\n");
	printf("\nENTER YOUR OPTION: ");
	scanf("%d",&op);
	system("@cls||clear");
	switch(op)
	{
		case 0:
			printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
			exit(0);
			break;
		case 1:
			printf(BOLD "\n=================================================    STACKS    ===================================================================================\n\n" RESET);
			printf("PRESS 1 FOR : INTRODUCTION OF STACKS\nPRESS 2 FOR : APPLICATIONS OF STACKS\nPRESS 0 TO : EXIT\n");
			int op_loop1;
			while(1) {
				printf("\nENTER YOUR OPTION: ");
				scanf("%d",&op_loop1);
				system("@cls||clear");
				switch(op_loop1)
				{
					case 0:
					printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
					exit(0);
					break;
					case 1:
						printf(BOLD "------------ INTRODUCTION TO STACKS --------------- \n"RESET);
						printf("Stack is an abstract data type with a bounded(predefined) capacity.\n");
						printf("It is a simple data structure that allows adding and removing elements in a particular order.\n");
						printf("Every time an element is added, it goes on the top of the stack, the only element that can be\n");
						printf("removed is the element that was at the top of the stack,\n");
						printf("just like a pile of objects . \n");
						printf(" Stack is an ordered list of similar data type.\n");
						printf("Stack is a LIFO structure. (Last in First out).\n");
						printf("push() function is used to insert new elements into the Stack and pop() is used to delete an element from the stack.\n");
						printf("Both insertion and deletion are allowed at only one end of Stack called Top.\n");
						printf("Stack is said to be in Overflow state when it is completely full and is said to be in \n");
						printf("Underflow state if it is completely empty.\n");
						break;
					case 2:
						printf("\n\n---------------- APPLICATIONS OF STACKS ------------------\n\n ");
						printf("The simplest application of a stack is to reverse a word. \n");
						printf(" You push a given word to stack - letter by letter - and then pop letters from the stack.\n");
						printf("There are other uses also like : Parsing,\n ");
						printf("Expression Conversion(Infix to Postfix, Postfix to Prefix etc) and many more.\n");
						printf("PRESS 1 FOR : INFIX TO POSTFIX  \n");
						printf("PRESS 2 FOR : INFIX TO PREFIX   \n");
						printf("PRESS 3 FOR : POSTFIX TO PREFIX \n");
						printf("PRESS 4 FOR : PREFIX TO POSTFIX \n");
						printf("PRESS 5 FOR : POSTFIX EVALUATION\n");
						printf("PRESS 0 TO  : EXIT\n");
						int op_loop1_1;
						while(1) {
							printf("\nENTER YOUR OPTION: ");
							fflush(stdin);
							scanf("%d", &op_loop1_1);
							fflush(stdin);
							switch(op_loop1_1)
							{
								case 0:
									printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
									exit(0);
								break;
								case 1:
									printf("\nINFIX TO POSTFIX");
									InfixtoPostfix_call();
									break;
								case 2:
									printf("\nINFIX TO PREFIX");
									InfixtoPrefix_call();
									break;
								case 3:
									printf("\nPOSTFIX TO PREFIX");
									PostfixtoPrefix_call();
									break;
								case 4:
									printf("\nPREFIX TO POSTFIX");
									PrefixtoPostfix_call();
									break;
								case 5:
									printf("\nPOSTFIX EVALUATION");
									PostfixEvaluation_call();
									break;
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
		case 2:
			printf(BOLD "=============================================================================    QUEUES    =============================================================================\n" RESET);
			printf("\t\t\t\t\t\t\t\t\tPRESS 1 FOR : INTRODUCTION\n\t\t\t\t\t\t\t\t\tPRESS 2 FOR : APPLICATIONS\n\t\t\t\t\t\t\t\t\tPRESS 0 TO : EXIT\n");
			int op_loop2;
			while(1) {
				printf("\n\t\t\t\t\t\t\t\t\tENTER YOUR OPTION: ");
				scanf("%d",&op_loop2);
				system("@cls||clear");
				switch(op_loop2)
				{
					case 0:
					printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
					exit(0);
					break;
					case 1:
					printf(BOLD "\t\t\t\t\t\t\t------------ INTRODUCTION TO QUEUES ---------------\n" RESET);
					printf("\t\t\t\t\tQueue is an important data structure which is extensively used in computer applications. It\n");
					printf("\t\t\t\t\tis a FIFO(First-In,First-Out) data structure in which the element that is inserted first is\n");
					printf("\t\t\t\t\tthe first one to be taken out. The elements in a queue are added at one end called the REAR\n");
					printf("\t\t\t\t\tand removed from the other end called the FRONT. Queues can be implemented by using either \n");
					printf("\t\t\t\t\t\t\t\t\tarrays or linked lists. \n");
					printf("\t\t\t\t       There are four types of queues namely Circular queue,Deque,Priority queue and Multiple queue.\n");
					printf("\t\t\t\t\t  While insertion,it is said to be in Overflow state when it is completely full and while      \n");
					printf("\t\t\t\t\t  deletion of an element, it is said to be in Underflow state if it is completely empty.\n");
					break;
					case 2:
					printf("\n\n\t\t\t\t\t\t\t---------------- APPLICATIONS OF QUEUES ------------------\n\n");
					printf("\t\t\t\t\t\t\t\tQueue can also be implemented using Stacks.\n");
					printf("\t\t\t\t\t\t\t   One of the applications of queues is Josephus problem.\n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 1 FOR : LINEAR QUEUE \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 2 FOR : DEQUE \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 3 FOR : PRIORITY QUEUE \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 4 FOR : JOSEPHUS PROBLEM \n");
					printf("\t\t\t\t\t\t\t\t\tPRESS 0 TO  : EXIT\n");
					int op_loop2_1;
					while(1) {
						printf("\n\t\t\t\t\t\t\t   ENTER YOUR OPTION(FOR MENU OF APPLICATIONS OF QUEUE): ");
						scanf("%d",&op_loop2_1);
						switch(op_loop2_1)
						{
							case 1:
							printf("\n\t\t\t\t\t\t\t\t\t   LINEAR QUEUE");
							Linearqueue1();
							break;
							case 2:
							printf("\n DEQUE");
							Deques2();
							break;
							case 3:
							printf("\n PRIORITY QUEUE");
							Priorityqueue3();
							break;
							case 4:
							printf("\n JOSEPHUS PROBLEM");
							Josephusproblem4();
							break;
							case 0:
							printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
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
			printf("\t\t\t\t\t\t\t\tPRESS 1 FOR : INTRODUCTION OF TREES\n\t\t\t\t\t\t\t\tPRESS 2 FOR : APPLICATIONS OF TREES\n\t\t\t\t\t\t\t\tPRESS 0 TO  : EXIT\n");
			int op_loop3;
			while(1) {
				printf("\n\t\t\t\t\t\t\t\tENTER YOUR OPTION: ");
				scanf("%d",&op_loop3);
				system("@cls||clear");
				switch(op_loop3)
				{
					case 0:
					printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
					exit(0);
					break;
					case 1:
						printf(BOLD "------------------------------------------------------------------ INTRODUCTION TO TREES ------------------------------------------------------------------\n\n" RESET);
						printf("\t\t\tA tree is recursively defined as a set of one or more nodes where one node is designated as the root of the tree\n");
						printf("\t\t\t   and all the remaining nodes can be partitioned into non-empty sets each of which is a sub-tree of the root.\n");
						printf("\t\t     tree is a non-linear data structure (Unlike array, stack, queue etc.). There are many different types of trees such as\n");
						printf("\t\t\t\t\tGeneral trees, Binary trees, Binary search trees, Multi-way search trees etc.\n");
						printf("\t\t\t\t\t\t\t\tBasic terminology of a tree:-\n");
						printf(BOLD "\t\t\tRoot node " RESET "- The root node R is the topmost node in the tree. If R = NULL, then it means the tree is empty.\n");
						printf(BOLD "\t\t\tSub-trees " RESET "- If the root node R is not NULL, then the trees (i.e the nodes under it) are called the sub-trees of R.\n");
						printf(BOLD "\t\t\tLeaf node " RESET "- A node that has no children is called the leaf node or the terminal node.\n");
						printf(BOLD "\t\t\tAncestor node " RESET "- An ancestor of a node is any predecessor node on the path from root to that node. The root node does not have any ancestors.\n");
						printf(BOLD "\t\t\tDescendant node " RESET "- A descendant node is any successor node on any path from the node to a leaf node. Leaf nodes do not have any descendants.\n");
						printf(BOLD "\t\t\tDegree " RESET "- Degree of a node is equal to the number of children that a node has. The degree of a leaf node is zero.\n");
						printf(BOLD "\t\t\tIn-degree " RESET "- In-degree of a node is the number of edges arriving at that node.\n");
						printf(BOLD "\t\t\tOut-degree " RESET "- Out-degree of a node is the number of edges leaving that node.\n");
						break;
					case 2:
						printf("\n\n------------------------------------------------------------------ APPLICATIONS OF TREES ------------------------------------------------------------------\n\n");
						printf("\t\t\t\t\t\tThe simplest application of a tree is a binary search tree.\n");
						printf("\t\t\t    In a binary search tree, all the nodes in the left sub-tree have a value less than that of the root node.\n");
						printf("\t\t\tCorrespondingly, all the nodes in the right sub-tree have a value either equal to or greater than the root node.\n");
						printf("\t\t\t\t\t\tThe same rule is applicable to every sub-tree in the tree.\n\n");
						printf("\t\t\t\t\t\tPRESS 1 TO : FIND THE EXPRESSION TREE OF A GIVEN INFIX EXPRESSION\n");
						printf("\t\t\t\t\t\tPRESS 2 TO : CREATE A TOURNAMENT TREE FROM THE NUMBER OF PLAYERS\n");
						printf("\t\t\t\t\t\tPRESS 3 TO : COMPRESS A SENTENCE USING HUFFMAN CODING\n");
						printf("\t\t\t\t\t\tPRESS 0 TO : EXIT\n");
						int op_loop3_1, value;
						while(1) {
							printf("\n\t\t\t\t\t\t\t\tENTER YOUR OPTION: ");
							scanf("%d",&op_loop3_1);
							switch(op_loop3_1)
							{
								case 0:
								printf("--------------------------------------------------------- THANKS FOR USING THIS PROGRAM, GOODBYE ---------------------------------------------------------\n");
								exit(0);
								break;
								case 1:
									printf("\n\t\t\t\t\t\tFOR EXAMPLE, THE EXPRESSION TREE FOR THE EXPRESSION (a+b)*c IS:\n\n");
									MakeExpressionTree();
									root = TakeExpression();
									printf("\nYOUR EXPRESSION TREE IS:\n\n");
									print_ascii_tree(root);
									printf("\t\t\t\t\t\tENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
									break;
								case 2:
									printf("WE ALL KNOW THAT IN A TOURNAMENT, SAY OF CHESS, \"N\" NUMBER OF PLAYERS PARTICIPATE.\n");
									printf("TO DECLARE A THE WINNER AMONG ALL THESE PLAYERS, A COUPLE OF MATCHES ARE PLAYED\n\n");
									root = TournamentTree();
									printf("\nYOUR TOURNAMENT TREE IS:\n\n");
									print_ascii_tree(root);
									printf("ENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
									break;
								case 3:
								{
									char sentence[250], letters[250] = {[0 ... 249] = ' '}, letter = 'a';
									printf("ENTER A SENTENCE TO ENCODE IT:\n");
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
								  printf("THE ENCODED SENTENCE IS\n");
								  // till the end of sentence with length i
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
								  printf("\nSTORAGE (IN BITS) - ORIGINAL: %d, NEW: %d\n, SAVED: %d%%", j, m, (j - m) * 100 / j);
									printf("\n\nENTER ANY OF THE ABOVE OPTIONS FOR ANOTHER APPLICATION OR 0 TO EXIT\n");
									break;
								}
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
		default:
			system("@cls||clear");
			printf("OPTION DOESN\'T EXIST TRY AGAIN");
	}
}
