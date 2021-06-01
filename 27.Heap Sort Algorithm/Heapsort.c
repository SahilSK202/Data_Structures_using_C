// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 27


// Heap Sort algorithm 
// To sort the available data
// Time complexity of Heap Sort 
//  O(n logn ) 
// Space complexity is O(1) 
   


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>



bool valid = 1; //used for validation purpose only
char temp[100];

void swap(int *first , int *second)
{
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    // if largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
 
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // build heap (rearrange array)
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // one by one extract an element from heap
    for (i=n-1; i>=0; i--)
    {
        // move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int array[] ,int size )
{
	int i;

	for (i = 0; i < size; i++)
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
	int i , size;
		
	do
 	{
 		printf("Enter size of array : ");
    	fflush(stdin);
		gets(temp);
    	size = validint(temp);
 	}while(valid==0 || size < 1);
    
    int array[size],arrayAsc[size];
    
  
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
    
    heapSort(arrayAsc , size );
        
    printf("\n\nDisplaying Ascendingly sorted elements :\n");
    printArray(arrayAsc ,size );
    
    
    return 0;
} 
