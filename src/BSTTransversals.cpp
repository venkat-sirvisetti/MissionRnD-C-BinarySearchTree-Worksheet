/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void my_inorder(struct node* root, int *arr, int *index)
{
	if (root == NULL)
		return;
	my_inorder(root->left, arr, index);
	*(arr + *index) = root->data;
	*index += 1;
	my_inorder(root->right, arr, index);
}

void inorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL)
		return;
	my_inorder(root, arr,&index);
}

void my_preorder(struct node* root, int *arr, int *index)
{
	if (root == NULL)
		return;
	
	*(arr + *index) = root->data;
	*index += 1;
	my_inorder(root->left, arr, index);
	my_inorder(root->right, arr, index);
}
void preorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL)
		return;
	my_preorder(root, arr, &index);
	
}

void my_postorder(struct node* root, int *arr, int *index)
{
	if (root == NULL)
		return;
	my_inorder(root->left, arr, index);
	my_inorder(root->right, arr, index);
	*(arr + *index) = root->data;
	*index += 1;
}
void postorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL)
		return;
	my_postorder(root, arr, &index);
	
}

