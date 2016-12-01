#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node_type
{
    int data;
    struct node_type *next;
}node;

node *start = NULL;

void main()
{
    node *new_node, *ptr, *slow_ptr, *fast_ptr;
    int i, n, value, k, count=0;
    printf("Enter the number of nodes in your ll: ");
    scanf("%d", &n);
    printf("Enter the value of kth node to find from last: ");
    scanf("%d", &k);
    for(i=0;i<n;i++)
    {
        new_node = malloc(sizeof(node));
        scanf("%d",&value);
        new_node->data = value;
        if(start==NULL)
        {
            new_node->next = NULL;
            start = new_node;
            fast_ptr = start;
            slow_ptr = start;
        }

        else
        {
            ptr = start;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            new_node->next = NULL;
            ptr->next = new_node;
            ptr = new_node;
        }
        if(i<k)
        {
          fast_ptr = ptr;
        }
        else
        {
            fast_ptr = ptr;
            slow_ptr = slow_ptr->next;
        }
        count++;
    }
    printf("The kth element from last is %d",slow_ptr->data);
}
