// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Create Node
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};


bool valid = 1; //used for validation purpose only
char temp[100];

//int max(int a, int b);

// Function to get height
int height(struct Node *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Create a node
struct Node *new_node(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;// height is 0
  node->right = NULL;// height is 0
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *node) {
  struct Node *x = node->left;
  struct Node *xR = x->right;

  x->right = node;
  node->left = xR;

  node->height = max(height(node->left), height(node->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}


// Insert node
struct Node *insertNode(struct Node *node, int data) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (new_node(data));

  if (data < node->data)
    node->left = insertNode(node->left, data);
  else if (data > node->data)
    node->right = insertNode(node->right, data);
  else
    return node;

  // Update the height of each node and Balance the tree
  node->height = 1 + max(height(node->left),height(node->right));
  
  int balance = getBalance(node);
  if (balance > 1 && data < node->left->data) //LL
    node = rightRotate(node);

  if (balance < -1 && data > node->right->data)//RR
    node = leftRotate(node);

  if (balance > 1 && data > node->left->data) {//LR
    node->left = leftRotate(node->left);
    node = rightRotate(node);
  }

  if (balance < -1 && data < node->right->data) {//RL
    node->right = rightRotate(node->right);
    node = leftRotate(node);
  }

  return node;
}


//function to find node in a tree
struct Node* search(struct Node *root, int x)
{
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right, x);
    else if(x<root->data) //x is smaller than the data, so we will search the left subtree
        return search(root->left,x);
    else 
    	return NULL;   
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

struct Node *maxValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->right != NULL)
    current = current->right;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int data) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (data < root->data)
    root->left = deleteNode(root->left, data);

  else if (data > root->data)
    root->right = deleteNode(root->right, data);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),height(root->right));

  int balance = getBalance(root);
  
  
  if (balance > 1 && getBalance(root->left) >= 0)
    root = rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    root =  rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    root =  leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
   root = leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreorder(struct Node *root) {
	
	if (root == NULL){
        printf("\nNOTICE ::- No elements in a tree to display !\n");
        return;
    }
    
    printf("%d ", root->data);
    
	if (root->left != NULL)    
    	printPreorder(root->left);
 
    if (root->right != NULL)
    	printPreorder(root->right);

}

// Print the tree
void printInorder(struct Node *root) {
	
	if (root == NULL){
        printf("\nNOTICE ::- No elements in a tree to display !\n");
        return;
    }
    
	if (root->left != NULL)    
    	printInorder(root->left);
    	
    printf("%d ", root->data);
    
    if (root->right != NULL)
    	printInorder(root->right);
  
}

// Print the tree
void printPostorder(struct Node *root) {
	
	if (root == NULL){
        printf("\nNOTICE ::- No elements in a tree to display !\n");
        return;
    }
    
	if (root->left != NULL)    
    	printPostorder(root->left);

    if (root->right != NULL)
    	printPostorder(root->right);
    	
    printf("%d ", root->data);
  
}


// Function  to delete each and every node of the tree 
void deleteTree(struct Node* node)  
{ 
    if (node == NULL) return; 
  
    /* first delete both subtrees */
    deleteTree(node->left); 
    deleteTree(node->right); 
    
    /* then delete the node */
    //printf("\n Deleting node: %d", node->data); 
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

int main() {


	struct Node *root = NULL ,*tmp;
    int ch , val;
   
 	while(ch != 10 )
    {
    printf("\n_____________________________________________________\n");
    printf("\n\n******* OPERATIONS MENU ******\n\n");
    printf("1  - Create AVL Tree\n");
    printf("2  - Insert an element into tree\n");
    printf("3  - Delete an element from the tree\n");
    printf("4  - Search an element in the tree\n");
    printf("5  - Inorder Traversal\n");
    printf("6  - Preorder Traversal\n");
    printf("7  - Postorder Traversal\n");
    printf("8  - Show root\n");
    printf("9  - Delete Tree\n");
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
        case 1:
            {
            	deleteTree(root);
            	root = NULL;
            	char ch;
            	do
				{
		
					if(root==NULL)
					{
						
						do
 						{
 							printf("\nEnter root : ");
    						fflush(stdin);
							gets(temp);
    						val = validint(temp);
 						}while(valid==0);
						tmp=new_node(val);
						root=tmp;
					}
					else
					{
						do
 						{
 							printf("\nEnter data : ");
    						fflush(stdin);
							gets(temp);
    						val = validint(temp);
 						}while(valid==0);
 						
						insertNode(root,val);
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
        case 2:
        	{
        		char ch;
            	do
				{
						do
 						{
 							printf("\nEnter data : ");
    						fflush(stdin);
							gets(temp);
    						val = validint(temp);
 						}while(valid==0);
 						
						root = insertNode(root,val);
					
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
				  
           		root = deleteNode(root,x);
			}
			 break;
		case 4: 
        	{
        		int x;
        		struct Node * tmp;
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
            printInorder(root);
            break;
        case 6:    
        	printf("\n Preorder Traversal of Binary Search Tree -\n\n"); 
            printPreorder(root);
            break;
        case 7:    
        	printf("\n Postorder Traversal of Binary Search Tree -\n\n"); 
            printPostorder(root);
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
//    
//  root = insertNode(root, 2);
//  root = insertNode(root, 1);
//  root = insertNode(root, 7);
//  root = insertNode(root, 4);
//  root = insertNode(root, 5);
//  root = insertNode(root, 3);
//  root = insertNode(root, 8);
//
//  printPreOrder(root);
//
//  root = deleteNode(root, 3);
//
//  printf("\nAfter deletion: ");
//  printPreOrder(root);
//
//  return 0;
}
