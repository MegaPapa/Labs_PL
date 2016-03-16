#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};

tree *root = NULL;

struct tree *stree(struct tree *root,struct tree *r,char info)
{
	if (!r) {
		r = (struct tree *) malloc(sizeof(struct tree));
		if (!r) {
			printf("Не хватает памяти\n");
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->info = info;
		if (!root) return r; /* первый вход */
		if (info < root->info) root->left = r;
		else root->right = r;
		return r;
	}
	if (info < r->info)
		stree(r, r->left, info);
	else
		stree(r, r->right, info);
	return root;
}

void print_tree(struct tree *r, int l)
{
	int i;

	if (r != NULL)
	{
		print_tree(r->right, l + 1);
		for (i = 1; i <= l; i++) printf(" ");
		printf("%d\n",r->info);
		print_tree(r->left, l + 1);
	}
}


void Remove(int value)
{
	tree *pointer = root;
	tree *parent = NULL;

	while (pointer != NULL && pointer->info != value)
	{
		parent = pointer;
		if (value < pointer->info)
			pointer = pointer->left;
		else
			pointer = pointer->right;
	}

	if (pointer != NULL)
	{
		tree *removed = NULL;

		if (pointer->left == NULL || pointer->right == NULL)
		{
			tree *child = NULL;
			removed = pointer;

			if (pointer->left != NULL)
				child = pointer->left;
			else if (pointer->right != NULL)
				child = pointer->right;

			if (parent == NULL)
				root = child;
			else
			{
				if (parent->left == pointer)
					parent->left = child;
				else
					parent->right = child;
			}
		}
		else 
		{
			tree * mostLeft = pointer->right;
			tree * mostLeftParent = pointer;

			while (mostLeft->left != NULL)
			{
				mostLeftParent = mostLeft;
				mostLeft = mostLeft->left;
			}

			pointer->info = mostLeft->info;
			removed = mostLeft;

			if (mostLeftParent->left == mostLeft)
				mostLeftParent->left = NULL;
			else
				mostLeftParent->right = NULL;
		}

		delete removed;
	}
}

void main()
{
	int Menu = -1,temp = 0;
	while (Menu != 0)
	{
		printf("Enter operation: 1 - Add element, 2 - Delete element, 3 - View tree, 0 - Exit\n");
		scanf_s("%d",&Menu);
		switch (Menu)
		{
			case 1:
			{
				printf("Enter value: ");
				scanf_s("%d",&temp);
				if (root == NULL)
					root = stree(root,root,temp);
				else
					stree(root, root, temp);
				system("cls");
				break;
			}
			case 2:
			{
				printf("Enter who deleting: ");
				scanf_s("%d", &temp);
				Remove(temp);
				system("cls");
				break;
			}
			case 3:
			{
				system("cls");
				printf("Tree:\n");
				print_tree(root,1);
				break;
			}
		}
	}
}