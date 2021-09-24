#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;
void append()
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the node data to add at end : \n");
	scanf("%d",&temp->data);
	temp->prev = NULL;
	temp->next = NULL;

	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		struct node *p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
		temp->prev = p;
	}
}
void add_atbegin()
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the node data to add at begin : \n");
	scanf("%d",&temp->data);
	temp->prev = NULL;
	temp->next = NULL;
	
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

int length()
{
	struct node *temp = head;
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void display()
{
	struct node *temp = head;
	if(temp == NULL)
	{
		printf("List is empty \n");
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void add_atafter()
{
	struct node *temp, *p;
	int i=1, loc, len = length();
	printf("Enter the location to add the new node : \n");
	scanf("%d",&loc);
	
	if(loc > len)
	{
		printf("Invalid Location\n");
		printf("List contains only %d nodes",len);
		printf("\n");
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter node data to be added at specified location : \n");
		scanf("%d",&temp->data);
		temp->next = NULL;
		temp->prev = NULL;
		p = head;
		
		while(i < loc)
		{
			p = p->next;
			i++;
		}
		temp->next = p->next;
		p->next->prev = temp;

		temp->prev = p;
		p->next = temp;

	}
}

int main()
{
	int option; 
	printf("1. Add at Starting\n2. Add at the specified location\n3. Add at the end\n4. display\n");
	printf("5. length\n6. Exit\n");
	printf("Enter the option to perform the operation:\n");
	scanf("%d",&option);

	while(1)
	{
	switch(option)
	{
	
		case 1 : add_atbegin();
			 break;

		case 2 : add_atafter();
 	 	 	 break;

		case 3 : append();
			 break;

		case 4 : display();
			 break;

		case 5 : 
		{
			int len = length();
			printf("The size of linked list is : %d\n",len);
			break;
		}

		case 6 : exit(0);
		 	 break;

		default : printf("Invalid option !!!\n");
		
	}
	}	
}	
