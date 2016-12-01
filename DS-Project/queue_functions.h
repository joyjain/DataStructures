// queue_functions.h

// Prototypes
void Linearqueue1();
void insert1();
int delete1();
int peek1();
void display1();

void Deques2();
void inputdeque2();
void outputdeque2();
void insertleft2();
void insertright2();
void deleteleft2();
void deleteright2();
void display2();

void Priorityqueue3();
struct queue *insert3(struct queue *);
struct queue *delete3(struct queue *);
void display3(struct queue *);

void Josephusproblem4();

struct queue
{
	int data, priority;
	struct queue *next;
};

struct queue *start_q = NULL;

int rear=-1, front=-1;
int left=-1, right=-1;
int queue[MAX], deque[MAX];

//LINEAR QUEUE

void Linearqueue1()
{
	int option,val;
  printf("\n\t\t\t\t\t\t\t\t\t*****MAIN MENU*****");
  printf("\n\t\t\t\t\t\t\t\t\t1.Insert an element");
  printf("\n\t\t\t\t\t\t\t\t\t2.Delete an element");
  printf("\n\t\t\t\t\t\t\t\t\t3.Peek");
  printf("\n\t\t\t\t\t\t\t\t\t4.Display the queue");
  printf("\n\t\t\t\t\t\t\t\t\t5.TO STOP\n");
	do
	{
		printf("\n\t\t\t\t\t\t\t\t\tEnter the option: ");
			scanf("%d",&option);
		switch(option)
		{
			case 1: insert1();
					break;
			case 2: val= delete1();
					if(val!= -1)
						printf("\n\t\t\t\t\t\t\t\t\tThe number deleted is : %d",val);
					break;
			case 3: val= peek1();
					if(val!= -1)
						printf("\n\t\t\t\t\t\t\t\t\tThe first value in queue is : %d", val);
					break;
			case 4: display1();
					break;
      case 5:
          break;
      default:
          printf("OPTION DOESN\'T EXIST TRY AGAIN");
		}
	}while(option!= 5);
}

void insert1()
{
	int num;
	printf("\n\t\t\t\t\t\t\t    Enter the number to be inserted in the queue :");
		scanf("%d", &num);
	if(rear ==MAX-1)
		printf("\n\t\t\t\t\t\t\t\t\tOVERFLOW");
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
		printf("\n\t\t\t\t\t\t\t\t\tUNDERFLOW");
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
		printf("\n\t\t\t\t\t\t\t\t\tQUEUE IS EMPTY");
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
		printf("\n\t\t\t\t\t\t\t\t\tQUEUE IS EMPTY");
	else
	{
		for(i=front;i<=rear;i++)
			printf("\t %d", queue[i]);
	}
}

// DEQUES
void Deques2()
{
	int option;
	printf("\n\t\t\t\t\t\t\t\t\t1. Input restricted deque");
	printf("\n\t\t\t\t\t\t\t\t\t2. Output restricted deque");
	printf("\n\t\t\t\t\t\t\t\t\t   Enter your option: ");
	scanf("%d", &option);
	switch(option)
	{
		case 1: inputdeque2();
				break;
		case 2: outputdeque2();
				break;
	}
}

void inputdeque2()
{
  printf("\n\t\t\t\t\t\t\t\t\tINPUT RESTRICTED DEQUE");
  printf("\n\t\t\t\t\t\t\t\t\t1.Insert at right");
  printf("\n\t\t\t\t\t\t\t\t\t2.Delete from left");
  printf("\n\t\t\t\t\t\t\t\t\t3.Delete from right");
  printf("\n\t\t\t\t\t\t\t\t\t4.Display");
  printf("\n\t\t\t\t\t\t\t\t\t5.Quit");
	int option;
	do
	{
		printf("\n\t\t\t\t\t\t\t\t\t   Enter the option: ");
			scanf("%d",&option);
		switch(option)
		{
			case 1: insertright2();
					break;
			case 2: deleteleft2();
					break;
			case 3: deleteright2();
					break;
			case 4: display2();
					break;
      case 5:
          break;
      default:
          printf("\n\t\t\t\t\t\t\t\t\tOPTION DOESN\'T EXIST TRY AGAIN");
		}
	}while(option!=5);
}

void outputdeque2()
{
  printf("\n\t\t\t\t\t\t\t\t\tOUTPUT RESTRICTED DEQUE");
  printf("\n\t\t\t\t\t\t\t\t\t1.Insert at right");
  printf("\n\t\t\t\t\t\t\t\t\t2.Delete at left");
  printf("\n\t\t\t\t\t\t\t\t\t3.Delete from left");
  printf("\n\t\t\t\t\t\t\t\t\t4.Display");
  printf("\n\t\t\t\t\t\t\t\t\t5.Quit");
	int option;
	do
	{
		printf("\n\t\t\t\t\t\t\t\t\t   Enter the option: ");
			scanf("%d",&option);
		switch(option)
		{
			case 1: insertright2();
					break;
			case 2: insertleft2();
					break;
			case 3: deleteleft2();
					break;
			case 4: display2();
					break;
      case 5:
          break;
      default:
          printf("\n\t\t\t\t\t\t\t\t\tOPTION DOESN\'T EXIST TRY AGAIN");
		}
	}while(option!=5);
}

