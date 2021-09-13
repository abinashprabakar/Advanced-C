/*This program implements the working of single linked list
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 08.09.2021
 * Author : Abinash
 */

#include<stdio.h>     /* required for printf */
#include<stdlib.h>    /* required for structures */

/* defining structure for node */
typedef struct listnode{
	int data;
	struct listnode *next;
}*ListNodePtr;

typedef struct list{
	ListNodePtr head;
}List;


/*
 * insertion function. it will add new node to the linked list at front
 * @param[in] self
 * @param[in] data
 */
void insert_front(List *self,int data)
{
	ListNodePtr new_node = malloc(sizeof(*new_node));
	new_node->data = data;
	new_node->next = self->head;
	self->head = new_node;
	
}

/*
 * it will add new node to linked list in  order based on the data
 * @param[in] self
 * @param[in] data
 */
void insert_order(List *self,int data)
{
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;
	
	ListNodePtr new_node = malloc(sizeof(*new_node));
	new_node->data = data;
	new_node->next = NULL;

	while(current!=NULL && current->data <data)
	{
		prev = current;
		current = current->next;
	}

	if(current = self->head)
	{
		new_node->next = current;
		self->head = new_node;
	}
	else
	{
		new_node->next = current;
		prev->next = new_node;
	}
}

/*
 * it will delete  nodes
 * @param[in] self
 * @param[in] data
 */
void delete_list(List *self,int data)
{
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while(current!=NULL)
	{
		if(current->data == data)
		{
			if(prev == NULL)
			{
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else
			{
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else
		{
			prev = current;
			current = current->next;
			
		}
	}
}

/*
 * this will destroy the complete list 
 * @param[in] self
 */
void destroy_list(List *self)
{
	ListNodePtr current = self->head;
	ListNodePtr temp;
	while(current!= NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	self->head = NULL;
}

/*
 * display function to display all nodes in list
 * @param[in] self
 */
void display_all(List *self)
{
	ListNodePtr temp;
	temp = self->head;
	
	while(temp!=NULL)
	{
	
		printf("data : %d\n",temp->data);
		temp = temp->next;
	}

}
/* main program */
int main()
{
	/* hold the first(head) node reference */
	List self;
	self.head = NULL;
	int i;
	/* adding 5 nodes to list */
	for(i=0;i<5;i++)
	{
		insert_front(&self,i+30);
	}
	display_all(&self);
	insert_order(&self,10);
	insert_order(&self,20);
	display_all(&self);
	insert_order(&self,10);
	insert_order(&self,10);
	display_all(&self);
	delete_list(&self,10);
	display_all(&self);
	destroy_list(&self);

	return 0;

}
