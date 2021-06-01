// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 18

// Insertion Sort algorithm 
// To sort while accepting input
// Time complexity of Insertion Sort  
// O(n) = when already sorted , O(n^2)
   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool valid = 1; //used for validation purpose only
char temp[100];



void InsertionSortAsc(int array[], int size)
{
	int i , j , temp ;
	
	for (i = 1; i < size ; i++) // traverse unsorted sublist
    {   
		temp = array[i];
	
		for (j = i-1; j >= 0 ; j--) // traverse sorted sublist
        {	
			if (array[j] > temp) 
            {
 				array[j+1] = array[j];
                array[j] = temp;
            }
            else
            {
            	array[j + 1] = temp;
            	break;
			}
        }
    }	
}




void InsertionSortDesc(int array[], int size)
{
	int i , j , temp ;
	
	for (i = 1; i < size ; i++) // traverse unsorted sublist
    {   
		temp = array[i];
	
		for (j = i-1; j >= 0 ; j--) // traverse sorted sublist
        {	
			if (array[j] < temp) 
            {
 				array[j+1] = array[j];
                array[j] = temp;
            }
            else
            {
            	array[j + 1] = temp;
            	break;
			}
        }
    }	
}

//function to print array
void printArray(int array[] ,int size )
{
	int i;

	for (i = 0; i < size; ++i)
        printf("%d\t", array[i]);
    printf("\n");
}

// function to free int pointer

void reset(int* Pointer) {
     if (Pointer) {
         free(Pointer);
         Pointer = NULL;
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
			printf("\nInvalid input !\n");
			valid = 0;
			return ;
		}
	}
	
	if(strlen(temp) <= 0)
	{
		printf("\nEmpty Input !\n");
		valid = 0;
		return ;
	}
	int integer;
	integer = atoi(temp);
	return integer ;
	
}	


int main(void) 
{ 
	int size ,ch1 ;
	char ch[10] ;
	char choice = 'y'||'Y'||'n'||'N';
    int *array ;
    
    while(1)
    {
    	do
 		{
    		printf("\n_____________________________________________________\n");
    		printf("\n\n******* INSERTION SORT MENU ******\n\n");
   			printf("1 - Sort Ascending\n");
    		printf("2 - Sort Descending\n");
    		printf("3 - Exit\n");
    		
 			printf("\nEnter your choice : ");
        	fflush(stdin);
			gets(temp);
    		ch1 = validint(temp);
    		if(valid == 1 && ch1 < 1 || ch1 > 3 )
			{
				printf("\nWrong choice, Please enter correct choice\n");
			}
 		}while(valid==0 || (ch1 > 3 || ch1 < 1));
 		
 		if(ch1 == 3)
 			exit(0);
 			
 	
		reset(array);	//free pointer	
 		size = 1;      // default size of array = 1
    	array = (int*) calloc(size , sizeof(int)); // dynamically allocating array
    
    do
	{
   		do
 		{
 			printf("\nInput integer data = ");
    		fflush(stdin);
			gets(temp);
    		*(array + (size-1))= validint(temp);
    		if(size > 0 && valid == 1 && ch1 == 1)
	    		InsertionSortAsc(array ,size );
	    	if(size > 0 && valid == 1 && ch1 == 2)
	    		InsertionSortDesc(array ,size );
	    		
 		}while(valid==0);
 	
 		if(ch1 == 1)
 			printf("\n\nDisplaying Ascendingly sorted elements :\n");
 		else
 			printf("\n\nDisplaying Descendingly sorted elements :\n");
    	printArray(array ,size );
    	
    	do
		{
			printf("\n_____________________________________________________\n");
			printf("\nDo you want to enter more ? (y/n) : ");
			fflush(stdin);
			gets(ch);
			
			if(ch[0] != choice && ch[1]!= '\0' )
			{
				printf("\nWrong choice, Please enter correct choice\n");
			}
				
			if((ch[0] == 'y' || ch[0]=='Y' )&& ch[1]== '\0')
			{
				++size;
 				array = (int*) realloc(array , size * sizeof(int)); //reallocate if insertion is done.
			}
		
		}while(ch[0] != choice && ch[1]!= '\0');
					
    
 		
    }while(ch[0]=='y'|| ch[0]=='Y');
    
    
    	if(ch1 == 1)
 			printf("\n\nDisplaying Ascendingly sorted elements :\n");
 		else
 			printf("\n\nDisplaying Descendingly sorted elements :\n");
    	printArray(array ,size );
    
	}

    
    return 0;
} 
