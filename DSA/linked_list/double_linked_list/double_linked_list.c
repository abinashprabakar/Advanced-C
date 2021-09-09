/* This program implements the working of Double Linked list
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 08.09.2021
 * Author : Abinash
 */

#include<stdio.h>	/* required for printf */
#include<stdlib.h>	/* required for malloc */

/* defining node structure */
typedef struct node 
{
	int data;
	struct node *prev;
	struct node *next;
}NODE;

/* add_function to add element at the starting
 *
 * @param[in] head, n
 * @param[out] head, current
 */
NODE *add_first(NODE *head, int n)
{
	NODE *current;
	current = (NODE *)malloc(sizeof(NODE));
	current->data = NULL;
	current->next = current->prev = NULL;

	if(head == NULL)	/* if head is empty */
	{
		current->data = n;
		head = current;
	}
	else
	{
		current -> data = n;
		current->prev = NULL;
		current->next = head;
		head = current;
	}
	return head;
}

/* add_function to add element at the last
 *
 * @param[in] head, n
 * @param[out] head, current
 */
NODE *add_last(NODE *head, int n)
{
	NODE *current;
	current = (NODE*)malloc(sizeof(NODE));
	current->data = NULL;
	current->next = current->prev = NULL;

	if(head == NULL)
	{
		current->data = n;
		head = current;
	}
	else
	{
		NODE *temp = head;
		while(temp->next)
			temp = temp->next;
		
		current->data = n;
		temp->next = current;	/* forward linking */
		current->prev = temp;	/* backward linking */
	}
	return head;
}

/* delete_function to delete the element at desired position
 *
 * @param[in] head, n
 * @param[out] head, current
 */
NODE *del_node(NODE *head,int n)
{
	if(head == NULL)      /* if head is empty */
	{
		printf("list is empty\n");
		return NULL;
	}

	NODE *current = head;
	if(current->data == n && current->prev==NULL)    /* delete at first */
	{
		
		if(current->next)
		{
			head = current->next;
			head->prev = NULL;
			free(current);
		}
		else
		{
			free(current);
			head = NULL;
		}
	}
	else{
		current = current->next;

       		while(current && n != current->data)     /* delete at lst and middle */
		{
			current = current->next;
		}

		if(current==NULL)
		{
			printf("node not found...\n");
		}
		else
		{
			current->prev->next = current->next;
			if(current->next)
				current->next->prev = current->prev;
			free(current);
		}
	}
	return head;
}




/* This function will display all node in list
 * 
 * @param[in] head
 */

void display(NODE *head)
{
	if(head == NULL)
	{
		printf("List is empty...\n");
	}
	else
	{
		NODE *temp = head;
		while(temp)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}

/* main program */
int main()
{
	/* hold the reference to list */
	NODE *head = NULL;
	/* calling display function */
	display(head);
	head = del_node(head,10);

	/* adding node at last */
	head = add_last(head,10);
	head = add_last(head,20);
	head = add_last(head,30);
	head = add_last(head,40);

	/* adding nodes at first */
	head = add_first(head,5);
	head = add_first(head,1);
	head = add_first(head,3);
	head = add_first(head,5);

	/* calling display function */
	display(head);
	printf("\n");
    	head = del_node(head,5);
	display(head);
	printf("\n");
	head = del_node(head,40);
	display(head);
	printf("\n");
	head = del_node(head,10);
	display(head);
	printf("\n");


	return 0;
}

