/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int count_path(struct node* root,struct node*temp,int* found,int *ex,int *h)
{
	if (root == NULL)
		return -1;
	if (root->left == NULL && root->right == NULL)
		return 0;
	int left = count_path(root->left,temp,found,ex,h);
	int right = count_path(root->right,temp,found,ex,h);
	if (root == temp)
	{
		*found = 1;
	}
	if (*found == 1)
	{
		int min = 0;
		if (left == -1)
			min= right + 1;
		else if (right == -1)
			min= left + 1;
		else if (left < right)
			min= left + 1;
		else
			min= right + 1;
		if (min + *h < *ex)
			*ex = min + *h;
		*h += 1;
	}
	if (left == -1)
		return right+1;
	if (right == -1)
		return left + 1;
	if (left < right)
		return left + 1;
	return right + 1;
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int found = 0;
	int extra = 99999;
	int h = 0;
	count_path(root, temp, &found,&extra,&h);
	return extra;
}