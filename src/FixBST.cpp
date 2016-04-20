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
struct node *previous_node = NULL, *left_misplaced_node = NULL, *right_misplaced_node = NULL;
void identify_misplaced_nodes(struct node * current_node);
void fix_bst(struct node *root){
	if (root == NULL)
		return;
	identify_misplaced_nodes(root);
	int temp = left_misplaced_node->data;
	left_misplaced_node->data = right_misplaced_node->data;
	right_misplaced_node->data = temp;
	previous_node = NULL, left_misplaced_node = NULL, right_misplaced_node = NULL;
}
void identify_misplaced_nodes(struct node * current_node)
{
	if (current_node == NULL)
		return;
	identify_misplaced_nodes(current_node->left);
	if (previous_node != NULL&&previous_node->data > current_node->data)
	{
		if (left_misplaced_node == NULL)
			left_misplaced_node = previous_node;
		right_misplaced_node = current_node;
	}
	previous_node = current_node;
	identify_misplaced_nodes(current_node->right);

}
