#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INFINITY 9999
#define MAX 10


bool valid = 1; //used for validation purpose only
char temp[100];


void dijkstra(int Graph[MAX][MAX],int n,int startnode);
int validint(char temp[]);

/*
X |0 1 2 3 4 
---------------
0 |0 10 5 0 0
1 |0 0 0 1 0
2 |0 3 0 9 2
3 |0 0 0 0 0
4 |2 0 0 6 0

*/

 
int main()
{
	int Graph[MAX][MAX],i,j,n,startnode;
	
	do
 	{
 		printf("\nEnter no. of vertices:");
    	fflush(stdin);
		gets(temp);
    	n = validint(temp);
 	}while(valid==0);
 	
	printf("\nVertices of graph are :\n");
	for(i=0;i<n;i++)
		printf("%d\t",i);
		
	printf("\n\nEnter the adjacency matrix (weight):\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&Graph[i][j]);
	
	
	while(1)
	{
	do
 	{
 		printf("\n\n___________________________________________________\n\n");
 		printf("\nVertices of graph are :\n");
		for(i=0;i<n;i++)
			printf("%d\t",i);
			
 		printf("\n\nEnter the starting node:");
    	fflush(stdin);
		gets(temp);
    	startnode = validint(temp);
    	if( startnode < -1 || startnode > n-1)
    	{
    		printf("\nInvalid Vertex !\n");
		}
 	}while(valid==0 || startnode < -1 || startnode > n-1);
 	
	dijkstra(Graph,n,startnode);
	}
	
	return 0;
}
 
void dijkstra(int Graph[MAX][MAX],int n,int startnode)
{
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j ,empty;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(Graph[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=Graph[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
		{
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
			{
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
			}
		count++;
	}
 	
 	empty = 0;
	//print the path and distance of each node
	for(i=0;i<n;i++)
	{
		
		if(i!=startnode)
		{
			
			if(distance[i] == INFINITY)
			{
				
				continue;
			}
			++empty;
			printf("\n\nShortest Distance  d(%d,%d) is %d",startnode,i,distance[i]);
			printf("\nShortest Path = %d ",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<- %d ",j);
			}while(j!=startnode);
		}
	
	}
	if( empty == 0)
		{
			printf("\n\nThere is no outgoing edge from vertex %d !\n",startnode);
		}
	
}
/*
0 10 5 0 0
0 0 0 1 0
0 3 0 9 2
0 0 0 0 0
2 0 0 6 0
*/
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
