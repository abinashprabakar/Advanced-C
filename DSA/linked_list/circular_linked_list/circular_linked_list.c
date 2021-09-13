/* This program implements the operation of circular linked list
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 13.09.2021
 * Author : Abinash
 */

#include<stdio.h>	/* required for printf */
#include<stdlib.h>

/* defining node structure */
typedef struct node{
	int data;
	struct node *next;
}NODE;

/**
 * This function add node to list 
 * @param[in] head
 * @param[in] n
 * @param[out] head
 */

NODE *add_node(NODE *head,int n)
{
	/* allocating memory for new node */
	NODE *new = (NODE *)malloc(sizeof(NODE));

	/* if list is empty */
	if(head == NULL)
	{
		new->data = n;
		new->next = NULL;
		head = new;
		
	}
	else
	{
		NODE *current = head;
		while(current->next != NULL && current->next !=head)
		{
			current = current->next;
		}
		new->data = n;
		current->next = new;
		new->next = head;
	}
	return head;
}

/**
 * This function will add the new node at first to the list
 * @param[in] head
 * @param[in] n
 * @param[out] head
 */

NODE *add_first(NODE *head,int n)
{
	/* allowcating memory for new node */
	NODE *new = (NODE *)malloc(sizeof(NODE));

	/* if list is empty */
	if(head == NULL)
	{
		new->data = n;
		new->next = NULL;
		head = new;
	}
	else
	{
		NODE *current = head;
		while(current->next !=head)
		{
			current = current->next;
		}
		new->data = n;
		new->next = head;
		current->next = new;
		head = new;
	}
	return head;
}

/**
 * This program will remove node from list
 * @param[in] head
 * @param[in] n
 * @param[out] head
 */


NODE *del_node(NODE *head,int n)
{
	NODE *current = head;
	NODE *prev = NULL;
	if(current == NULL)
	{
		printf("list is empty\n");
		return NULL;
	}
	else if(current->next == head)
	{
		head = NULL;
		free(current);
	}
	else if(current->data != n)
	{
		while(current->next != head && current->data !=n)
		{
			prev = current;
			current = current->next;
		}
		if(current->data == n)
		{
			prev->next = current->next;
			free(current);
		}
		else
		{
			printf("node not found...\n");
		}
	}
	else
	{
		prev = current;
		while(current->next != head)
		{
			current = current->next;
		}
		current->next = prev->next;
		head = prev->next;
		free(prev);
	}
			
	return head;
}





/**
 * This function displays the node 
 * @param[in] head
 */

void display(NODE *head)
{
	NODE *current = head;
	if(current == NULL)
	{
		printf("node is empty...\n");
	}
	else
	{
		do
		{
			printf("%d ",current->data);
			current = current->next;
		}while(current!=head);
	}
}

/* main program */
int main()
{
	/* hold the reference to first node of list */
	NODE *head = NULL;
	display(head);
	head = del_node(head,10);
	head = add_node(head,10);
	head = add_node(head,20);
	head = add_node(head,30);
	display(head);
	printf("\n");
	head = add_first(head,50);
	head = add_first(head,70);
	display(head);
	printf("\n");
	head = del_node(head,70);
	display(head);
	printf("\n");
	head = del_node(head,10);
	display(head);
	printf("\n");
	head = del_node(head,30);
	display(head);
	printf("\n");
	return 0;
}
