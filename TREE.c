/*B171681*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int e;
	struct node *right;
};
struct que{
	struct node *a[20];
	int f;
	int r;
};
struct que* enqueue(struct que *q,struct node *ele)
{
	q->r++;
	q->a[q->r]=ele;
	return q;
}
struct node * dequeue(struct que *q)
{
	if(q->f==q->r)
		return NULL;
	else
	{
		q->f++;
		return q->a[q->f];
	}
}
int isempty(struct que *q)
{
	if(q->f==q->r)
		return 1;
	else
		return 0;
}
int count(struct node *root)
{
	int c=0;
	struct node *temp1;
	struct que *q;
	q=(struct que *)malloc(sizeof(struct que));
	q->r=-1;
	q->f=-1;
	q=enqueue(q,root);
	while(!isempty(q))
	{
		temp1=dequeue(q);
		c++;
		printf("%d\t",temp1->e);
		if(temp1->left!=NULL)
		{
			q=enqueue(q,temp1->left);
		}
		if(temp1->right!=NULL)
		{
			q=enqueue(q,temp1->right);
		}
	}
	return c;
}
void print(struct node *root)
{
	struct node *temp1;
	struct que *q;
	q=(struct que *)malloc(sizeof(struct que));
	q->r=-1;
	q->f=-1;
	q=enqueue(q,root);
	while(!isempty(q))
	{
		temp1=dequeue(q);
		printf("%d\t",temp1->e);
		if(temp1->left!=NULL)
		{
			q=enqueue(q,temp1->left);
		}
		if(temp1->right!=NULL)
		{
			q=enqueue(q,temp1->right);
		}
	}
}
struct node * insert(struct node *root)
{
	int ele;
	printf("enter the element to insert:");
	scanf("%d",&ele);
	if(root==NULL)		
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->e=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		struct node *temp,*temp1;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->e=ele;
		temp->left=NULL;
		temp->right=NULL;
		struct que *q;
		q=(struct que*)malloc(sizeof(struct que));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			else
			{
				temp1->left=temp;
				break;
			}
			if(temp1->right!=NULL)
			{
				q=enqueue(q,temp1->right);
			}
			else
			{
				temp1->right=temp;
				break;
			}
		}
	}
	return root;
}
void search(struct node * root,int k)
{
	if(root==NULL)
	{
		printf("the tree is empty");
		
	}
	else
	{
		struct node *temp;
		int f=0;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp=dequeue(q);
			if(temp->left!=NULL)
				q=enqueue(q,temp->left);
			if(temp->right!=NULL)
				q=enqueue(q,temp->right);
			if(temp->e==k)
			{
				f=1;
				break;
			}
		
		}
		if(f==1)
		{
			printf("the element is found in list\n");
		
		}
		else
			printf("the element is not in the list\n");
	}
}	
struct node * find(struct node * root,int k)
{
	if(root==NULL)
	{
		printf("the tree is empty");
		return root;
	}
	else
	{
		struct node *temp;
		int f=0;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp=dequeue(q);
			if(temp->left!=NULL)
				q=enqueue(q,temp->left);
			if(temp->right!=NULL)
				q=enqueue(q,temp->right);
			if(temp->e==k)
			{
				f=1;
				break;
			}
		
		}
		if(f==1)
		{
			printf("the element is found in list\n");
			return temp;
		}
		else
			return NULL;
	}
}	
struct node * last_node(struct node * root)
{
	if(root==NULL)
	{
		printf("the tree is empty");
		return root;
	}
	else
	{
		struct node *temp1;
		int f=0;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
				q=enqueue(q,temp1->left);
			if(temp1->right!=NULL)
				q=enqueue(q,temp1->right);
		}
		return temp1;
	}
}
struct node * parent_node(struct node *root,struct node *temp1)
{
	if(root==NULL)
	{
		printf("the tree is empty");
		return root;
	}
	else
	{
		struct node *temp2;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp2=dequeue(q);
			if(temp2->left==temp1)
			{
				return temp2;
			}
			else
			{
			if(temp2->left!=NULL)
				{
					q=enqueue(q,temp2->left);
				}
			}
			if(temp2->right==temp1)
			{
				return temp2;
			}
			else
			{
				if(temp2->right!=NULL)
				{
					q=enqueue(q,temp2->right);
				}
			}
		}
		return NULL;
	}
}
struct node * delete(struct node *root,int val)
{
	if(root==NULL)
	{
		printf("the tree is empty");
		return root;
	}
	struct node *temp,*temp1,*temp2;
	temp=find(root,val);
	if(temp!=NULL)
	{
		temp1=last_node(root);
		temp2=parent_node(root,temp1);
		temp->e=temp1->e;
		if(temp2->left==temp1)
			temp2->left=NULL;
		else
			temp2->right=NULL;
		return root;
	}
}
void main()
{
	struct node *root=NULL;
	int op,ele;
	do{
	printf("enter the option\n1.insert the element\n2.delete the element\n3.To search the element:\n4.count the number of elements:\n5.print the elements\n6.exit:");
	scanf("%d",&op);
		switch(op)
		{
			case 1:
				
				root=insert(root);
				print(root);
				break;
			case 2:
				printf("enter the element that u want to delete:");
				scanf("%d",&ele);
				root=delete(root,ele);
				print(root);
				break;
			case 3:
				printf("enter the element that u want to search:");
				scanf("%d",&ele);
				search(root,ele);
				break;
			case 4:
				printf("the number of elements in list is == %d\n",count(root));
				break;
			case 5:
				print(root);
				break;
			default:
				break;
		}
	}
	while(op!=6);
}

