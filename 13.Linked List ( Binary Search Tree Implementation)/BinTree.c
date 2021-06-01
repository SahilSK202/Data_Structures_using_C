
#include<stdio.h>
#include<stdlib.h>


struct treenode
{
	int data;
	struct treenode *left , *right;
};



struct treenode *create()
{
	struct treenode *newnode;
	int x;
	newnode = (struct treenode *)malloc(sizeof(struct treenode));
	printf("\nEnter the data (-1 for no node) : ");
	scanf("%d", &x);
	if(x == -1)
	{
		return NULL;
	}
	newnode -> data = x;
	printf("\nEnter left child of %d", x);
	newnode->left = create();
	printf("\nEnter right child of %d", x);
	newnode->right = create();
	return newnode;
}


void Preorder(struct treenode * root)
{
	if(root == NULL)
	{
		return;
	}
	
	printf("%d\t" , root->data);
	Preorder(root->left);
	Preorder(root->right);
}


void Inorder(struct treenode * root)
{
	if(root == NULL)
	{
		return;
	}
	
	Inorder(root->left);
	printf("%d\t" , root->data);
	Inorder(root->right);
}


void Postorder(struct treenode * root)
{
	if(root == NULL)
	{
		return;
	}
	
	Postorder(root->left);
	Postorder(root->right);
	printf("%d\t" , root->data);
}



int main()
{
	struct treenode *root;
	root = NULL;
	root = create();
	printf("\nRoot is %d" , root->data);
	
	printf("\nPre-order of tree is :\n ");
	Preorder(root);
	
	printf("\nIn-order of tree is :\n ");
	Inorder(root);
	
	printf("\nPost-order of tree is :\n ");
	Postorder(root);
	
	return 0;
}















