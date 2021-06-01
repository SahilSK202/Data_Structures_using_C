

// C program to implement BFS using Adjacency matrix.

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

/*
X |0 1 2 3 4 
---------------
0 |0 1 1 1 0
1 |1 0 1 0 0
2 |1 1 0 0 1
3 |1 0 0 0 0
4 |0 0 1 0 0

*/

bool valid = 1; //used for validation purpose only
char temp[100];


int Stack[5] ,top = -1;


void push(int val)
{
	
	
	if(top==4)
	{
		//printf("\nStack is full!!");
	}
	else
	{
		top=top+1;
		Stack[top]=val;
	}
}
 
int pop()
{
	int tmp;
	if(top==-1)
	{
		//printf("\nStack is empty!!");
	}
	else
	{
		tmp = Stack[top];
	//	printf("\nDeleted element is %d",Stack[top]);
		top=top-1;
	}
	return tmp;
}

int Search(int n , int Adj[n][n]  ,int elt)
{
	int i;
	for(i = 1 ; i < n+1 ; i++)
	{
		if(Adj[0][i] == elt) //searching in 1st row
		{
			return i;
		}
			
	}
	return -1;
}


void DFS(int val , int n, int Adj[n+1][n+1] ,int visited[n] )
{	
	int i ,ind, node , k =0 , j ,flag ;
	
	ind = Search(n , Adj , val);

	visited[k] = val;
	
	
	do
	{	
		//printf("\n ind is %d \n\n" ,ind);
		
		for(i = 1 ; i <= n ; i++) //traverse val th row
		{
			node = Adj[ind][i]; //val th row and i th col

			if(node == 1) 
			{	
				flag = 0;
				for (j = 0 ; visited[j] != -1 ; j++) //traverse visited array
				{
					
					if(visited[j] == Adj[0][i])
					{	
						flag = 1;
						break;
					}	
					
				}
				for (j = top ; j > -1 ; j--) //traverse stack
				{
					
					if(Stack[j] == Adj[0][i] && top != -1)
					{
						flag = 1;
						break;
					}	
					
				}
				if(flag == 0 )
				{
					push(Adj[0][i]);	

					//printf("visited[%d] = %d\n\n" ,k , visited[k] );
				}
				
			}
		}
		//printf("\nvisited[%d] = %d\n\n" ,k , visited[k] );

			visited[++k] = pop();
		ind = Search(n , Adj , visited[k] );

	}while(k != n );

}

// Function to print the created Adjacency Matrix 
void printAdjMatrix(int n , int Adj[n+1][n+1]) 
{ 
	int i,j;
  for(i = 0 ; i < n+1 ; i ++)
	{
		if(i == 1)
		{
			printf("-------------------------------------------\n");
		}
		for(j = 0 ; j < n+1 ; j ++)
		{
			if(j == 1)
			printf("|");
			printf(" %d\t",Adj[i][j]);
		}
		printf("\n");
	}
} 

int main() 
{
	
	int i ,j ,val ,n;
	int visited[5];

	int Adj[6][6]= {
	{-1, 0, 1 ,2, 3, 4 },
	{0, 0 ,1, 1, 1, 0 },
	{1, 1 ,0, 1, 0, 0 },
	{2, 1 ,1, 0, 0, 1 },
	{3, 1 ,0, 0, 0, 0 },
	{4, 0 ,0, 1, 0, 0 },
	};
	
	/*do
 	{
 		printf("\nEnter number of vertices in a graph :");
 		fflush(stdin);
		gets(temp);
    	n = validint(temp);
 	}while(valid==0);*/
 	
 	
	
	

	printf("Adjacency matrix is :-\n\n");
	printAdjMatrix(5 , Adj) ;

	
	while(1)
	{
	
	
		for(i = 0 ; i < 5 ; i++) //initialized visited array and queue with -1
		{
			visited[i] = -1;
			Stack[i] = -1;
		}
		do
	 	{
	 		printf("\n\n___________________________________________________\n\n");
	 		printf("\nVertices in a graph : \n\n");
	 		for(i = 1 ; i <= 5 ; i++)
	 			printf(" %d\t",Adj[0][i]);
	 		printf("\n\nEnter the vertex value for DFS to start with : ");
	 		fflush(stdin);
			gets(temp);
	    	val = validint(temp);
	    	i = Search(5,Adj,val);
	    	if(i == -1)  printf("\nVertex not present.\n");
	 	}while(valid==0 || i == -1);
			
		DFS(val , 5 ,Adj ,visited);
	
		printf("\n\nDFS starting with %d is :- \n\n" ,val);
		
		for( i = 0 ; i < 5 ; i++)
		{
			printf(" %d\t" , visited[i]);
		}
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

	

