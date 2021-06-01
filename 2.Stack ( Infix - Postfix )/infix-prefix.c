//C program to convert given infix expression to its equivalent prefix expression using stack.

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<stdbool.h>

# define MAX 100


char stack[MAX] ;
int top = -1;
bool valid = 1;

void infixToPrefix(char[] , char[]);
void Reverse(char[] , char[] );
int getPriority(char);
void push(char);
char pop();

void removeSpaces(char[]);
void validInfix(char infix[]);

int main()
{
	
	int i , len , p , s= 0;
	char infix[100] ,prefix[100] , rev_infix[100];
	
	do
	{
	
	printf("\n\nEnter infix Expression : ");
	gets(infix);
	removeSpaces(infix);
	//validInfix(infix);

	}while(valid == 0);
	
	printf("\n\nInfix = %s" , infix);
	
	Reverse(infix,rev_infix);	
	infixToPrefix(rev_infix,infix);
	Reverse(infix , prefix);
	

	printf("\n\nPrefix = %s" , prefix);
					
					
return 0;
}



void infixToPrefix(char rev_infix[] , char prefix[])
{
	int i ,p , s = 0 , len , k=0 ;
	len = strlen(rev_infix);
	
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


void validInfix(char infix[])
{
	valid = 1;
	int i , open =0 , close =0 , len , symb , oprd;
	len = strlen(infix);
	
	for(i = 0 ; i < len ; i++)
	{
		if (isdigit(infix[i]))
		{
			valid = 0;
			printf("\nDigits not allowed..!");
			return;
		}
		
		
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
			
		if(!isalnum(infix[i]))
			symb++;
		
		if(isalpha(infix[i]))
			oprd++;
	}
	
	if(open != close)
	{
		printf("\nInvalid Infix Expression..!");
		valid = 0;
		return;
	}
	
	if(symb < oprd - 1)
	{
		printf("\nInvalid Infix Expression..!");
		valid = 0;
		return;
	}
		
	
}
