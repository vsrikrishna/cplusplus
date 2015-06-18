
#include "iostream"
#include "conio.h"
#include "queue"
#include "stack"

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

class BST{
public:
	Node* root;
	BST(){
		root = NULL;
	}
	BST(int data){
		root = new Node;
		root->value = data;
		root->left = NULL;
		root->right = NULL;
	}
	void insertData(int key); 
	void insertData(int key, Node* root);
	bool mirrorBinaryTree(Node* root);
};

void BST::insertData(int key){
	if (root == NULL){
		return;
	}
	else{
		insertData(key, root);
	}
}

void BST::insertData(int key, Node* root){
	if (key < root->value){
		if (root->left == NULL){
			root->left = new Node;
			root->left->value = key;
			root->left->left = NULL;
			root->left->right = NULL;
		}
		else{
			insertData(key, root->left);
		}
	}

	if (key >= root->value){
		if (root->right == NULL){
			root->right = new Node;
			root->right->value = key;
			root->right->left = NULL;
			root->right->right = NULL;
		}
		else{
			insertData(key, root->right);
		}
	}
}
bool compareTrees(Node *N1, Node *N2){
	if (N1 == NULL && N2 == NULL)
		return true;
	else if (N1 == NULL || N2 == NULL)
		return false;
	else if (N1->value != N2->value)
		return false;
	else if (!compareTrees(N1->left, N2->left))
		return false;
	else if (!compareTrees(N1->right, N2->right))
		return false;
	else
		return true;
}

int main(){
	BST BT1(6);
	BT1.insertData(3);
	BT1.insertData(8);
	BT1.insertData(2);
	BT1.insertData(4);
	BT1.insertData(1);
	BT1.insertData(5);
	BT1.insertData(7);
	BT1.insertData(9);
	BT1.insertData(10);

	BST BT2(6);
	BT2.insertData(3);
	BT2.insertData(8);
	BT2.insertData(2);
	BT2.insertData(4);
	BT2.insertData(1);
	BT2.insertData(5);
	BT2.insertData(7);
	BT2.insertData(9);
	BT2.insertData(10);
	
	cout << "comparison of B1 and B2 trees is " << compareTrees(BT1.root, BT2.root);
	getchar();
	return 0;
}