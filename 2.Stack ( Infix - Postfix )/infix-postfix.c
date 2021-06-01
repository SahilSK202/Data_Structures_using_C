//C program to convert given infix expression to its equivalent postfix expression using stack.

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<stdbool.h>

# define MAX 100


char stack[MAX] ;
int top = -1;
bool valid = 1;

void infixToPostfix(char[] , char[]);
int getPriority(char);
void push(char);
char pop();

void removeSpaces(char[]);
void validInfix(char infix[]);

int main()
{
	
	int i , len , p , s= 0;
	char infix[100] ,postfix[100] ;
	
	do
	{
	
		printf("\n\nEnter infix Expression : ");
		gets(infix);
		removeSpaces(infix);
		validInfix(infix);

	}while(valid == 0);
	
	printf("\n\nInfix = %s" , infix);
	
	infixToPostfix(infix , postfix);

	printf("\n\nPostfix = %s" , postfix);
					
					
return 0;
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
			{// if top is not "opening bracket" then add to prefix and continue
				if(getPriority(stack[top]) != 5 ) 
				{
					postfix[s++] = pop();
					continue;
				}
				else
				{
					pop();
					break;	
				}
				 // break if it is "opening bracket"
			}		
		}
		
		// checking precedence 
		else if(p <= getPriority(stack[top]) && top >= 0)
			{
			
				while(1)
				{
					if(p <= getPriority(stack[top]) && top >= 0 && getPriority(stack[top]) > 3 ) 
					{
					
						postfix[s++] = pop();
						continue;
							
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

// function to remove white spaces from infix string

void removeSpaces(char infix[])
{
	int i = 0 , j = 0;
	char temp[50];
	strcpy(temp , infix);
	
	while(temp[i] != '\0')    // till string doesn't terminate
    {
        if(temp[i] != ' ')  // if the char is not a white space
        {
            infix[j++] = temp[i];
        }
        i++;
    }
    infix[j] = '\0';
}

// function to validate given infix 

void validInfix(char infix[])
{
	valid = 1;
	int i , open =0 , close =0 , len ;
	len = strlen(infix);
	
	if(infix[0] != '(' || infix[len-1] != ')' )
	{
	if(!isalnum(infix[0]) || !isalnum(infix[len-1]) )
	{
		valid = 0;
		printf("\nInvalid Infix Expression..");
		return;	
	}
	}
	
	for(i = 0 ; i < len ; i++)
	{
			
		if(infix[i] == '(')
		{
			open++;
			if(infix[i+1] == ')')
				{
				valid = 0;
				printf("\nInvalid Infix Expression..");
				return;		
				}
		}

		if(infix[i] == ')')
			close++;
	
	}
	
	if(open != close) // no of opening and closing brackets are same or not
	{
		printf("\nInvalid Infix Expression..!");
		valid = 0;
		return;
	}
	
}
