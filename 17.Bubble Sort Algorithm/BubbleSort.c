// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 17


// C program to implement Bubble Sort algorithm 
// To sort the available data
// Time complexity of Bubble Sort 
// O(n) = when already sorted , O(n^2)
   


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


bool valid = 1; //used for validation purpose only
char temp[100];



void BubbleSortAsc(int array[], int size)
{
	int i , j , temp ,flag;
	
	for (i = 0; i < size - 1; i++) // no of iterations
    {   
		flag = 0;
		for (j = 0; j < size - 1 - i; j++) // no of comparisons
        {
			if (array[j] > array[j+1]) 
            {
 				temp =  array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
            }
        }
        
        if(flag == 0) //optimized iterations
        	break;
    }	
}

void BubbleSortDesc(int array[], int size)
{
	int i , j , temp ,flag;
	
	for (i = 0; i < size - 1; i++) // no of iterations
    {   
		flag = 0;
		for (j = size-1; j > i; j--) // no of comparisons
        {
			if (array[j] > array[j-1]) 
            {
 				temp =  array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                flag = 1;
            }
        }
        
        if(flag == 0) //optimized iterations
        	break;
    }	
}


void printArray(int array[] ,int size )
{
	int i;

	for (i = 0; i < size; ++i)
        printf("%d\t", array[i]);
    printf("\n");
}

void copyArray(int Srcarr[] , int Destarr[] , int size)
{
	int i;
	for(i = 0 ; i < size ; i++)
		Destarr[i] = Srcarr[i];	
	
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
    
    int array[size],arrayAsc[size],arrayDesc[size];
    
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
    printArray(array ,size);
    
    copyArray(array , arrayAsc , size);
    printf("\n\nDisplaying Ascendingly sorted elements :\n");
    BubbleSortAsc(arrayAsc , size);
    printArray(arrayAsc ,size );
    
    copyArray(array , arrayDesc , size);
    printf("\n\nDisplaying Descendingly sorted elements :\n");
    BubbleSortDesc(arrayDesc , size);
    printArray(arrayDesc ,size );
    
    return 0;
} 
