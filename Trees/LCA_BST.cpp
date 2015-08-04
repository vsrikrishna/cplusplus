/*
LowestCommonAncestors.cpp
Find common ancestors for 2 nodes in a binary tree
06/21/2015
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// node structure using leaf nodes
struct node{
	int value;
	node* lnode;
	node* rnode;
};

//function to create a node with key
node* createNode(int key){
	node* N1 = new node();
	N1->value = key;
	N1->lnode = N1->rnode = NULL;
	return N1;
}



/*
Time Complexity: O(log n)
*/
bool isPresent(node *root, node *n1){
	if (root == NULL || n1 == NULL)
		return 0;
	while (true){
		if (root == NULL)
			return 0;
		if (root->value == n1->value)
			return 1;
		if (root->value > n1->value)
			root = root->lnode;
		else
			root = root->rnode;
	}
}

/*recursion method
This is a top down approach where we try to find the ancestor from leaf nodes to root. 
The tree is parsed only once and we would need extra space at each node for storing traversal info
Time Complexity: O(log n) - log n which is height of the tree
Space Complexity: O(log n) - log n because in worst case stack will be holding values from 
                             previous call till height of tree is called recursively
*/
node* findLcaRecursive(node* root, node* n1, node* n2){
	if (root == NULL || n1 == NULL || n2 == NULL)
		return NULL;
	if (!isPresent(root, n1) || !isPresent(root, n2))
		return NULL;
	if (root == n1 && root == n2)
		return root;

	//If execution has reached here then it means 
	// the roots must be in subtrees
	if(root->value > n1->value && root->value > n2->value)
        findLcaRecursive(root->lnode, n1, n2);
	if (root->value < n1->value && root->value < n2->value)
	    findLcaRecursive(root->rnode,n1,n2);
	return root;
}

/*iterative method
How to remember the stopping condition:
You keep going towards the subtree which has both the nodes. The moment this 
condition is not true, it means that either values are on both side of this node 
or one value is in subtree and the other value is this node itself. So return 
this node
Time Complexity: O(log n) - log n which is height of the tree
Space Complexity: O(1) - constant because the value is stored in constant set of registers
*/
node* findLcaIterative(node* root, node* n1, node* n2){
	if (root == NULL || n1 == NULL || n2 == NULL)
		return NULL;
	if (!isPresent(root, n1) || !isPresent(root, n2))
		return NULL;
	if (root == n1 && root == n2)
		return root;
	while (root != NULL){
		if (root->value > n1->value && root->value > n2->value)
			root = root->lnode;
		else if (root->value < n1->value && root->value < n2->value)
			root = root->rnode;
		else
			return root;
	}
}


int main(){
    //Testing 1 method
	node* root = createNode(3);
	root->lnode = createNode(4);
	root->rnode = createNode(6);
	root->lnode->lnode = createNode(1);
	root->lnode->rnode = createNode(2);
	root->rnode->lnode = createNode(5);
	root->rnode->rnode = createNode(7);
	node* outNode = createNode(9);
	node *result = findLCA(root, root->lnode->lnode, root->rnode->rnode);
	//node *result = findLCA(root, root->lnode->lnode, outNode);
	cout << "The LCA of " << root->lnode->lnode->value << " & " << root->rnode->rnode->value << " is " << result->value << endl;

	getchar();
	return 0;
}