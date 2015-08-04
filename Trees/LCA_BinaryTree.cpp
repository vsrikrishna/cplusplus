/*
LCA_BinaryTree.cpp
Find common ancestors for 2 nodes in a binary tree
08/01/2015
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure using parent node
struct Node{
	int value;
	Node* parent;
	Node* left;
	Node* right;
};

Node* newNode(int key){
	Node* N2 = new Node();
	N2->parent = NULL;
	N2->value = key;
	N2->left = NULL;
	N2->right = NULL;
	return N2;
}


/* link to parent node for each node
If each node has a link to its parent node then we can come up with a solution which is more optimized
Time Complexity: O(h) because it parses the height of the tree from both directions
Space Complexity: O(h) because it stores height nodes of the tree, maybe twice height of tree in worst case
*/
Node * findLCAUsingParent(Node *n1, Node* n2){
	set<Node*> visitedNodes;
	while (n1||n2){
		if (n1){
			if (visitedNodes.find(n1) != visitedNodes.end()){
				return n1;
			}
			visitedNodes.insert(n1);
			n1 = n1->parent;
		}
		if (n2){
			if (visitedNodes.find(n2) != visitedNodes.end()){
				return n2;
			}
			visitedNodes.insert(n2);
			n2 = n2->parent;
		}
	}
	return NULL;
}

/*
tricks to remember this algorithm:
1) YES, YOU CAN PASS A RUNNING PATH IN RECURSIVE FUNCTION CALL
2) A twisted method, top down approach, used to store nodes and then it is popped if not true
3) First store the node in the path & then return true/false. This makes sure the node is definitely captured in path
4) Dont forget to return false at the very end
5) Doing bottom up approach may be tedious here since we will have to reverse parse the paths to compare the common nodes
6) Top-Down approach is not intutitive but it yields optimized and quick results

Time Complexity:O(n) - where n is no of elements
Space Complexity: omega(log n) for storing the paths
*/
bool findPath(Node *root, int key, vector<Node*>& path){
	if (root == NULL) 
		return false;
    
	//first store the node in path & then return true if found equal
	path.push_back(root);
	if (root->value == key) 
		return true;
	
	int left=0, right = 0;
	if (root->left)
		left = findPath(root->left, key, path);
	if (root->right)
		right = findPath(root->right, key, path);
	if (left || right)
		return true;

	// If execution has reached here without returning it means the key was not found in this path
	// Pop the node from vector path
	if (!path.empty())
	   path.pop_back();
	return false;
}
int findLcaWithPath(Node* root, int n1, int n2){
	vector<Node*> path1;
	vector<Node*> path2;

	if (!findPath(root, n1,path1) || !findPath(root, n2,path2)){
		return -1;
	}
	unsigned int i;
	for (i = 0; i < path1.size() && i< path2.size(); i++){
		if (path1[i]->value != path2[i]->value){
			break;
		}
	}
	return path1[i - 1]->value;
}

/*
Third Method Optimized for LCA
This function returns pointer to LCA of two given values n1 and n2.
v1 is set as true by this function if n1 is found
v2 is set as true by this function if n2 is found
Time Complexity: O(n) - the tree is traversed only once unlike in the path method
Space Complexity: O(log n) - for height of tree to store variables at each step
 */
struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2)
{
	// Base case
	if (root == NULL) return NULL;

	// If either n1 or n2 matches with root's key, report the presence
	// by setting v1 or v2 as true and return root (Note that if a key
	// is ancestor of other, then the ancestor key becomes LCA)
	if (root->value == n1)
	{
		v1 = true;
		return root;
	}
	if (root->value == n2)
	{
		v2 = true;
		return root;
	}

	// Look for keys in left and right subtrees
	Node *left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
	Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

	// If both of the above calls return Non-NULL, then one key
	// is present in once subtree and other is present in other,
	// So this node is the LCA
	if (left_lca && right_lca)  return root;

	// Otherwise check if left subtree or right subtree is LCA
	return (left_lca != NULL) ? left_lca : right_lca;
}

// Returns true if key k is present in tree rooted with root
bool find(Node *root, int k)
{
	// Base Case
	if (root == NULL)
		return false;

	// If key is present at root, or in left subtree or right subtree,
	// return true;
	if (root->value == k || find(root->left, k) || find(root->right, k))
		return true;

	// Else return false
	return false;
}


// This function returns LCA of n1 and n2 only if both n1 and n2 are present
//in tree, otherwise returns NULL;

Node *findLCA(Node *root, int n1, int n2)
{
	// Initialize n1 and n2 as not visited
	bool v1 = false, v2 = false;

	// Find lca of n1 and n2 using the technique discussed above
	Node *lca = findLCAUtil(root, n1, n2, v1, v2);

	// Return LCA only if both n1 and n2 are present in tree
	if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
		return lca;

	// Else return NULL
	return NULL;
}


int main(){
	//Testing parent method of finding LCA
	Node* leaf1 = newNode(1);
	Node* leaf2 = newNode(2);
	Node* leaf3 = newNode(5);
	Node* leaf4 = newNode(7);
	Node* leaf5 = newNode(10);
	leaf1->parent = leaf2->parent = newNode(4);
	leaf3->parent = leaf4->parent = newNode(6);
	leaf1->parent->parent = leaf2->parent->parent = leaf3->parent->parent = leaf4->parent->parent = newNode(3);
	Node* result2 = findLCAUsingParent(leaf1, leaf4);
	if (result2 == NULL){
		cout << "The LCA of " << leaf1->value << " & " << leaf4->value << " is not in the tree." << endl;
	}
	else{
		cout << "The LCA of " << leaf1->value << " & " << leaf4->value << " is: " << result2->value << endl;
	}

	cout << "Using method 2" << endl;
	//Testing path method of finding LCA
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLcaWithPath(root, 4, 5);
	cout << "\nLCA(4, 6) = " << findLcaWithPath(root, 4, 6);
	cout << "\nLCA(3, 4) = " << findLcaWithPath(root, 3, 4);
	cout << "\nLCA(2, 4) = " << findLcaWithPath(root, 2, 4);
	cout << endl;

	cout << "Using method 3, the most optimized  method" << endl;
	Node *lca = findLCA(root, 4, 5);
	if (lca != NULL)
		cout << "LCA(4, 5) = " << lca->value<<endl;
	else
		cout << "Keys are not present "<<endl;

	lca = findLCA(root, 1, 9);
	if (lca != NULL)
		cout << "LCA(1, 9) = " << lca->value<<endl;
	else
		cout << "Keys(1,9) are not present "<<endl;

	getchar();
	return 0;
}