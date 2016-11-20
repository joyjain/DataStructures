//compiled and runned on linux based elementary OS 0.3.2 Freya (64-bit)
#include <stdio.h>
//Following are the codes for colored text
#define BLK   "\x1B[30m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m" //code to reset text to its default value
#define BOLD  "\x1B[1m" //code for bold text
//Following are the codes for colored background
#define BLKBG "\x1B[40m"
#define REDBG "\x1B[41m"
#define GRNBG "\x1B[42m"
#define YELBG "\x1B[43m"
#define BLUBG "\x1B[44m"
#define MAGBG "\x1B[45m"
#define CYNBG "\x1B[46m"
#define WHTBG "\x1B[47m"
void InfixToPostfix(){
printf("hey i am InfixToPostfix");  //Jugaad hai
}
void InfixToPrefix(){
printf("hey i am InfixToPrefix");

}
void PostfixToPrefix(){
printf("hey i am PostfixToPrefix");

}
void PrefixToPostfix(){
printf("hey i am PrefixToPostfix");

}
void PostfixEvaluation(){
printf("hey i am PostfixEvaluation"); // jugad hai

}
void PrefixEvaluation(){
printf("hey i am PrefixEvaluation");

}

int main() {
 printf(BOLD BLK  "=================================================    STACKS    ===================================================================================\n" RESET RESET);
 printf("PRESS 1 FOR : INTRODUCTION\nPRESS 2 FOR : APPLICATIONS\nPRESS 0 TO : EXIT\n");
int c ;
  do {
  printf("ENTER YOUR OPTION: ");
  scanf("%d",&c);
           switch(c)
           {
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
                    printf("PRESS 1 FOR : INFIX TO POSTFIX \n");
                    printf("PRESS 2 FOR : INFIX TO PREFIX \n");
                    printf("PRESS 3 FOR : POSTFIX TO PREFIX\n");
                    printf("PRESS 4 FOR : PREFIX TO POSTFIX \n");
                    printf("PRESS 5 FOR : POSTFIX EVALUATION\n");
                    printf("PRESS 6 FOR : PREFIX EVALUATION \n");
                    printf("PRESS 0 TO  : EXIT\n");
                    int d;
                    do {
                      printf("ENTER YOUR OPTION ");
                      scanf("%d",&d);
                      switch(d)
                      {
                        case 1:
                       
                        printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         printf("\n PRESS 2 TO: RUN THE SOURCE CODE\n\n ");
                         printf("PRESS 0 TO EXIT\n");
                          int e;
                        do{
                        scanf("%d",&e);
                        switch (e)
                        {
                          case 0:
                            printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");

                          return 0 ;
                          break;
                          case 1:
                          break;
                          case 2:
                          InfixToPostfix();
                          break;
                          default:
                            printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");


                        }
                      }while(e!=0);

                        break;
                        case 2:
                         printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         printf("\n PRESS 2 TO: RUN THE SOURCE CODE\n\n ");
                         printf("PRESS 0 TO EXIT\n");
                          int f;

                        do{
                        scanf("%d",&f);
                        switch (f)
                        {
                          case 0:
                            printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");

                          return 0 ;
                          break;
                          case 1:
                          break;
                          case 2:
                          InfixToPrefix();
                          break;
                          default:
                            printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");


                        }
                      }
                          while(f!=0);
                      
                      
                        break;
                        case 3:
                         printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         printf("\n PRESS 2 TO: RUN THE SOURCE CODE \n\n");
                         printf("PRESS 0 TO EXIT\n");
                         int g;
                        do{
                          
                        scanf("%d",&g);
                        switch (g)
                        {
                          case 0:
                            printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");

                          return 0 ;
                          break;
                          case 1:
                          break;
                          case 2:
                          PostfixToPrefix();
                          break;
                          default:
                            printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");


                        }
                          }
                        while(g!=0);
                      
                        
                        break;
                        case 4:
                         printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         printf("\n PRESS 2 TO: RUN THE SOURCE CODE\n\n ");
                         printf("PRESS 0 TO EXIT\n");
                         int h ;
                        do{

                        scanf("%d",&h);
                        switch (h)
                        {
                          case 0:
                            printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");

                          return 0 ;
                          break;
                          case 1:
                          break;
                          case 2:
                          PrefixToPostfix();
                          break;
                          default:
                            printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");


                        }
                      }while(h!=0);
                       
                        break;
                        case 5:
                       
                        printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         printf("\n PRESS 2 TO: RUN THE SOURCE CODE \n\n");
                         printf("PRESS 0 TO EXIT\n\n");
                         int i ;
                        do{
                        scanf("%d",&i);
                        switch (i)
                        {
                          case 0:
                            printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");

                          return 0 ;
                          break;
                          case 1:
                          break;
                          case 2:
                          PostfixEvaluation();
                          break;
                          default:
                            printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");


                        }
                      } while(i!=0);
                        break;
                        case 6:
                       
                        printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         printf("\n PRESS 2 TO: RUN THE SOURCE CODE \n");
                         printf("PRESS 0 TO EXIT\n");
                         int j ; 
                        do{
                        scanf("%d",&j);
                        switch (j)
                        {
                          case 0:
                            printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");

                          return 0 ;
                          break;
                          case 1:
                          break;
                          case 2:
                          PrefixEvaluation();
                          break;
                          default:
                            printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");


                        }
                      } while(j!=0);
                        break;
                        case 0:
                        printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");
                        return 0;
                        break;
                        default:
                         printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");
                         break;
                      }

                    }while(c!=0);
                   break;
               case 0:
               printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n ");
               return 0;
                   break;
               default:
                   printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");

           }
         }while(c!=0);
        }
