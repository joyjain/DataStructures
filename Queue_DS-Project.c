#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX 10
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
void Linearqueue();
void Deques();
void Priorityqueue();
void Josephusproblem();

int main()
{
	printf(BOLD BLK  "=================================================    QUEUES    ===================================================================================\n" RESET RESET);
	printf("PRESS 1 FOR : INTRODUCTION\nPRESS 2 FOR : APPLICATIONS\nPRESS 0 TO : EXIT\n");
	int c ;
	do
	{
		printf("ENTER YOUR OPTION: ");
			scanf("%d",&c);
        switch(c)
        {
            case 1: printf(BOLD "------------ INTRODUCTION TO QUEUES --------------- \n"RESET);
                    printf("Queue is an important data structure which is extensively used in computer applications. It\n");
                    printf("is a FIFO(First-In,First-Out) data structure in which the element that is inserted first is\n");
                    printf("the first one to be taken out. The elements in a queue are added at one end called the REAR\n");
                    printf("and removed from the other end called the FRONT. Queues can be implemented by using either \n");
                    printf("arrays or linked lists. \n");
                    printf("There are four types of queues namely Circular queue,Deque,Priority queue and Multiple queue.\n");
                    printf("While insertion,it is said to be in Overflow state when it is completely full and while      \n");
                    printf(" deletion of an element, it is said to be in Underflow state if it is completely empty.\n");
                    break;
            case 2: printf("\n\n---------------- APPLICATIONS OF QUEUES ------------------\n\n ");
                    printf("Queue can also be implemented using Stacks.\n");
                    printf("One of the applications of queues is Josephus problem.\n");
                    printf("PRESS 1 FOR : LINEAR QUEUE \n");
                    printf("PRESS 2 FOR : DEQUE \n");
                    printf("PRESS 3 FOR : PRIORITY QUEUE \n");
                    printf("PRESS 4 FOR : JOSEPHUS PROBLEM \n");
                    printf("PRESS 0 TO  : EXIT\n");
                    int d;
                    do
					{
                    	printf("ENTER YOUR OPTION ");
                    		scanf("%d",&d);
                    	switch(d)
                      	{
                        	case 1:	printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                        			printf("\n PRESS 2 TO: RUN THE SOURCE CODE\n\n ");
                    				printf("PRESS 0 TO EXIT\n");
                    				int e;
                        			do
									{
                    					scanf("%d",&e);
                        				switch (e)
                        				{
                          					case 0: printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");
													return 0 ;
                          							break;
                          					case 1: break;
                          					case 2: Linearqueue();
                          							break;
                          					default:printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");
										}
                      				}while(e!=0);
									break;
                        	case 2: printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         			printf("\n PRESS 2 TO: RUN THE SOURCE CODE\n\n ");
                         			printf("PRESS 0 TO EXIT\n");
                          			int f;
									do
									{
                        				scanf("%d",&f);
                        				switch (f)
                        				{
                          					case 0: printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");
													return 0 ;
                          							break;
                          					case 1: break;
                          					case 2: Deques();
													break;
                          					default:printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");
										}
                      				}while(f!=0);
                      				break;
                        	case 3: printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         			printf("\n PRESS 2 TO: RUN THE SOURCE CODE \n\n");
                         			printf("PRESS 0 TO EXIT\n");
                         			int g;
                        			do
									{
                          				scanf("%d",&g);
                        				switch (g)
                        				{
                          					case 0: printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");
											  		return 0 ;
                          							break;
                          					case 1: break;
                          					case 2: Priorityqueue();
                          							break;
                          					default:printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");
										}
                          			}while(g!=0);
                      				break;
                        	case 4: printf("\n PRESS 1 TO : DISPLAY THE SOURCE CODE FOR THE PROGRAM  ");
                         			printf("\n PRESS 2 TO: RUN THE SOURCE CODE\n\n ");
                         			printf("PRESS 0 TO EXIT\n");
                         			int h ;
                        			do
									{
										scanf("%d",&h);
                        				switch (h)
                        				{
                          					case 0: printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");
											  		return 0 ;
                          							break;
                          					case 1: break;
                          					case 2:	Josephusproblem();
                          							break;
                          					default:printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");
										}
                      				}while(h!=0);
                       				break;
                    			case 0: printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n");
                        				return 0;
                        				break;
                        		default:printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");
                         				break;
                    	}
					}while(c!=0);
                   break;
            case 0: printf("THANKS FOR USING THIS PROGRAM , GOODBYE \n\n ");
               		return 0;
                   	break;
            default:printf("\nInvalid Choice\n Please try again or press 0 to EXIT \n\n");
		}
	}while(c!=0);
}

