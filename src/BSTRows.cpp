/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void left_to_right(struct node *root, struct node **node_arr, int *mem)
{
	int i = 0;
	int k = 0;
	node_arr[i] = root;
	while (node_arr[i] != NULL)
	{
		
		mem[i] = node_arr[i]->data;
		if (node_arr[i]->right)
		{
			node_arr[k+1] = node_arr[i]->right;
			k++;
		}
		if (node_arr[i]->left)
		{
			node_arr[k+1] = node_arr[i]->left;
			k++;
		}
		i++;
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
		return NULL;
	struct node **node_arr = (struct node **)malloc(sizeof(struct node *) * 20);
	int *mem = (int *)malloc(sizeof(int) * 20);
	for (int i = 0; i < 20; i++)
	{
		node_arr[i] = NULL;
		mem[i] = 0;
	}
	left_to_right(root, node_arr, mem);
	return mem;
}
