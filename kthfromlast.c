
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;
void main()
{
	printKthFromLast(*head,k);
}
void printKthFromLast(struct node *head, int k)
{
    int len = 0, i;
    struct node *temp = head;
 
    // 1) count the number of nodes in Linked List
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
 
    // check if value of k is not more than length of the linked list
    if (len < k)
      return;
 
    temp = head;
 
    // 2) get the (len-k+1)th node from the begining
    for (i = 1; i < len-k+1; i++)
       temp = temp->next;
 
    printf ("%d", temp->data);
 
    return;
}