void Linearqueue()
{
	int MAX=10;
	int queue[MAX];
	int rear=-1,front=-1;
	void insert1(void);
	int delete1(void);
	int peek1(void);
	void display1(void);
	int main()
	{
		int option,val;
		do
		{
			printf("\n *****MAIN MENU*****");
			printf("\n 1.Insert an element");
			printf("\n 2.Delete an element");
			printf("\n 3.Peek");
			printf("\n 4.Display the queue");
			printf("\n 5.EXIT");
			printf("\n Enter the option:");
				scanf("%d",&option);
			switch(option)
			{
				case 1: insert1();
						break;
				case 2: val= delete1();
						if(val!= -1)
							printf("\n The number deleted is : %d",val);
						break;
				case 3: val= peek1();
						if(val!= -1)
							printf("\n The first value in queue is : %d", val);
						break;
				case 4: display1();
						break;
			}
		}while(option != 5);
		getch();
		return 0;
	}
	void insert1()
	{
		int num;
		printf("\n Enter the number to be inserted in the queue :");
			scanf("%d", &num);
		if(rear ==MAX-1)
			printf("\n OVERFLOW");
		else if(front==-1 && rear==-1)
			front=rear=0;
		else
			rear++;
		queue[rear]=num;
	}
	int delete1()
	{
		int val;
		if(front==-1 || front>rear)
		{
			printf("\n UNDERFLOW");
			return -1;
		}
		else
		{
			val=queue[front];
			front++;
			if(front>rear)
				front=rear=-1;
			return val;
		}
	}
	int peek1()
	{
		if(front==-1 || front>rear)
		{
			printf("\n QUEUE IS EMPTY");
			return -1;
		}
		else
		{
			return queue[front];
		}
	}
	void display1()
	{
		int i;
		printf("\n");
		if(front==-1 || front>rear)
			printf("\n QUEUE IS EMPTY");
		else
		{
			for(i=front;i<=rear;i++)
				printf("\t %d", queue[i]);
		}
	}
}
void Deques()
{
	int deque[MAX];
	int left=-1, right=-1;
	void inputdeque(void);
	void outputdeque(void);
	void insertleft(void);
	void insertright(void);
	void deleteleft(void);
	void deleteright(void);
	void display2(void);
	int main()
	{
		int option;
		printf("\n 1. Input restricted deque");
		printf("\n 2. Output rstricted deque");
		printf("\n Enter your option");
			scanf("%d", &option);
		switch(option)
		{
			case 1: inputdeque();
					break;
			case 2: outputdeque();
					break;
		}
		return 0;
	}
	void inputdeque()
	{
		int option;
		do
		{
			printf("\n INPUT RESTRICTED DEQUE");
			printf("\n 1.Insert at right");
			printf("\n 2.Delete from left");
			printf("\n 3.Delete from right");
			printf("\n 4.Display");
			printf("\n 5.Quit");
			printf("\n Enter the option :");
				scanf("%d",&option);
			switch(option)
			{
				case 1: insertright();
						break;
				case 2: deleteleft();
						break;
				case 3: deleteright();
						break;
				case 4: display2();
						break;
			}
		}while(option!=5);
	}
	void outputdeque()
	{
		int option;
		do
		{
			printf("\n OUTPUT RESTRICTED DEQUE");
			printf("\n 1.Insert at right");
			printf("\n 2.Delete at left");
			printf("\n 3.Delete from left");
			printf("\n 4.Display");
			printf("\n 5.Quit");
			printf("\n Enter the option :");
				scanf("%d",&option);
			switch(option)
			{
				case 1: insertright();
						break;
				case 2: insertleft();
						break;
				case 3: deleteleft();
						break;
				case 4: display2();
						break;
			}
		}while(option!=5);
	}
	void insertright()
	{
		int val;
		printf("\n Enter the vale to be added :");
			scanf("%d", &val);
		if(left == 0 && right == MAX-1 || (left==right+1))
		{
			printf("\n OVERFLOW");
			return;
		}
		else if(left ==-1) //if queue is initially empty
		{
			left=0;
			right=0;
		}
		else
		{
			if(right == MAX-1)
				right=0;
			else
				right=right +1;
		}
		deque[right]=val;
	}
	void insertleft()
	{
		int val;
		printf("\n Enter the vale to be added :");
			scanf("%d", &val);
		if(left == 0 && right == MAX-1 || (left==right+1))
		{
			printf("\n OVERFLOW");
			return;
		}
		else if(left ==-1) //if queue is initially empty
		{
			left=0;
			right=0;
		}
		else
		{
			if(left==0)
				left=MAX-1;
			else
				left=left-1;
		}
		deque[left]=val;
	}
	void deleteleft()
	{
		if(left==-1)
		{
			printf("\n UNDERFLOW");
			return;
		}
		printf("\n Deleted element is : %d",deque[left]);
		if(left==right)  //queue has only one element
		{
			left=-1;
			right=-1;
		}
		else
		{
			if(left ==MAX-1)
				left=0;
			else
				left=left+1;
		}
	}
	void deleteright()
	{
		if(left==-1)
		{
			printf("\n UNDERFLOW");
			return;
		}
		printf("\n Deleted element is : %d",deque[right]);
		if(left==right)  //queue has only one element
		{
			left=-1;
			right=-1;
		}
		else
		{
			if(right ==0)
				right=MAX-1;
			else
				right=right+1;
		}
	}
	void display2()
	{
		int front=left, rear=right;
		if(front==-1)
		{
			printf("\n QUEUE IS EMPTY");
			return;
		}
		printf("\n The elements of the queue are :");
		if(front<=rear)
		{
			while(front<=rear)
			{
				printf("%d",deque[front]);
				front++;
			}
		}
		else
		{
			while(front<=MAX-1)
			{
				printf("%d",deque[front]);
				front++;
			}
			front=0;
			while(front<=rear)
			{
				printf("%d",deque[front]);
				front++;
			}
		}
		printf("\n");
	}
}


