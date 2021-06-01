// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 12

//C program to implement doubly Circular linked list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


bool valid = 1; //used for validation purpose only
char temp[100];

struct node
{
	int data;
	struct node * p_next;
	struct node * p_prev;

};

struct node * head = NULL; // point to head node
struct node * tail = NULL; // point to end node
struct node * newnode;



void createDLL()
{
	int ch1 = 0;
					
	int item;
	do{
	printf("\nEnter element to insert :");
	scanf("%d",&item);
	
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> data = item;
	
	 
	if(head == NULL)
	{
		head = tail = newnode;
		newnode -> p_next = NULL;
		newnode -> p_prev = NULL;
		// for first node , head and tail will point to first node 
	}
	else
	{
		tail->p_next = newnode; // for next nodes 
		newnode ->p_prev = tail;
		newnode ->p_next = head;
		head ->p_prev = newnode;
		tail = newnode;		
	}
	printf("\nElement added !");
	printf("\n\nEnter 1 to add more elements.\nEnter 2 for Main Menu. \n : ");
	scanf("%d",&ch1);
	}while(ch1 == 1);
}


void insert_beg(int item)
{
	if(head == NULL)
	{
		printf("\nCreate list first !");
		return;
	}
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> data = item;
	
	head->p_prev = newnode;
	newnode -> p_next = head;
	newnode -> p_prev = tail;
	head = newnode; 
	tail->p_next = head;

}

void insert_end(int item)
{
	if(head == NULL)
	{
		printf("\nCreate list first !");
		return;
	}
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> data = item;
	newnode -> p_next = head;
	newnode -> p_prev = tail;
	tail -> p_next = newnode;
	tail = newnode;
	head->p_prev = tail;
	
}

void insert_pos(int pos,int item) 
{
	
	if(head == NULL)
	{
		printf("\nCreate list first !");
		return;
	}
	if(pos == 1)
	{
		insert_beg(item);
	}
	else // traverse to pos-1
	{
		struct node * temp;
		int count2 = 1;
		newnode = (struct node*) malloc(sizeof(struct node));
		newnode -> data = item;
		temp = head;
		
		while(count2 < pos-1)
		{
			temp=temp->p_next;
			count2++;
		}
		if(temp == tail)
		{
			insert_end(item);
		}
		else
		{
		newnode -> p_next = temp->p_next;
		newnode -> p_prev = temp;
		temp->p_next ->p_prev = newnode; 
		temp->p_next = newnode; 
		}
	}
	

}


void delete_beg()
{
	
	if(head == NULL)
	{
		printf("\nList is Empty.");
		return;
	}
	if(head == tail)
	{
		printf("\nDeleted element is %d", head->data);
		head = tail = NULL;
		return;
	}
	
	head = head->p_next;
	printf("\nDeleted element is %d", head->p_prev->data);
	free(head->p_prev);
	head->p_prev = tail;
	tail->p_next = head;

}

void delete_end()
{
	
	if(head == NULL)
	{
		printf("\nList is Empty.");
		return;
	}
	if(head == tail)
	{
		printf("\nDeleted element is %d", head->data);
		head = tail = NULL;
		return;
	}
	
	tail = tail ->p_prev ;
	printf("\nDeleted element is %d", tail->p_next->data);
	free(tail->p_next);
	tail->p_next = head;
	head->p_prev = tail;
	
}

void delete_pos(int pos) 
{
	if(head == NULL)
	{
		printf("\nList is Empty.");
		return;
	}
	if(head == tail)
	{
		printf("\nDeleted element is %d", head->data);
		head = tail = NULL;
		return;
	}
	
	if(pos == 1)
	{
		delete_beg();
	}
	else
	{
		struct node * temp1 , *temp2;
		int count1 = 1;
		// traverse to pos
	
		temp1 = head; // starts from head (to access second last elt)
		temp2 = head->p_next; // starts from head + 1  
	
		while(count1 < pos-1) 
		{
			temp1=temp1->p_next; // reaches to pos - 1
			temp2=temp2->p_next; // reaches to pos
			count1++;
		}
		
		if(temp2 -> p_next == head)
		{
			delete_end();
		}
		else
		{
		
		temp1->p_next = temp2->p_next;
		temp2->p_next-> p_prev = temp1;
		printf("\nDeleted element is %d", temp2->data);
		free(temp2);
		}
	}
	

}


void display()
{
	if(head == NULL)
	{
		printf("\nList is Empty.");
		return;
	}
	
	struct node * ptr;
	printf("\nDisplaying List elements...(head to tail)\n");
	for(ptr = head ; ptr != tail ;ptr=ptr->p_next)
	{
		printf("%d\t",ptr-> data);	 
	}
	printf("%d\t",ptr-> data);
}


int sizeLL()
{
	int size = 0;
	if(head != NULL)
	{
		struct node * temp;
		for(temp = head ; temp != tail ; temp=temp->p_next)
		{
			size++;
		}
	}
	printf("\n\nSize is %d" , ++size);
	return size;
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
	while(ch != 5)	
	{
		printf("\n\nMain Menu ");
		printf("\n\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit");
		printf("\n\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: {
					createDLL();
					break;
			}
			case 2: {
					int ch1 = 0;
					while(ch1 != 4)	
					{
						printf("\n\nInsert Menu ");
						printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at particular position\n4.Main Menu");
						printf("\n\nEnter your choice : ");
						scanf("%d",&ch1);
						switch(ch1)
						{
							case 1: {
								do
 								{
 									printf("\nEnter element to insert at beginning : ");
 									fflush(stdin);
									gets(temp);
    								item = validint(temp);
 								}while(valid==0);
								insert_beg(item);
								
								break;
							}
							case 2: {
							do
 								{
 									printf("\nEnter element to insert at end : ");
 									fflush(stdin);
									gets(temp);
    								item = validint(temp);
 								}while(valid==0);
								insert_end(item);
								
								break;
							}
							case 3: {
								int pos ,size;
								size = sizeLL();
								do{
								printf("\nEnter position to insert an element : ");
								scanf("%d",&pos);
								 
								if(pos > size+1 || pos < 1)
								{
									printf("\nInvalid position to insert");	
								}
								}while(pos > size+1 || pos < 1);
								
								do
 								{
 									printf("\nEnter element to insert at postion %d : " , pos);
 									fflush(stdin);
									gets(temp);
    								item = validint(temp);
 								}while(valid==0);
								insert_pos(pos,item);
								
								break;
							}
							case 4: {
								break;
							}
							default: {
								 printf("\nWrong Choice!!");
							}	
						}
					}
			}		break;
			case 3: {
					int ch1 = 0;
					while(ch1 != 4)	
					{
						printf("\n\nDelete Menu ");
						printf("\n\n1.Delete from beginning\n2.Delete from end\n3.Delete from particular position\n4.Main Menu");
						printf("\n\nEnter your choice : ");
						scanf("%d",&ch1);
						switch(ch1)
						{
							case 1: {
								
								delete_beg();
								
							
								break;
							}
							case 2: {
							
								delete_end();
								
								break;
							}
							case 3: {
								int pos ,size ;
								size = sizeLL();
								do{
								printf("\nEnter position to delete an element : ");
								scanf("%d",&pos);
								
								if(pos > size|| pos < 1)
								{
									printf("\nInvalid position to insert");	
								}
								}while(pos > size || pos < 1);
								
								delete_pos(pos);
								
							
								break;
							}
							case 4: {
								break;
							}
							default: {
								 printf("\nWrong Choice!!");
							}	
						}
					}
			}		break;
			
			case 4: display();
					break;
			case 5: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	
return 0;
}
