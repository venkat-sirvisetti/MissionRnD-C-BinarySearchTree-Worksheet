/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void fix(struct node *root, struct node**one, struct node **two)
{
	if (root->left != NULL)
	{
		if (!(root->data >= root->left->data))
		{
			if (*one == NULL)
				*one = root;
			else
				*two = root;
		}
	}
	if (root->right != NULL)
	{
		if (!(root->data <= root->right->data))
		{
			if (*one == NULL)
				*one = root;
			else
				*two = root;
		}
	}
	if (root == NULL)
		return;
	fix(root->left, one, two);
	fix(root->right, one, two);
}
void fix_bst(struct node *root){
	int temp = 0;
	if (root == NULL)
		return;
	struct node* one = NULL, *two = NULL;
	fix(root, &one, &two);
	temp = one->data;
	one->data = two->data;
	two->data = temp;
}
