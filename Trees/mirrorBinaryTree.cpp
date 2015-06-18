/**
Mirror Binary Tree: Program to mirror the binary tree
07/19/2014
*/

#include "iostream"
#include "conio.h"

using namespace std;

struct Node{
    int value;
    Node* lnode;
	Node* rnode;
};
class BST{
    Node* root;
	void insertNode(Node*, int);
	void printTreePreOrder(Node* leaf);
	void mirrorRecursively(Node* leaf);
public:
	BST(int val){
		root = new Node;
   	    root->value = val;
		root->lnode = NULL;
		root->rnode = NULL;
	}
	BST(){
		root = NULL;
	}
	void insertNode(int);
	void printTreePreOrder();
	void mirrorRecursively();
};
void BST::insertNode(int Val){
	if (root == NULL){
		root = new Node;
		root->lnode = NULL;
		root->rnode = NULL;
	}
	else
	   insertNode(root, Val);
}
void BST::printTreePreOrder(){
	printTreePreOrder(root);
}
void BST::mirrorRecursively(){
	mirrorRecursively(root);
}

void BST::insertNode(Node* N1, int Val){
	if (N1 == NULL){
		N1 = new Node;
		N1->value = Val;
		N1->lnode = NULL;
		N1->rnode = NULL;
	}
	Node *Leaf = new Node;
	Leaf->value = Val;
	if(Val > N1->value){
        if (N1->rnode == NULL){
			N1->rnode = new Node;
			N1->rnode->value = Val;
			N1->rnode->lnode = NULL;
			N1->rnode->rnode = NULL;
		}
        else{
            insertNode(N1->rnode, Val);
        }
	}
	if (Val <= N1->value){
		if(N1->lnode == NULL){
			N1->lnode = new Node;
			N1->lnode->value = Val;
			N1->lnode->lnode = NULL;
			N1->lnode->rnode = NULL;
		}
		else{
			insertNode(N1->lnode, Val);
		}
	}

}

void BST::printTreePreOrder(Node* leaf){
	if (leaf == NULL) return;
	cout<<leaf->value<<endl;
	printTreePreOrder(leaf->lnode);
	printTreePreOrder(leaf->rnode);
}

void BST::mirrorRecursively(Node* leaf){
	if (leaf == NULL) return;
	if (leaf->lnode == NULL && leaf->rnode == NULL) return;

	Node* temp = leaf->lnode;
	leaf->lnode = leaf->rnode;
	leaf->rnode = temp;

	if (leaf->lnode) mirrorRecursively(leaf->lnode);
	if (leaf->rnode) mirrorRecursively(leaf->rnode);
}


int main(){
	BST B1(5);
	B1.insertNode(3);
	B1.insertNode(4);
	B1.insertNode(6);
	B1.insertNode(7);
	B1.insertNode(8);
	B1.printTreePreOrder();
	B1.mirrorRecursively();
	B1.printTreePreOrder();
	getchar();
}