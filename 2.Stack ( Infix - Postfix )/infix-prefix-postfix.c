//Program for conversion of infix expression to prefix and postfix.

# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define MAX 100

//a+b-(c/d)*e%(f-g)
//(a+b)-c
//a+(b*c-(d/e^f)*g)*h

char stack[MAX] ;
int top = -1;

void infixToPostfix(char infix[] , char Prefix[]);
void infixToPrefix(char infix[] , char postfix[]);
void Reverse(char str[] , char rev[] );
int getPriority(char opr);
void push(char val);
char pop();

int main()
{
	
	int i , len , p , s= 0;
	char infix[100] ,prefix[100] , postfix[100];
	
	printf("Enter infix Expression : ");
	gets(infix);

	
	Reverse(infix,prefix);
	printf("\n\nReverse Infix = %s" , prefix);
	infixToPrefix(prefix , postfix);
	Reverse(postfix , prefix);
	printf("\n\nInfix = %s" , infix);
	printf("\n\nPrefix = %s" , prefix);
					
	infixToPostfix(infix , postfix);

	printf("\n\nPostfix = %s" , postfix);
					
return 0;
}



void infixToPrefix(char infix[] , char postfix[])
{
	int i ,p , s = 0 , len , k=0 ;
	len = strlen(infix);
	
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
				else
				{
					pop();
					break;	
				}
				//break; //pop and break if it is "opening bracket"
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
		
		//printf("\npostfix = %s " , postfix );
		
		//printf("\t stack is = %s" , stack);
	
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


void infixToPostfix(char infix[] , char postfix[])
{
	int i ,p , s = 0 , len , k=0 ;
	len = strlen(infix);
	
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
				else
				{
					pop();
					break;	
				}
				//break; // break if it is "opening bracket"
			}		
		}
		
		else if(p <= getPriority(stack[top]) && top >= 0)
			{
			
				while(1)
				{
					if(p <= getPriority(stack[top]) && top >= 0  ) // if it is less than current priortiy then pop and add to prefix and continue
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
		
		//printf("\npostfix = %s " , postfix );
		
		//printf("\t stack is = %s" , stack);
	
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
	else if(opr == '^' )
		return 3;	
	else if(opr == '*' || opr == '/' || opr == '%')
		return 2;
	else if(opr == '+' || opr == '-')
		return 1;
	
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

