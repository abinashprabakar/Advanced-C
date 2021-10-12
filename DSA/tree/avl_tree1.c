#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *left,*right;
}NODE;


void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(NODE *root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(NODE *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}


int tree_height(NODE *root)
{
	int l_height=0,r_height=0;
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		l_height = tree_height(root->left);
		r_height = tree_height(root->right);

		if(r_height>l_height)
		{
			return r_height+1;
		}
		else
		{
			return l_height+1;
		}
	}
}

int balance_factor(NODE *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return(tree_height(root->left) - tree_height(root->right));
	}
}

NODE *right_rotate(NODE *root)
{
	NODE *x = root->left;
	NODE *y = x->right;

	//rotation
	x->right = root;
	root->left = y;

	return x;
}

NODE *left_rotate(NODE *root)
{
	NODE *x = root->right;
	NODE *y = x->left;

	//rotation
	x->left = root;
	root->right = y;

	return x;
}


NODE *create_node(int val)
{
	NODE *new_node = (NODE *)malloc(sizeof(NODE));
	new_node->data = val;
	new_node->left=new_node->right = NULL;

	return new_node;
}

NODE *insert_node(NODE *root,NODE *new)
{
       int bf;
       if(root == NULL)
       {
               return new;
       }
       if(new->data>root->data)
       {
               root->right = insert_node(root->right,new);
       }
       else if(new->data < root->data)
       {
               root->left = insert_node(root->left,new);
       }
       bf = balance_factor(root);
       //left Rotation
       if((bf<-1) && new->data> root->right->data)
       {
               return left_rotate(root);
       }
       //right rotation
       if((bf>1) && new->data < root->left->data)
       {
               return right_rotate(root);
       }
       //right - left rotation
       if((bf<-1) && new->data < root->right->data)
       {
               root->right = right_rotate(root->right);
               return left_rotate(root);
       }
       //left - right rotation
       if((bf>1) && new->data > root->left->data)
       {
               root->left = left_rotate(root->left);
               return right_rotate(root);
        }
	return root;
}

int main()
{
	NODE *root = NULL;
	NODE *node = NULL;

	int arr[] = {3,7,15,18,13,16,12,14,2,11,17};
	int i;
	for(i=0;i<11;i++)
	{
		node = create_node(arr[i]);

		root = insert_node(root,node);
	}

	printf("inorder: ");
	inorder(root);
	printf("\n");
	printf("preOrder: ");
	preorder(root);
	printf("\n");
	printf("postOrder: ");
	postorder(root);
	printf("\n");
	printf("Height of tree : %d\n",tree_height(root));
	printf("balance factor of root : %d\n",balance_factor(root));
	return 0;
}

