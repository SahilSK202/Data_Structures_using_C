// Lab Assignment 1
// Sahil Shivaji Kavitake
// Roll no 672.


//  C program to add two polynomials using array data structure.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



void setPoly (float coeff[] ,int exp[], int deg);
int dispPoly (float coeff[] ,int exp[], int deg);

int validint(char temp[]);
float validfloat(char temp[]);


bool valid = 1; //used for validation purpose only
char temp[100];

int main()
{
	int i;
 	int deg1,deg2;
 	
	
	do
	{
 		printf("\n\nEnter the highest degree of polynomial 1: ");
 		fflush(stdin);
		gets(temp);
		deg1 = validint(temp);
		if(deg1<1) printf("\nDegree must be greater than 0");
		
	}while(valid == 0 || deg1 < 1);

	
	float coeff1[deg1];
	int exp1[deg1]; 

 	setPoly (coeff1 , exp1 , deg1);
	
	char temp2[100];
 	do
	{
 		printf("\n\nEnter the highest degree of polynomial 2: ");
 		fflush(stdin);
 		gets(temp);
		deg2 = validint(temp);
		if(deg2<1) printf("\nDegree must be greater than 0"); 
		
	}while(valid == 0 || deg2 < 1);
	
	float coeff2[deg2];
	int exp2[deg2]; 

 	setPoly (coeff2 , exp2 , deg2);
 		
	int deg3 = (deg1 > deg2) ? deg1 : deg2;      
 	float coeff3[deg3]; 
	int exp3[deg3];
	
 	if(deg1>deg2)
    {	
		for(i=0;i<=deg2;i++)
		{
			coeff3[i] = coeff1[i] + coeff2[i];
			exp3[i] = exp1[i];
		}
		  
		for(i=deg2+1;i<=deg1;i++)
		{
			coeff3[i] = coeff1[i];
			exp3[i] = exp1[i];
		}
	}
 	else
  	{
	  	
    	for(i=0;i<=deg1;i++)
		{
			coeff3[i] = coeff1[i] + coeff2[i];
			exp3[i] = exp2[i];
		}
		  
		for(i=deg1+1;i<=deg2;i++)
		{
			coeff3[i] = coeff2[i];
			exp3[i] = exp2[i];
		}

  	}
  	
  	printf("\n----------------------------------------------\n");
 	
 	printf("\nFirst Polynomial  =  ");
	dispPoly (coeff1 , exp1 , deg1);
 	
 	printf("\n\nSecond Polynomial = ");
	dispPoly (coeff2 , exp2 , deg2);
  
  	printf("\n\nAdditon is = ");
	dispPoly (coeff3 , exp3 , deg3);
	printf("\n\n");
	
return 0;

}

// function to set polynomial.

void setPoly (float coeff[] ,int exp[], int deg)
{
	int i;
	for(i=0;i<=deg;i++)
 	{
 		do
 		{
		
 		printf("\nEnter the coeff of x^%d : ",i);
 		fflush(stdin);
		gets(temp);
    	coeff[i] = validfloat(temp);
		exp[i] = i;
 		}while(valid==0);
 	}

}

// function to display polynomial

int dispPoly (float coeff[] ,int exp[], int deg)
{
	int i;
	
	printf(" %.2lf " , coeff[0]);
	
	for(i=1;i<=deg;i++)
  	{
  		if (coeff[i] == 0)
  			continue;
  		
  		if(coeff[i] < 0)
  			printf("- %.2lf x^%d ",(-1)*coeff[i],exp[i]);
  		
  		else
    		printf("+ %.2lf x^%d ",coeff[i],exp[i]);
  	}  
	  return 0; 
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

//function to validate integer value.

float validfloat(char temp[])
{
	valid = 1;
	int i , point = 0;
	
	if(strlen(temp) <= 0)
	{
		printf("\nEmpty Input !");
		valid = 0;
		return;
	}
	
	for( i = 0 ; i < strlen(temp) ; i++)
	{
		if(temp[0] == '-') continue;
		if(temp[i] == '.')
		{
			point++;
			continue;
		}
		if(!isdigit(temp[i]))
		{
			printf("\nInvalid input !");
			valid = 0;
			return;
		}
		if(point > 2)
		{
			printf("\nInvalid input !");
			valid = 0;
			return;
		}
	}
	
	
	float number;
	
	number = atof(temp);
		return number ;
	
}	


