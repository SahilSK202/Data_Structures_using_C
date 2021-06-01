// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 15

// C program to implement Linear Search Algorithm


#include <stdio.h>
#include<string.h>
#include<stdbool.h>


bool valid = 1; //used for validation purpose only
char temp[100];

 
int linearSearch(int array[], int n, int element) // TC : O(1),O(n),O(n)
{
   int i;
 
   for (i = 0 ;i < n ; i++ ) 
   {
        if (array[i] == element)
         	return i;
   }
 
   return -1;
}


void printArray(int array[] ,int size )
{
	int i;

	for (i = 0; i < size; i++)
        printf("%d\t", array[i]);
    printf("\n");
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


int main()
{
   int i, size ,element ,result;
	
	do
 	{
 		printf("Enter size of array : ");
    	fflush(stdin);
		gets(temp);
    	size = validint(temp);
 	}while(valid==0);
    
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
	
	while(1)
	{
		

    do
 	{
 		printf("\n\nEnter element to be serached : ");
    	fflush(stdin);
		gets(temp);
    	element = validint(temp);
 	}while(valid==0 || size < 1);
    
    result = linearSearch(array, size , element); 
    
    (result == -1) ? printf("\nThe element is not present !") 
                   : printf("\nThe element is present at position %d", result+1); 
    }
    return 0; 
}

