#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head,*tail = NULL;

void addnode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;

	if(head == NULL)
	{
		head = tail = temp;
		head->prev = NULL;
		tail->next = NULL;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		tail->next = NULL;
	}
}

void sortlist()
{
	struct node *current = NULL, *p = NULL;
	int temp;
	if(head == NULL)
		printf("List is empty\n");
	else
	{
		for(current=head; current->next!=NULL; current=current->next)
		{
			for(p = current->next;p!=NULL;p=p->next)
			{
				if(current->data > p->data)
				{
					temp = current->data;
					current->data = p->data;
					p->data = temp;
				}
			}
		}
	}
}

void reverse()
{
	struct node *current= head, *temp;
	while(current!=NULL)
	{
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;

		current = temp;
	}
	temp = head;
	head = tail;
	tail = temp;
}

void display()
{
	struct node *current = head;
	if(head == NULL)
		printf("List is empty\n");
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

int main()
{
	int n, i;
	for(i=0; i<=10; i++)
	{
		n = rand() % 101;
		printf("%d ",n);
		addnode(n);
	}
	//addnode(n);
	printf("\nBefore Sorting \n");
	display();
	
	sortlist();
	printf("After sorting in ascending order\n");
	display();

	reverse();
	printf("After reversing \n");
	display();
	return 0;
}
