/* This program implements the working of binary search tree
 *
 * Trees are hierarchical data structure ( items are linked to each other in parent-child relationships in an overall
 * tree structure)
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 28.09.2021
 * Author : Abinash
 */

#include<stdio.h>   /* required for printf */
#include<stdlib.h>  /* required for malloc(), free() */

/* declaring BST node */
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}bst;

/**
 * this function will add new node to BST
 * @param[in] head
 * @param[in] data
 * @param[out] head
 */
bst *add_node(bst *head,int data)
{
	if(head == NULL)
	{
		head = (bst *)malloc(sizeof(bst *));
		head->data = data;
		head->left=head->right = NULL;
	}
	else if(head->data >data)
	{
		head->left = add_node(head->left,data);
	}
	else if(head->data <data)
	{
		head->right = add_node(head->right,data);
	}
	return head;
}

/**
 * this function will finds the min node from right subtree
 * @param[in] head
 * @param[out] min_node
 */
bst *find_min(bst *head)
{
	bst *current = head;
	while(current->left !=NULL)
	{
		current = current->left;
	}
	return current;
}

/** 
 * This function will delete a node in BST 
 * @param[in] head
 * @param[in] data
 * @param[out] head
 */
bst *del_node(bst *head,int data)
{
	if(head!=NULL)
	{
		if(data = head->data)  /* found node to delete */
		{
			if(head->left!=NULL && head->right!=NULL) /* if node has 2 childs */
			{
				bst *temp = find_min(head->right);
				head->data = temp->data;
				head->right = del_node(head->right,data);
			}
			else                                        /* if node has one child or 0 */
			{
				bst *temp = head;
				if(head->right)
				{
					head = head->right;
				}
				else
				{
					head = head->left;
				}
				free(temp);
			}
		}
		else if(data < head->data)
		{
			head->left = del_node(head->left,data);
		}
		else
		{
			head->right = del_node(head->right,data);
		}
	}
	return head;
}


/**
 *  printing nodes in preorder method 
 *  @param[in] head
 */
void preorder(bst *head)
{
	if(head!=NULL)
	{
	     printf("%d ",head->data);
	     preorder(head->left);
	     preorder(head->right);
	}
}
/**
 * printing data in inorder method
 * @param[in] head
 */
void inorder(bst *head)
{
	if(head)
	{
		inorder(head->left);
		printf("%d ",head->data);
		inorder(head->right);
	}
}
/**
 * printing data in postorder method
 * @param[in] head
 */
void postorder(bst *head)
{
	if(head)
	{
		postorder(head->left);
		postorder(head->right);
		printf("%d ",head->data);
	}
}

/* main program starts */

int main()
{
	/* to hold the root node of BST */
	bst *head = NULL;
	int arr[] = {10,20,30,4,3,5,6,45,63,76},i;
	for(i=0;i<10;i++)
	{
		head = add_node(head,arr[i]);
	}
	/* deleting a node with value 10 from BST */
	head = del_node(head,10);
	printf("PreOrder: ");
	preorder(head);
	printf("\n");
	printf("InOrder: ");
	inorder(head);
	printf("\n");
	printf("PostOrder: ");
	postorder(head);
	printf("\n");
}
