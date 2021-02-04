/*B171681*/
#include<stdio.h>
#include<stdlib.h>
struct tnode{
	struct tnode *left;
	int e;
	struct tnode *right;
};
struct que{
	struct tnode *a[20];
	int f;
	int r;
};
struct que* enqueue(struct que *q,struct tnode *ele)
{
	q->r++;
	q->a[q->r]=ele;
	return q;
}
struct tnode * dequeue(struct que *q)
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
void print(struct tnode *root)
{
	struct tnode *temp1;
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
struct tnode * insert(struct tnode *root)
{
	int ele;
	printf("enter the element to insert:");
	scanf("%d",&ele);
	if(root==NULL)
	{
		root=(struct tnode *)malloc(sizeof(struct tnode));
		root->e=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		struct tnode *nn;
		nn=(struct tnode *)malloc(sizeof(struct tnode));
		nn->e=ele;
		nn->left=NULL;
		nn->right=NULL;
		struct tnode *temp;
		
		while(1)
		{
			if(temp->e>ele)
			{
				if(temp->left!=NULL)
					temp=temp->left;
				else
				{
					temp->left=nn;
					break;
				}
			}
			else
			{
				if(temp->right!=NULL)
					temp=temp->right;
				else
				{
					temp->right=nn;
					break;
				}
			}
		}
	}
	return root;
}
struct tnode * search(struct tnode *root,int ele)
{
	int f=0;
	struct tnode *temp=root;
	
	while(1)
	{
		if(temp->e==ele)
		{
			f=1;
			break;
		}
		else if(temp->e>ele)
		{
			if(temp->left!=NULL)
			{
				temp=temp->left;
			}
			else
				break;
		}
		else
		{
			if(temp->right!=NULL)
			{
				temp=temp->right;
			}
			else
				break;
		}
	}
	if(f==1)
	{
		printf("the element found in the list\n");
		return root;
	}
	else
	{
		printf("the element  not found in the list\n");
		return NULL;
	}
}
void preorder(struct tnode *root)
{
	if(root!=NULL)
	{
		printf("%d",root->e);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct tnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->e);
		inorder(root->right);
	}
}
void postorder(struct tnode *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->e);
	}
}
void main()
{
	struct tnode *root=NULL;
	int op,ele,f;
	do{
	printf("enter the option\n1.insert the element\n2.to search the element\n3.To print in preorder\n4.To print in inorder\n5.To print in  postorder\n5.delete the element\n6.exit:");
	scanf("%d",&op);
		switch(op)
		{
			case 1:
				root=insert(root);
				print(root);
				break;
			case 2:
				printf("enter the element to search:");
				scanf("%d",&ele);
				root=search(root,ele);
				break;
			case 3:
				printf("elements in preorder\n");
				preorder(root); 
				break;
			case 4:
				printf("\nelements in inorder\n");
				inorder(root); 
				break;
			case 5:
				printf("\nelements in postorder\n");
				postorder(root); 
				printf("\n");
				break;
			default:
				printf("invaild option\n");
				break;
		}
	}
	while(op!=6);
}

