// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 5

// Write a C program to implement queue using linked list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


bool valid = 1; //used for validation purpose only
char temp[100];



struct node
{
	int data;
	struct node * next;
};

struct node * front = NULL; // point to front node (head)
struct node * rear = NULL; // point to rear node (tail)
struct node * newnode;



void enqueue(int item)
{

	newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> data = item;
	newnode -> next = NULL;
	// assigned next pointer to null of the each node inserted 
	if(front == NULL)
	{
		front = rear = newnode;
	// for first node , front and rear will point to first node 
	}
	else
	{
		rear->next = newnode; // for next nodes 
		rear = newnode;		
	}

}


void dequeue()
{
	if(front == NULL)
	{
		printf("\nQueue is empty !");
		return;
	}
	printf("\nDeleted element is %d", front->data);
	if(front == rear)
	{
		free(front);
		front = rear = NULL;
		return;
	}
	struct node *temp;
	temp = front ->next;
	free(front);
	front = temp; 

}

void peek_front()
{
	if(front == NULL)
	{
		printf("\nQueue is Empty.");
		return;
	}
	
	printf("\nElement at front is %d" , front->data);
}

void peek_rear()
{
	if(front == NULL)
	{
		printf("\nQueue is Empty.");
		return;
	}
	
	printf("\nElement at rear is %d" , rear->data);
}

void display()
{
	if(front == NULL)
	{
		printf("\nQueue is empty !");
		return;
	}
	
	struct node * ptr;
	printf("\nDisplaying List elements...(front to rear)\n");
	for(ptr = front ; ptr != NULL ;ptr=ptr->next)
	{
		printf("%d\t",ptr-> data);	 
	}
}

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
	int item ;
	while(ch != 6)	
	{
		do
 		{
 			printf("\n\nMain Menu ");
			printf("\n\n1.Insert\n2.Delete\n3.See Front\n4.See Rear\n5.Display\n6.Exit");
			printf("\n\nEnter your choice :");
 			fflush(stdin);
			gets(temp);
    		ch = validint(temp);
    	
 		}while(valid==0);
 	

		switch(ch)
		{
			
			case 1: {
						do
 						{
 							printf("\nEnter element to insert :");
 							fflush(stdin);
							gets(temp);
    						item = validint(temp);
 						}while(valid==0);
 						
 						enqueue(item);
					break;
			}		
			case 2: {
						dequeue();
					break;
			}		
			case 3: {
						peek_front();
				break;
			}
			case 4: {
						peek_rear();
				break;
			}
			case 5: 	display();
				break;
			case 6: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	
return 0;
}
