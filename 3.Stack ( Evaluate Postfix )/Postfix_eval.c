//Program for conversion of infix expression to prefix and postfix.


# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<string.h>
# include<stdbool.h>

# define MAX 100



int stack[MAX] ;
int top = -1;

int Postfix_evaluate(char postfix[]);
int getPriority(char opr);
void push(int val);
int pop();
void validPostfix(char postfix[]);
void removeSpaces(char postfix[]);

bool valid = 1;

int main()
{
	
	char postfix[100];
	int Ans ;
	printf("\nNOTE :-  Enter only single digit operands... ");
	do
	{
	
	printf("\n\nEnter Postfix Expression : ");
	fflush(stdin);
	gets(postfix);
	removeSpaces(postfix);
	validPostfix(postfix);
	
	}while(valid == 0);
	
	Ans = Postfix_evaluate(postfix);
	
	printf("\nPostfix = %s" , postfix);
	printf("\n\nAns = %d" ,  Ans);
					
return 0;
}


int Postfix_evaluate(char postfix[])
{
	int i , len ,p, n1, n2 ,n3;
	len = strlen(postfix);
	
	for(i = 0 ; i < len ; i++)
	{	
		p = getPriority(postfix[i]);
	
		
		if(isdigit(postfix[i])) // if it is operand add to stack
		{
			push(postfix[i] - '0');
		}
		
		else // if it is operator
		{
			n1 = pop() ;
			n2 = pop() ;

			
			if(p == 6 )
				n3 = pow(n2,n1);
			else if(p == 5 )
				n3 = n2/n1;
			else if(p == 4)
				n3 = n2*n1;	
			else if(p == 3)
				n3 = n2%n1;
			else if(p == 2)
				n3 = n2+n1;
			else
				n3 = n2-n1;
			
			push(n3 );	//push result in ascii value			
		}
	}
		
	return stack[top] ; 
}


int getPriority(char opr)
{
	if(opr == '^' )
		return 6;
	else if(opr == '/' )
		return 5;
	else if(opr == '*' )
		return 4;	
	else if(opr == '%')
		return 3;
	else if(opr == '+')
		return 2;
	else if(opr == '-')
		return 1;
	else
		return 0;
	
}


void push(int val)
{
	if(top == MAX - 1)
	{
		printf("\nStack Overflow...!");
	}
	else
	{
		stack[++top] = val  ;	//conversion of ascii.	
	}
		
}

int pop()
{
	if(top == -1)
	{
		printf("\nStack Underflow...!");
	}
	else
	{
		//printf("\nPopped element is : %c" , stack[top]);
		return stack[top--]  ;
	}
}

void removeSpaces(char postfix[])
{
	int i = 0 , j = 0;
	char temp[50];
	strcpy(temp , postfix);
	
	while(temp[i] != '\0')    // till string doesn't terminate
    {
        if(temp[i] != ' ')  // if the char is not a white space
        {
            postfix[j++] = temp[i];
        }
        i++;
    }
    postfix[j] = '\0';
}

void validPostfix(char postfix[])
{
	valid = 1;
	int i = 0 , digit = 0 , symb = 0 , len;
	
	len = strlen(postfix);
	
	
	if((!isdigit(postfix[0])) && (!isdigit(postfix[1]))) // first two characters must be be digit
	{
		valid = 0;
		printf("\nInvalid Postfix Expression..! ");
		return;
	}
	
	if(isdigit(postfix[len-1])) // last char should not be digit
	{
		valid = 0;
		printf("\nInvalid Postfix Expression..! ");
		return;
	}
		
	for(i = 0 ; i < len ; i++)
	{
		if(isdigit(postfix[i]))
			digit++;
		else
			symb++;	
	}
	
	
	if(symb != (digit -1)) // no of operations is 1 less than operands
	{
		valid = 0;
		printf("\nInvalid Postfix Expression..! ");
		return;
	}
		
}