void insertright2()
{
	int val;
	printf("\n\t\t\t\t\t\t\t\t\t   Enter the value to be added :");
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

void insertleft2()
{
	int val;
	printf("\n\t\t\t\t\t\t\t\t\t   Enter the value to be added :");
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

void deleteleft2()
{
	if(left==-1)
	{
		printf("\n\t\t\t\t\t\t\t\t\t   UNDERFLOW");
		return;
	}
	printf("\n\t\t\t\t\t\t\t\t\t   Deleted element is : %d",deque[left]);
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

void deleteright2()
{
	if(left==-1)
	{
		printf("\n\t\t\t\t\t\t\t\t\t   UNDERFLOW");
		return;
	}
	printf("\n\t\t\t\t\t\t\t\t\t   Deleted element is : %d",deque[right]);
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
		printf("\n\t\t\t\t\t\t\t\t\t   QUEUE IS EMPTY");
		return;
	}
	printf("\n\t\t\t\t\t\t\t\t\t   The elements of the queue are :");
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

//PRIORITY QUEUE
void Priorityqueue3()
{
  printf("\n\t\t\t\t\t\t\t\t\t   *****MAIN MENU*****");
  printf("\n\t\t\t\t\t\t\t\t\t        1.Insert");
  printf("\n\t\t\t\t\t\t\t\t\t        2.Delete");
  printf("\n\t\t\t\t\t\t\t\t\t        3.Display");
  printf("\n\t\t\t\t\t\t\t\t\t        4.TO STOP");
	int option;
	do
	{
    printf("\n\t\t\t\t\t\t\t\t\tEnter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
        start_q = insert3(start_q);
				break;
			case 2:
        start_q = delete3(start_q);
				break;
			case 3:
        display3(start_q);
				break;
      case 4:
        break;
      default:
        printf("\n\t\t\t\t\t\t\t\t\tOPTION DOESN\'T EXIST TRY AGAIN");
		}
	}while(option!=4);
}

struct queue *insert3(struct queue *start_q)
{
	int val,pri;
	struct queue *ptr,*p;
	ptr= (struct  queue *)malloc(sizeof(struct queue));
	printf("\n\t\t\t\t\t\t\t\t\tEnter the value and its priority :");
		scanf("%d %d", &val,&pri);
	ptr->data=val;
	ptr->priority=pri;
	if(start_q==NULL || pri<start_q->priority)
	{
		ptr->next=start_q;
		start_q=ptr;
	}
	else
	{
		p=start_q;
		while(p->next!=NULL && p->next->priority <= pri)
			p=p->next;
		ptr->next=p->next;
		p->next =ptr;
	}
	return start_q;
}

struct queue *delete3(struct queue *start_q)
{
	struct queue *ptr;
	if(start_q == NULL)
	{
		printf("\n\t\t\t\t\t\t\t\t\tUNDERFLOW");
	}
	else
	{
		ptr=start_q;
		printf("\n\t\t\t\t\t\t\t\t\tDeleted item is: %d",ptr->data);
		start_q = start_q->next;
		free(ptr);
	}
	return start_q;
}

void display3(struct queue *start_q)
{
	struct queue *ptr;
	ptr=start_q;
	if(start_q==NULL)
		printf("\n\t\t\t\t\t\t\t\t\tQUEUE IS EMPTY");
	else
	{
		printf("\n\t\t\t\t\t\t\t\t\tPRIORITY QUEUE IS:");
		while(ptr!=NULL)
		{
			printf("\t%d [priority=%d]",ptr->data,ptr->priority);
			ptr=ptr->next;
		}
	}
}

// JOSEPHUS PROBLEM
void Josephusproblem4()
{

	struct josephus
  {
	int playerid;
	struct josephus *next;
	};

	struct josephus *start4,*ptr,*newnode;
	int n,k,i,count;
	printf("\n\t\t\t\t\t\t\t\t\tEnter the number of players: ");
	scanf("%d",&n);
	printf("\n\t\t\t\t\t\t\tEnter the value of k (every kth player gets eliminated): ");
	scanf("%d",&k);
	// Create circular linked list containing all players
	start4 = (struct josephus *)malloc(sizeof(struct josephus));
	start4->playerid = 1;
	ptr = start4;
	for(i=2;i<=n;i++)
	{
		newnode = (struct josephus *)malloc(sizeof(struct josephus));
		ptr->next = newnode;
		newnode->playerid = i;
		newnode->next = start4;
		ptr=newnode;
	}
	for(count=n;count>1;count--)
	{
		for(i=0;i<k-1;++i)
			ptr = ptr->next;
		ptr->next = ptr->next->next; // Remove the eliminated player
	}
	printf("\n\t\t\t\t\t\t\t\t\t     The winner is player %d", ptr->playerid);
}
