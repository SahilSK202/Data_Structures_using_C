// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 8

// Write a C program to implement Double Ended Queue using array.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 100


bool valid = 1; //used for validation purpose only
char temp[100];



int DEQueue[MAX] ,front = -1,rear = -1 , n;


int isFull()
{
	if((rear + 1)%n == front)
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

void enqueueFront( int val)
{
	
	if(isFull())
	{
		printf("\nQueue is full!!");
		return;	
	}
	else if(isEmpty()) // If Queue is empty
	{
		front = rear = 0;	
	}
	else
	{	
		if(front == 0)
		front = n-1;
		else
		front = front-1; 
	}
	DEQueue[front]=val;
}

void enqueueRear( int val)
{
	
	if(isFull())
	{
		printf("\nQueue is full!!");
		return;	
	}
	else if(isEmpty()) // If Queue is empty
	{
		front = rear = 0;	
	}
	else
	{	
		rear = (rear+1)%n; 
	}
	DEQueue[rear]=val;
}

void dequeueFront()
{
	if(isEmpty()) // If Queue is empty
	{
		printf("\nQueue is empty!!");
		return;
	}
	
	printf("\nDeleted element from front is %d",DEQueue[front]);
	
	 if(front == rear) // if one element left.
	{
		front = rear = -1;
	}
	else
	{
		front = (front+1)%n;
	}
}

void dequeueRear()
{
	if(isEmpty()) // If Queue is empty
	{
		printf("\nQueue is empty!!");
		return;
	}
	
	printf("\nDeleted element from rear is %d",DEQueue[rear]);
	
	if(front == rear) // if one element left.
	{
		front = rear = -1;
	}
	else
	{
		if(rear == 0)
		rear = n-1;
		else
		rear = rear-1;
	}
}

int getFront()
{
	if(isEmpty()) // If Queue is empty
	{
		printf("\nQueue is empty!!");
	}
	else
		return DEQueue[front];
}


int getRear()
{
	if(isEmpty()) // If Queue is empty
	{
		printf("\nQueue is empty!!");
	}
	else
		return DEQueue[rear];
}
 
void display()
{
	if(isEmpty()) // If Queue is empty
	{
		printf("\nQueue is empty!!");
	}
	else
	{
		int i;
		printf("\nDEQueue is .....\n\n");
		for(i = (front) ; i != rear ; i=(i+1)%n)
		{
			printf("%d\t",DEQueue[i]);
		}
		printf("%d",DEQueue[i]);
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
	int val , ch ;

	do
 	{
 		printf("\nEnter the size of DEQueue : ");
 		fflush(stdin);
		gets(temp);
    	n = validint(temp);
 	}while(valid==0 || n < 1);
	

	while(ch != 8 )	
	{
		do
 		{
		 	printf("\n\n**********\tMenu\t*********** ");
			printf("\n\n1.Insert from front\t2.Insert from rear\n3.Delete from front\t4.Delete from rear\n5.Get front\t\t6.Get rear\n7.Display\t\t8.Exit");
			printf("\n\nEnter your choice :");
 			fflush(stdin);
			gets(temp);
    		ch = validint(temp);
    	
 		}while(valid==0);
		
		switch(ch)
		{
			case 1: do
 					{
 						printf("\nEnter element to insert at front :");
 						fflush(stdin);
						gets(temp);
    					val = validint(temp);
 					}while(valid==0);
 					
					enqueueFront(val);
					break;
			case 2: do
 					{
 						printf("\nEnter element to insert at rear :");
 						fflush(stdin);
						gets(temp);
    					val = validint(temp);
 					}while(valid==0);
 					
					enqueueRear(val);
					break;
			case 3: dequeueFront();
					break;
			case 4: dequeueRear();
					break;
			case 5: printf("\nElement at front is %d" , getFront());
					break;
			case 6: printf("\nElement at rear is %d" , getRear());
					break;
			case 7: display();
					break;
			case 8: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	return 0;
}

