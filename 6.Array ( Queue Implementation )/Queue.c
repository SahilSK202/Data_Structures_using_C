// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 6

// Write a C program to implement Queue using array.




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 100

bool valid = 1; //used for validation purpose only
char temp[100];

int Queue[MAX] ,front = -1,rear = -1 , n;


int isFull()
{
	if(rear == n-1)
	{
		return 1;	
	}
	else
	{
		return 0;
	}
	
}

int isEmpty()
{
	if(front == -1 && rear == -1) // If Queue is empty
	{
		return 1;	
	}
	else
	{
		return 0;
	}
	
}

void enqueue( int val)
{
	
	if(isFull())
	{
		printf("\nQueue is full!!");	
	}
	else if(front == -1 && rear == -1) // If Queue is empty
	{
		front = rear = 0;
		Queue[rear]=val;
	}
	else
	{	
		rear++;
		Queue[rear]=val;
	}
}

void dequeue()
{
	if(isEmpty())
	{
		printf("\nQueue is empty!!");
	}
	else if(front == rear)// if one element left.
	{
		printf("\nDeleted element is %d",Queue[front]);
		front = rear = -1;
	}
	else
	{
		printf("\nDeleted element is %d",Queue[front]);
		front++;
	}
}



void peek_front()
{
	if(isEmpty())
	{
		printf("\nQueue is empty!!");
	}
	else
		printf("Element at front is %d" , Queue[front]);
}


void peek_rear()
{
	if(isEmpty())
	{
		printf("\nQueue is empty!!");
	}
	else
		printf("Element at rear is %d" , Queue[rear]);
}

 
void display()
{
	if(isEmpty())
	{
		printf("\nQueue is empty!!");
	}
	else
	{
		int i;
		printf("\nQueue is...\n");
		for(i=front;i<=rear;i++)
			printf("%d\t",Queue[i]);
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
	int ch ,val ;
	
	printf("Enter the size of Queue : ");
	scanf("%d" , &n);
	//int Queue[n];
	
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
			case 1: do
 					{
 						printf("\nEnter element to insert :");
 						fflush(stdin);
						gets(temp);
    					val = validint(temp);
 					}while(valid==0);
					enqueue(val);
					break;
			case 2: dequeue();
					break;
			case 3: peek_front();
					break;
			case 4: peek_rear();
					break;
			case 5: display();
					break;
			case 6: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	return 0;
}
