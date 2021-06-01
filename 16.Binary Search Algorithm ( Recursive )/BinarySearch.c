// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 16

// C program to implement Binary search algorithm 
// Search element in sorted array 
// Time complexity of binary search O(log n)
   


#include <stdio.h>
#include<string.h>
#include<stdbool.h>


bool valid = 1; //used for validation purpose only
char temp[100];


int BinarySearch(int array[], int size, int element) //iterative 
{ 
	int first , mid , last;
	first = 0;
	last = size - 1;
	
    while (first <= last) 
	{ 
        mid = first + (last - first) / 2; 
        
        if (array[mid] == element) 
            return mid; 
            
        if (array[mid] < element) 
            first = mid + 1; 
            
        else
            last = mid - 1; 
    }  
    return -1; //as position cannot be -1
}   


int BinarySearchRec(int array[], int first , int last, int element) // using recursion
{ 
	int mid ;
	
		if( first > last) 
		{
			return -1;
		}
		
        mid = (first + last) / 2; 
        
        if (array[mid] == element) 
        {
        	return mid; 
		}
            
            
        if (array[mid] < element) 
        {
        	first = mid + 1; 
        	return BinarySearchRec(array , first , last , element);
		}
        else
        {
        	last = mid - 1;
        	return BinarySearchRec(array , first , last , element);
		}
		   

        
    	
}   


void sortAsc(int array[], int size)
{
	int i , j , temp;
	
	for (i = 0; i < size; i++) 
    {    
		for (j = i + 1; j < size; j++)
        {
			if (array[i] > array[j]) 
            {
 				temp =  array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }	
}


void printArray(int array[] , int size)
{
	int i;
	for (i = 0; i < size; ++i)
            printf("%d\t", array[i]);
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
			printf("\nInvalid input !\n");
			valid = 0;
			return;
		}
	}
	
	if(strlen(temp) <= 0)
	{
		printf("\nEmpty Input !\n");
		valid = 0;
		return;
	}
	int integer;
	integer = atoi(temp);
	return integer ;
	
}	


int main(void) 
{ 
	int i, size ,element ,result;
	
	do
 	{
 		printf("Enter size of array : ");
    	fflush(stdin);
		gets(temp);
    	size = validint(temp);
 	}while(valid==0 || size < 1);
    
    int array[size];
    
    for(i = 0; i < size; i++)
    {
   		do
 		{
 			printf("array[%d] = " , i);
    		fflush(stdin);
			gets(temp);
    		array[i] = validint(temp);
 		}while(valid==0);
    }
    
    printf("\nDisplaying elements :\n");
    printArray(array , size);
    
    
    sortAsc(array , size);
    printf("\n\nDisplaying sorted elements :\n");
    printArray(array , size);
    
    while(1)
    {
	
    do
 	{
 		printf("\n\nEnter element to be searched : ");
    	fflush(stdin);
		gets(temp);
    	element = validint(temp);
 	}while(valid==0);
    
    result = BinarySearchRec(array, 0 , size-1 , element); //recursive
	//result = BinarySearch(array, size , element); //iterative
    
    (result == -1) ? printf("\nThe element is not present !") 
                   : printf("\nThe element %d is present at position %d",element, result+1); 
    
	}
    return 0; 
} 
