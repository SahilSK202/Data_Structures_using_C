// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 4

// Write a C program to implement stack using linked list.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node * p_next;
};

struct node * top = NULL; // point to top node
struct node * head = NULL; // point to head node
struct node * newnode;

void push(int item)
{
	
	
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> data = item;
	newnode -> p_next = NULL;
	// assigned next pointer to null of the each node inserted 
	if(head == NULL)
	{
		head = top = newnode;
	// for first node , head and top will point to first node 
	}
	else// for further nodes
	{
		top->p_next = newnode;  
		top = newnode;		
	}
}


void pop()
{
	if(top == NULL) 
	{
		printf("\nStack is Empty.");
		return;
	}
	if(top == head) // one element in stack.
	{
		printf("\nDeleted element is %d", head->data);
		free(head);
		top = head = NULL;
		return;
	}

	struct node *temp1 , *temp2;
	
	// traverse to top
	
	temp1 = head; // starts from head (to access second last elt)
	temp2 = head->p_next; // starts from head + 1  
	
	while(temp2 != top) // or temp2->p_next != NULL
	{
		temp1=temp1->p_next; // reaches to top - 1
		temp2=temp2->p_next; // reaches to top
	}
	
	printf("\nDeleted element is %d", temp2->data);
	free(temp2);
	temp1->p_next = NULL;
	top = temp1; 
	
}

void display()
{
	if(top == NULL)
	{
		printf("\nStack is Empty.");
		return;
	}
	
	struct node * ptr;
	printf("\nDisplaying stack elements...\n\n");
	for(ptr = head ; ptr != NULL ;ptr=ptr->p_next)
	{
		printf("%d\t",ptr-> data);	 
	}

}

void peek()
{
	if(top == NULL)
	{
		printf("\nStack is Empty.");
		return;
	}
	
	printf("\nTop element is %d" , top->data);
}

bool valid = 1; //used for validation purpose only
char temp[100];
//function to validate integer value.

int validint(char temp[])
{
	valid = 1;
	int i;
	for( i = 0 ; i < strlen(temp) ; i++)
	{
		if(temp[0] == '-') continue;
		if(!isdigit(temp[i]))
		{
			printf("\nInvalid input !");
			valid = 0;
			return;
		}
	}
	
	if(strlen(temp) <= 0)
	{
		printf("\nEmpty Input !");
		valid = 0;
		return;
	}
	int integer;
	
	integer = atoi(temp);
	return integer ;
	
}	





int main()
{
	int ch;
	int item;
	while(ch != 5)	
	{
	do
 	{
 		printf("\n\n Menu ");
		printf("\n\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit");
		printf("\n\nEnter your choice :");
 		fflush(stdin);
		gets(temp);
    	ch = validint(temp);
    
 	}while(valid==0 );

		
		switch(ch)
		{
			case 1: do
 					{
 						printf("\nEnter element to insert :");
 						fflush(stdin);
						gets(temp);
    					item = validint(temp);
 					}while(valid==0);
					
					push(item);
					break;
			case 2: pop();
					break;
			case 3: peek();
					break;
			case 4: display();
					break;
			case 5: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	return 0;
}
