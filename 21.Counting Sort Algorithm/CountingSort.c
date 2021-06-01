// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 21


// counting Sort algorithm 
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
int size;


void printArray(int array[] ,int size )
{
	int i;

	for (i = 0; i < size; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

void copyArray(int Srcarr[] , int Destarr[] , int size )
{
	int i;
	for(i = 0 ; i < size ; i++)
		Destarr[i] = Srcarr[i];	
	
} 

void CountSortAsc(int array[], int size , int count[] , int max) //upper and lower bound
{
	int i ,j ;
	
	
	for(i = 0 ; i < max+1 ; i++)
	{
		count[i] = 0;
	}
	
	for(i = 0 ; i < size ; i++)
	{
		count[array[i]]++;
	}
	
	
	//update count array
	
	for(i = 1 ; i < max+1 ; i++)
	{
		count[i] += count[i-1];
	}
	
	int b[size];
	for(i = size-1  ; i >=0 ; i--)
	{
		
		b[--count[array[i]]] = array[i];
	}
	
	copyArray(b , array , size);
	
	
	
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
	int i , min , max ;

	do
 	{
 		printf("\nEnter size of array : ");
    	fflush(stdin);
		gets(temp);
    	size = validint(temp);
 	}while(valid==0 || size < 1);
 	
 	do
 	{
 		printf("\nEnter minimum of range : ");
    	fflush(stdin);
		gets(temp);
    	min = validint(temp);
 	}while(valid==0 );
 	
 	do
 	{
 		printf("\nEnter maximum of range : ");
    	fflush(stdin);
		gets(temp);
    	max = validint(temp);
    	if(max < min)
    	{
    		printf("\nMaximum must be greater than minimum i.e %d\n" , min);
		}
 	}while(valid==0 || max < min);
    
    int array[size],arrayAsc[size],count[max+1];;
    
    
    printf("\nEnter data :\n");
    for(i = 0; i < size; i++)
    {
   		do
 		{
 			printf("array[%d] = " , i);
    		fflush(stdin);
			gets(temp);
    		array[i] = validint(temp);
    		if(array[i] > max || array[i] < min)
    		{
    			printf("\nData is out of range.\nRange is %d-%d\n\n" , min,max);
			}
 		}while(valid==0 || array[i] > max || array[i] < min );
    }
    
    printf("\nDisplaying elements :\n");
    printArray(array ,size);
    
    copyArray(array , arrayAsc , size);
    
    CountSortAsc(arrayAsc , size , count , max);
        
    printf("\n\nDisplaying Ascendingly sorted elements :\n");
    printArray(arrayAsc ,size );
    
    
    return 0;
} 
