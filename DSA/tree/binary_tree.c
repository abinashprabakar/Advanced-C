/* This program implements about the working of binary tree
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 28.09.21
 * 
 * Author : Abinash
 */

#include<stdio.h>	/* required for printf */
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *right,*left;
}NODE;



struct node *create()
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	int val;
	printf("enter value : ");
	scanf("%d",&val);
	temp->data = val;
	if(val == -1)
	{
		return NULL;
	}
	temp->right = temp->left = NULL;
	printf("Enter left child of %d\n",val);
	temp->left = create();
	printf("Enter  right child of %d\n",val);
	temp->right = create();

	return temp;
}


void preorder(NODE *root)
{
	
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
	
}

void postorder(NODE *root)
{
	
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
	
}

void inorder(NODE *root)
{
	
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
	
}

/* main program */
int main()
{
	NODE *root = NULL;

	root = create();
	printf("PreOrder: ");
	preorder(root);
	printf("\n");
	printf("InOrder: ");
	inorder(root);
	printf("\n");
	printf("PostOrder: ");
	postorder(root);
	printf("\n");

	return 0;
}
