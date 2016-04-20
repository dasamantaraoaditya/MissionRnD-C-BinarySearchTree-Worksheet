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


void fill_the_queue(struct node * root, struct node ** queue, int start, int index);
int* BSTRighttoLeftRows(struct node* head)
{
	if (head == NULL)
		return NULL;
	struct node * root = head;
	struct node ** queue = (struct node **)malloc(sizeof(struct node*) * 100);
	fill_the_queue(head, queue, 0, 0); int i = 0;
	int * array = (int *)malloc(sizeof(int) * 100);
	array[i++] = root->data;
	for (; queue[i - 1] != NULL; i++)
		array[i] = queue[i - 1]->data;
	array[i] = '\0';
	return array;
}
void fill_the_queue(struct node * root, struct node ** queue, int start, int index)
{
	if (start <= index)
	{
		if (root != NULL)
		{
			if (root->right != NULL)
			{
				queue[index++] = root->right;
			}
			if (root->left != NULL)
			{
				queue[index++] = root->left;
			}
		}
		fill_the_queue(queue[start], queue, start + 1, index);
	}
	else
		queue[index] = NULL;
}

