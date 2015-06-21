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


// Node structure using parent node
struct Node{
	int value;
	Node* parent;
};

Node* newNode(int key){
	Node* N2 = new Node();
	N2->parent = NULL;
	N2->value = key;
	return N2;
}


/*recursion method
This is a top down approach where we try to find the ancestor from leaf nodes to root. 
The tree is parsed only once and we would need extra space at each node for storing traversal info
Time Complexity: O(n)
Space Complexity: O(2n)
This solution does not cover one condition where only one node is present in tree
*/
node* findLCA(node* root, node* n1, node* n2){
	if (root == NULL || n1 == NULL || n2 == NULL)
		return NULL;
	if (root == n1 || root == n2)
		return root;
	node* left = findLCA(root->lnode, n1, n2);
	node* right = findLCA(root->rnode,n1,n2);
	if (left && right) return root; // if both the nodes are on each side of root
	return left ? left : right; //if each node are one side or return null if not on either side 
}

/* link to parent node for each node
If each node has a link to its parent node then we can come up with a solution which is more optimized 
It also solves the edge case missing in previous solution
Time Complexity: O(h) because it parses the height of the tree from both directions
Space Complexity: O(h) because it stores height nodes of the tree, maybe twice height of tree in worst case
*/
Node * findLCAUsingParent(Node *n1, Node* n2){
	unordered_map<Node*, int> visitedNodes;
	while (n1 || n2){
		if (n1){
			if (visitedNodes.find(n1) != visitedNodes.end()){
				return n1;
			}
			visitedNodes.insert(pair<Node*,int>(n1, 1));
			n1 = n1->parent;
		}
		if (n2){
			if (visitedNodes.find(n2) != visitedNodes.end()){
				return n2;
			}
			visitedNodes.insert(pair<Node*, int>(n2, 1));
			n2 = n2->parent;
		}
	}
	return NULL;
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

	//Testing 2nd method of finding LCA
	Node* leaf1 = newNode(1);
	Node* leaf2 = newNode(2);
	Node* leaf3 = newNode(5);
	Node* leaf4 = newNode(7);
	Node* leaf5 = newNode(10);
	leaf1->parent = leaf2->parent = newNode(4);
	leaf3->parent = leaf4->parent = newNode(6);
	leaf1->parent->parent = leaf2->parent->parent = leaf3->parent->parent = leaf4->parent->parent = newNode(3);
	Node* result2 = findLCAUsingParent(leaf1,leaf5);
	if (result2 == NULL){
		cout << "The LCA of " << leaf1->value << " & " << leaf5->value << " is not in the tree." << endl;
	}
	else{
		cout << "The LCA of " << leaf1->value << " & " << leaf5->value << " is: "<< result2->value << endl;
	}
	getchar();
	return 0;
}