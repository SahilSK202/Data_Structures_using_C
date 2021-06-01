// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 20


// Quick Sort algorithm 
// To sort the available data
// Time complexity of Merge Sort 
//  O(n logn ) ,O(n logn ),O(n^2)
// Space complexity is O(n) as it uses recursion 
   


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

int Partition(int array[], int lb , int ub) //upper and lower bound
{
	int  pivot , start ,end ;
	pivot = array[lb];
	start = lb;
	end = ub;
	
	while(start < end)
	{
		while(array[start] <= pivot)
		{
			start++;
		}
		while(array[end] > pivot)
		{
			end--;
		}
		if(start < end)
		{
			swap(&array[start],&array[end]);	
		}
			
	}
	swap(&array[lb] , &array[end]);
	return end;
	
	
}




void QuickSortAsc(int array[], int lb , int ub) //upper and lower bound
{
	int end1 ;
	
	if(lb < ub)
	{
		end1 = Partition(array , lb, ub);
		QuickSortAsc(array , lb, end1-1);
		QuickSortAsc(array , end1+1 , ub);
	}
	else
		return;	
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
    
    QuickSortAsc(arrayAsc , 0,size-1);
        
    printf("\n\nDisplaying Ascendingly sorted elements :\n");
    printArray(arrayAsc ,size );
    
    
    return 0;
} 
