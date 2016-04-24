/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void inorder1(struct node *root,int* i){
	if (root == NULL)return;
	inorder1(root->left, i);
	(*i) = ((*i) - root->data);
	inorder1(root->right, i);
}
int get_missing_value(struct node *root,int n){
	if (root == NULL || n == 0)return -1;
	if (n >= -10000 && n <= 10000){
		//int *arr = (int*)calloc(n, sizeof(int));
		int *index = (int*)calloc(1, sizeof(int));
		//finding some of numbers.
		int sum = n*(n + 1) / 2;
		*index = sum;
		inorder1(root,index);
		//quicksort(arr, 0, n - 1);
		int x = (*index);
		//free(arr);
		free(index);
		return x;
	}
	else return -1;
}