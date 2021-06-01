// Lab Assignment 13

// C program (Menu Driven) to implement Binary search tree using linked list.

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


bool valid = 1; //used for validation purpose only
char temp[100];

struct BSTnode
{
    int data; 
    struct BSTnode *right_child; 
    struct BSTnode *left_child; 
};

//function to find node in a tree
struct BSTnode* search(struct BSTnode *root, int x)
{
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else if(x<root->data) //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
    else 
    	return NULL;   
}

//function to find the minimum value in a node
struct BSTnode* find_minimum(struct BSTnode *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}


//function to find the maximum value in a node
struct BSTnode* find_maximum(struct BSTnode *root)
{
    if(root == NULL)
        return NULL;
    else if(root->right_child != NULL) // node with maximum value will have no right child
        return find_minimum(root->right_child); // right most element will be minimum
    return root;
}


//function to create a node
struct BSTnode* new_node()
{
    struct BSTnode *p;
	p=(struct BSTnode*)malloc(sizeof(struct BSTnode));
	
	do
 	{
 		printf("\nEnter the data : ");
    	fflush(stdin);
		gets(temp);
    	p->data = validint(temp);
 	}while(valid==0);
 	

    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}


void insert(struct BSTnode *root,struct BSTnode *temp)
{
	if(temp->data<root->data) // newnode data is smaller should be inserted to left of root
	{
		if(root->left_child!=NULL)
			insert(root->left_child,temp);
		else
			root->left_child=temp;
	}
	
	if(temp->data>root->data) // newnode data is greater. Should be inserted to right of root
	{
		if(root->right_child!=NULL)
			insert(root->right_child,temp);
		else
			root->right_child=temp;
	}
}


// funnction to delete a node
struct BSTnode* Remove(struct BSTnode *root, int x)
{
	
    //searching for the element
    if(root==NULL) //right or left of leaf node
    {
    	printf("\nElement not found..!");
    	return NULL;	
	}
        
    if (x > root->data)
        root->right_child = Remove( root->right_child, x );
    else if(x < root->data)
        root->left_child = Remove(root->left_child, x);
        
    else // x  = root->data
    {
		
		
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
        	printf("\nElement deleted successfully..!\n");
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct BSTnode *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            printf("\nElement deleted successfully..!\n");
            free(root);
            return temp;
        }

        //Two Children
        else
        {
        	struct BSTnode *tmp;
        	int ch;
        	
        	printf("\nNotice :- Node has two children.\n");
        	do
        	{
        		printf("\n1- To replace with Successor.\n");
        		printf("2- To replace with Predecessor.\n");
        		printf("\nEnter your choice : ");
        		
        		fflush(stdin);
        		gets(temp);
				ch = validint(temp);
			}while(ch != 1 && ch !=2);
        	
        	if(ch==1)
        	{
        		tmp = find_minimum(root->right_child);
            	root->data = tmp->data;
           		root->right_child = Remove(root->right_child, tmp->data);
			}
			if(ch ==2)
			{
				tmp = find_maximum(root->left_child);
            	root->data = tmp->data;
            	root->left_child = Remove(root->left_child, tmp->data);
			}
            
        }
    }
    
    return root;
    
}

void inorder(struct BSTnode *root)
{
    
    	if (root == NULL)
    	{
        printf("No elements in a tree to display");
        return;
    	}
    	if (root->left_child != NULL)    
        inorder(root->left_child); // visiting left child
    	
		printf(" %d ", root->data); // printing data at root
    	if (root->right_child != NULL)    
        inorder(root->right_child);// visiting right child 
}


void preorder(struct BSTnode *root)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    
    	printf(" %d ", root->data); // printing data at root
    	
    	if (root->left_child != NULL)    
        inorder(root->left_child); // visiting left child
    	
    	if (root->right_child != NULL)    
        inorder(root->right_child);// visiting right child 
}
 

void postorder(struct BSTnode *root)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    
    	if (root->left_child != NULL)    
        inorder(root->left_child); // visiting left child
    	
    	if (root->right_child != NULL)    
        inorder(root->right_child);// visiting right child 
        
    	printf(" %d ", root->data); // printing data at root
    	
}

// This function traverses tree in post order to delete each and every node of the tree 
void deleteTree(struct BSTnode* node)  
{ 
    if (node == NULL) return; 
  
    /* first delete both subtrees */
    deleteTree(node->left_child); 
    deleteTree(node->right_child); 
    
    /* then delete the node */
    //printf("\n Deleting node: %d\n\n", node->data); 
    free(node); 
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


int main()
{
    
    struct BSTnode *root = NULL ,*tmp;
    int ch;
   
 	while(ch != 10 )
    {
    printf("\n_____________________________________________________\n");
    printf("\n\n******* OPERATIONS MENU ******\n\n");
    printf("1 - Create Binary Search Tree\n");
    printf("2 - Insert an element into tree\n");
    printf("3 - Delete an element from the tree\n");
    printf("4 - Search an element in the tree\n");
    printf("5 - Inorder Traversal\n");
    printf("6 - Preorder Traversal\n");
    printf("7 - Postorder Traversal\n");
    printf("8 - Show root\n");
    printf("9 - Delete Tree\n");
    printf("10 - Exit\n");
    
    	do
 		{
 			printf("\nEnter your choice : ");
        	fflush(stdin);
			gets(temp);
    		ch = validint(temp);
 		}while(valid==0);
 		
 		
        switch (ch)
        {
        case 1:   case 2:
            {
            	char ch;
            	do
				{
		
					if(root==NULL)
					{
						printf("\nEnter root : ");
						tmp=new_node();
						root=tmp;
					}
					else
					{
						tmp=new_node();	
						insert(root,tmp);
					}
					do
					{
					printf("\nDo you want to enter more(y/n)? : ");
					fflush(stdin);
					scanf("%c",&ch);
					if(ch != 'y' && ch!='Y' && ch != 'n' && ch!='N')
					printf("\nWrong choice, Please enter correct choice\n");
					}while(ch != 'y' && ch!='Y' && ch != 'n' && ch!='N');
					
				}while(ch=='y'|| ch=='Y');
			}
            break;
        
        case 3: 
        	{
        		int x;
				
				do
 				{
 					printf("\nEnter element you want to remove :");
    				fflush(stdin);
					gets(temp);
    				x = validint(temp);
 				}while(valid==0);
				  
           		root = Remove(root,x);
			}
			 break;
		case 4: 
        	{
        		int x;
        		struct BSTnode * tmp;
				do
 				{
 					printf("\nEnter element you want to search :");
    				fflush(stdin);
					gets(temp);
    				x = validint(temp);
 				}while(valid==0);
				
				tmp = search(root,x);
				(tmp == NULL) ? printf("\nElement %d not found !" ,x) : printf("\nElement %d found !" , x);
			}
			 break;
        case 5:
			printf("\nInorder Traversal of Binary Search Tree -\n\n");    
            inorder(root);
            break;
        case 6:    
        	printf("\n Preorder Traversal of Binary Search Tree -\n\n"); 
            preorder(root);
            break;
        case 7:    
        	printf("\n Postorder Traversal of Binary Search Tree -\n\n"); 
            postorder(root);
            break;
        case 8:    
            printf("\n Root is %d \n\n" , root->data);
			break; 
        case 9:    
            deleteTree(root);
            root = NULL;
            break;
        case 10: 
			deleteTree(root);   
            exit(0);
        default :     
            printf("\nWrong choice, Please enter correct choice  ");
            break;    
        }
    }
    return 0;
}
