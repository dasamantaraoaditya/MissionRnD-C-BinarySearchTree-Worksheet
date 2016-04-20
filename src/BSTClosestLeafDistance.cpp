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
int get_leaf_distance(struct node * root);
int MIN(int num1, int num2);
int find_closest_node(struct node * root, struct node * temp, struct node *intermediate_nodes[], int index);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;

	struct node * intermediate_nodes[100];
	return find_closest_node(root, temp, intermediate_nodes, 0);
}

int get_leaf_distance(struct node * root)
{
	if (root == NULL)
		return 1000;

	if (root->right == NULL&&root->left == NULL)
		return 0;
	return 1 + MIN(get_leaf_distance(root->left), get_leaf_distance(root->right));
}

int find_closest_node(struct node * root, struct node * temp, struct node *intermediate_nodes[], int index)
{
	if (root == NULL)
		return 10000;

	if (root == temp)
	{
		int root_to_leaf = get_leaf_distance(root);
		int min_distance = get_leaf_distance(root), i;
		for (i = index - 1; i >= 0; i--)
			min_distance = MIN(min_distance, index - i + get_leaf_distance(intermediate_nodes[i]));
		return min_distance;
	}
	intermediate_nodes[index] = root;
	return MIN(find_closest_node(root->left, temp, intermediate_nodes, index + 1), find_closest_node(root->right, temp, intermediate_nodes, index + 1));

}

int MIN(int num1, int num2)
{
	if (num1>num2)
		return num2;
	return num1;
}