void Priorityqueue()
{
	struct node{
	int data;
	int priority;
	struct node *next;
	};
	struct node *start=NULL;
	struct node *insert(struct node *);
	struct node *delete(struct node *);
	void display(struct node *);
	int main()
	{
		int option;
		do
		{
			printf("\n *****MAIN MENU*****");
			printf("\n 1.Insert");
			printf("\n 2.Delete");
			printf("\n 3.Display");
			printf("\n 4.EXIT");
			printf("\n Enter your option");
				scanf("%d", &option);
			switch(option)
			{
				case 1: start=insert(start);
						break;
				case 2: start=delete(start);
						break;
				case 3: display(start);
						break;
			}
		}while(option!=4);
	}
	struct node *insert(struct node *start)
	{
		int val,pri;
		struct node *ptr,*p;
		ptr= (struct  node *)malloc(sizeof(struct node));
		printf("\n Enter the value and its priority :");
			scanf("%d %d", &val,&pri);
		ptr->data=val;
		ptr->priority=pri;
		if(start==NULL || pri<start->priority)
		{
			ptr->next=start;
			start=ptr;
		}
		else
		{
			p=start;
			while(p->next!=NULL && p->next->priority <= pri)
				p=p->next;
			ptr->next=p->next;
			p->next =ptr;
		}
		return start;
	}
	struct node *delete(struct node *start)
	{
		struct node *ptr;
		if(start == NULL)
		{
			printf("\n UNDERFLOW");
			return;
		}
		else
		{
			ptr=start;
			printf("\n Deleted item is: %d",ptr->data);
			start=start->next;
			free(ptr);
		}
		return start;
	}
	void display(struct node *start)
	{
		struct node *ptr;
		ptr=start;
		if(start==NULL)
			printf("\n QUEUE IS EMPTY");
		else
		{
			printf("\n PRIORITY QUEUE IS:");
			while(ptr!=NULL)
			{
				printf("\t%d [priority=%d]",ptr->data,ptr->priority);
				ptr=ptr->next;
			}
		}
	}
}
void Josephusproblem()
{
	struct node{
	int playerid;
	struct node *next;
	};
	struct node *start,*ptr,*newnode;
	int main()
	{
		int n,k,i,count;
		printf("\n Enter the number of players");
			scanf("%d",&n);
		printf("\n Enter the value of k (every kth player gets eliminated)");
			scanf("%d",&k);
		//create circular linked list containing all players
		start=malloc(sizeof(struct node));
		start->playerid=1;
		ptr=start;
		for(i=2;i<=n;i++)
		{
			newnode=malloc(sizeof(struct node));
			ptr->next=newnode;
			newnode->playerid=i;
			newnode->next=start;
			ptr=newnode;
		}
		for(count=n;count>1;count--)
		{
			for(i=0;i<k-1;++i)
				ptr=ptr->next;
			ptr->next=ptr->next->next; //remove the eliminated player
		}
		printf("\n The winner is player %d", ptr->playerid);
		getche();
		return 0;
	}
}
