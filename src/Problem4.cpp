/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard 
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void fixLinks(struct node* root, struct node* root2){
	//if (root2->data == root->data)return;
	 if (root2->data < root->data){
		if (root->left == NULL){
			root->left = root2;
			root->left->right->left = NULL;
			root->left->right->right = NULL;
				return;
		}
		else fixLinks(root->left, root2);
	}
	else{
		if (root->right == NULL){ 
			root->right = root2;
			root->right->
		    return; 
		}
		else fixLinks(root->right, root2);
	 }
}
void inorder2(struct node *root,struct node* root1){
	if (root == NULL)return;
	inorder2(root->left,root1);
	fixLinks(root1,root);
	inorder2(root->right,root1);
}

void merge_two_bst(struct node *root1, struct node *root2){
	if (root1 == NULL || root2 == NULL)return;
		inorder2(root2,root1);

}