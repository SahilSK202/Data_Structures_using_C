# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define MAX 100

//a+b-(c/d)*e%(f-g)
//(a+b)-c

char stack[MAX] ;
int top = -1;

void infixToPrefix(char infix[] , char Prefix[]);
void infixToPostfix(char infix[] , char postfix[]);
void Reverse(char str[] , char rev[] );
int getPriority(char opr);
void push(char val);
char pop();

int main()
{
	
	int i ,k, len , p , s= 0;
	char infix[100] ,rev_infix[100] ,prefix[100] , postfix[100];
	
	printf("Enter Expression : ");
	gets(infix);
	
	len = strlen(infix);
	
	
	
	Reverse(infix,rev_infix);
	
	
	for(i = 0 ; i < len ; i++)
	{	
		p = getPriority(rev_infix[i]);
	
		
		if(p == 0) // if it is operand add to prefix
		{
			prefix[s++] = rev_infix[i]; 
		}
		
		else if(p == 4 ) // if it is closing bracket
		{
			while(top >= 0)
			{
				if(getPriority(stack[top]) != 5 ) // if top is not "opening bracket" then add to prefix and continue
				{
					prefix[s++] = pop();
					continue;
				}
				break; // break if it is "opening bracket"
			}		
		}
		
		else if(p < getPriority(stack[top]) && top >= 0)
			{
			
				while(1)
				{
					if(p < getPriority(stack[top]) && top >= 0  ) // if it is less than current priortiy then pop and add to prefix and continue
					{
						if(getPriority(stack[top]) != 5 )
						{
						prefix[s++] = pop();
						continue;
						}
					}
				
					push(rev_infix[i]);
					break; // if it is greater then push it to stack and stop compairing
				}
			}
		else
		{
			push(rev_infix[i]);
		}
	}
	
	while(top >= 0) // add remaining operators from stack to prefix except '('
	{
		if(getPriority(stack[top]) == 5)
		{
			top--;
		}
		else
		{
			prefix[s++] = pop();
		}
	}

	prefix[s] = '\0';
	
	
	//printf("\ninfix = %s" , infix);
	printf("\nrev_infix = %s" , rev_infix);
	printf("\nprefix = %s" , prefix);
	printf("\n\ntop = %d ", top);
	
	
	return 0;
}

void infixToPostfix(char infix[] , char postfix[])
{
	int i ,p , s = 0;
	
	for(i = 0 ; i < len ; i++)
	{	
		p = getPriority(infix[i]);
	
		
		if(p == 0) // if it is operand add to prefix
		{
			postfix[s++] = infix[i]; 
		}
		
		else if(p == 4 ) // if it is closing bracket
		{
			while(top >= 0)
			{
				if(getPriority(stack[top]) != 5 ) // if top is not "opening bracket" then add to prefix and continue
				{
					postfix[s++] = pop();
					continue;
				}
				break; // break if it is "opening bracket"
			}		
		}
		
		else if(p < getPriority(stack[top]) && top >= 0)
			{
			
				while(1)
				{
					if(p < getPriority(stack[top]) && top >= 0  ) // if it is less than current priortiy then pop and add to prefix and continue
					{
						if(getPriority(stack[top]) != 5 )
						{
						postfix[s++] = pop();
						continue;
						}
					}
				
					push(infix[i]);
					break; // if it is greater then push it to stack and stop compairing
				}
			}
		else
		{
			push(infix[i]);
		}
	}
	
	while(top >= 0) // add remaining operators from stack to prefix except '('
	{
		if(getPriority(stack[top]) == 5)
		{
			top--;
		}
		else
		{
			postfix[s++] = pop();
		}
	}

	postfix[s] = '\0';
	
}


int getPriority(char opr)
{
	if(opr == '(' )
		return 5;
	else if(opr == ')' )
		return 4;
	else if(opr == '*' || opr == '/' || opr == '%')
		return 3;
	else if(opr == '+' || opr == '-')
		return 2;
	else
		return 0;
	
}


void push(char val)
{
	if(top == MAX - 1)
	{
		printf("\nStack Overflow...!");
	}
	else
		stack[++top] = val;
}

char pop()
{
	if(top == -1)
	{
		printf("\nStack Underflow...!");
	}
	else
	{
		//printf("\nPopped element is : %c" , stack[top]);
		return stack[top--];
	}
}


void Reverse(char str[] , char rev[] )
{
	int i ,j , len ;
	len = strlen(str);
	for(i = 0 , j = len-1 ; i < len ; i++ ,j--)
	{
	
		rev[i] = str[j];
		
		if(str[j] == '(')
			rev[i] = ')';
		if(str[j] == ')')
			rev[i] = '(';
	
	}
	rev[i] = '\0';
	
}

