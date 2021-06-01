// Sahil Shivaji Kavitake.
// Msc.IMCA Sem-3
// Data structures using C
// Lab Assignment 19


// Merge Sort algorithm 
// To sort the available data
// Time complexity of Merge Sort 
//  O(n logn ) for all cases hence less used for large data
// Space complexity is O(n) as it uses recursion 
   


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>



bool valid = 1; //used for validation purpose only
char temp[100];
int size;

void MergeArrayAsc(int array[], int lb, int mid, int ub);
void MergeArrayDesc(int array[], int lb, int mid, int ub); 


void MergeSortAsc(int array[], int lb , int ub) //upper and lower bound
{
	int i , j , mid ;
	
	if(lb < ub)
	{
		mid = (lb + ub)/2; //dividing array with mid
		MergeSortAsc(array , lb , mid); //left subtree
		MergeSortAsc(array , mid+1 , ub); // right subtree
		MergeArrayAsc(array , lb ,mid ,ub);
	}
	else
		return;	
}

// function to merge the subarrays
void MergeArrayAsc(int array[], int lb, int mid, int ub) 
{
    int b[size];   
    int i, j, k;
    k = 0;
    i = lb;
    j = mid + 1;
    while(i <= mid && j <= ub)
    {
        if(array[i] < array[j])
        {
            b[k++] = array[i++];    // same as b[k]=a[i]; k++; i++;
        }
        else
        {
            b[k++] = array[j++];
        }
    }
  
    while(i <= mid)
    {
        b[k++] = array[i++];
    }
  
    while(j <= ub)
    {
        b[k++] = array[j++];
    }
  
    for(i= ub; i >= lb; i--)
    {
        array[i] = b[--k];  // copying back the sorted list to array[]
    } 
}

void MergeSortDesc(int array[], int lb , int ub) //upper and lower bound
{
	int i , j , mid ;
	
	if(lb < ub)
	{
		mid = (lb + ub)/2; //dividing array with mid
		MergeSortDesc(array , lb , mid); //left subtree
		MergeSortDesc(array , mid+1 , ub); // right subtree
		MergeArrayDesc(array , lb ,mid ,ub);
	}
	else
		return;	
}

// function to merge the subarrays
void MergeArrayDesc(int array[], int lb, int mid, int ub) 
{
    int b[size];   
    int i, j, k;
    k = 0;
    i = lb;
    j = mid + 1;
    while(i <= mid && j <= ub)
    {
        if(array[i] > array[j])
        {
            b[k++] = array[i++];    // same as b[k]=a[i]; k++; i++;
        }
        else
        {
            b[k++] = array[j++];
        }
    }
  
    while(i <= mid)
    {
        b[k++] = array[i++];
    }
  
    while(j <= ub)
    {
        b[k++] = array[j++];
    }
  
    for(i= ub; i >= lb; i--)
    {
        array[i] = b[--k];  // copying back the sorted list to array[]
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
	int i ,element ,result;

	
	
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
    
    MergeSortAsc(arrayAsc , 0,size-1);
        
    printf("\n\nDisplaying Ascendingly sorted elements :\n");
    printArray(arrayAsc ,size );
    
    copyArray(array , arrayDesc , size);
    printf("\n\nDisplaying Descendingly sorted elements :\n");
    MergeSortDesc(arrayDesc , 0,size-1);
    printArray(arrayDesc ,size );
    
    return 0;
} 
