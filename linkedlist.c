#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
}*start=NULL;

void create()
{
char ch;
 do
 {
  struct node *new_node,*current;

  new_node=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the data: ");
  scanf("%d",&new_node->data);
  new_node->next=NULL;

  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }
 printf("\nDo you want to create another: ");
 fflush(stdin);
 printf("If you wish to stop enter \'n\'");
scanf("%c",&ch);
 }while(ch!='n');
}

void display()
{
struct node *new_node;
 printf("The Linked List : \n");
 new_node=start;
 int count;
  printf("START->");
 while(new_node!=NULL)
   {
   printf("%d->",new_node->data);
   new_node=new_node->next;
   count++;
   }
  printf("NULL");
  printf("\nThe number of nodes in linked list are: %d",count);
}

void main()
{
create();
display();
}
