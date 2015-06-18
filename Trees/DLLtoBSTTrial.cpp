/*
01/11/2015
Google Interview Preperation
Given a sorted doubly linked list, write an algorithm to convert this list into a binary search tree (BST). The BST will be used to represent a set.
You may expect that client will use it to search for presence of a key in the set.
You may assume that you are given the following Node implementation that you can not exted or modify:

public class Node {
public Node prev, next;
public int key;
}
You algorithm is not allowed to create any other instance of the Node.
*/

#include <iostream>
using namespace std;

struct Node {
   Node *prev, *next;
   int key;
};

class LL{
public:
	Node *root;
	LL(){
		root = NULL;
	}	
	void addNode(int val);
};
void LL::addNode(int val){

	if (root == NULL){
		root = new Node;
		root->prev = root->next = NULL;
		root->key = val;
	}
	else{
		Node *parse = root;
		while (parse->next != NULL){
			parse = parse->next;
		}
		parse->next = new Node;
		parse->next->key = val;
		parse->next->prev = NULL;
		parse->next->next = NULL;
	}
}

struct tNode{
	tNode *left, *right;
	int value;
};

class BST{
public: 
   tNode *root;
   BST(){
	   root = NULL;
   }
   BST(int _value){
	   root = new tNode();
	   root->left = root->right = NULL;
	   root->value = _value;
   }
   void addNode(int val);
   void addNode(tNode *leaf, int val);
   void printTreePreOrder(tNode*);
};

void BST::addNode(int val){
	if (root != NULL){
		addNode(root, val);
	}
	else{
		root = new tNode();
		root->value = val;
		root->left = root->right = NULL;
	}
}

void BST::addNode(tNode* leaf, int val){
	if (val<leaf->value){
		if (leaf->left == NULL){
			leaf->left = new tNode();
			leaf->left->value = val;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
		else{
			addNode(leaf->left,val);
		}
	}
	else{
		if (leaf->right == NULL){
			leaf->right = new tNode();
			leaf->right->value = val;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
		else{
			addNode(leaf->right, val);
		}

	}
}

void BST::printTreePreOrder(tNode* root){
	if(root!=NULL){
		printTreePreOrder(root->left);
		cout << "Data at this node is: " << root->value << endl;
		printTreePreOrder(root->right);
	}
}

BST* LinkedListToBST(Node *root){
   BST *llTree = new BST;
   Node *parse = root;
   while(parse !=NULL){
	   llTree->addNode(parse->key);
	   parse = parse->next;
   }
   return llTree;
}

int main(){
	LL l1;
	l1.addNode(5);
	l1.addNode(7);
	l1.addNode(8);
	l1.addNode(2);
	l1.addNode(3);
	l1.addNode(1);
	BST* B1 = LinkedListToBST(l1.root);
	B1->printTreePreOrder(B1->root);
	getchar();
	return 0;
}