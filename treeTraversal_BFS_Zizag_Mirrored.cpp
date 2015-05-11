/**
* Question asked during LinkedIN interview
* July 23 2012
* This implementation also covers removing duplicate elements using BST
* Sample input:
*
*          1
*         / \
*        3   5
*       / \   \
*      2   4   7
*     /     \
*    9       8
*
* Expected output(BFS):
* 1
* 3 5
* 2 4 7
* 9 8
* ==========
*
* Expected output(ZigZag)
* 1
* 5 3
* 2 4 7
* 8 9
* ===========
*
* Expected output(Mirrored Binary Tree)
*
*
*
*
*
*/

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
	Node* root;
	void insertData(int key, Node* root);
	void BFS(Node* root);
	void zigzagPrint(Node* root);
	void mirrorBinaryTree(Node* root);
public:
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
	void BFS();
	void zigzagPrint();
	void mirrorBinaryTree();
};

void BST::BFS(Node* root){
	queue<Node*> q;
	int popCount, inCount;
	popCount = inCount = 0;
	q.push(root);
	popCount++;
	vector<int> values;
	bool duplicate = false;
	
	while (!q.empty()){
		Node* n1 = q.front();
		
		cout << n1->value<<" ";		
		q.pop();
		popCount--;
		if (n1->left != NULL){
			q.push(n1->left);
			inCount++;
		}
		if (n1->right != NULL){
			q.push(n1->right);
			inCount++;
		}
		if (popCount == 0){
			popCount = inCount;
			inCount = 0;
			cout << endl;
		}
	}
	std::cout << std::endl;
}

void BST::zigzagPrint(Node* pRoot){
    if (pRoot == NULL){
       return;
    }	

	std::stack<Node*> levels[2];
	int current = 1; 
	int next = 0;

	levels[current].push(pRoot);
	while(!levels[0].empty() || !levels[1].empty()){
        Node* pNode = levels[current].top();
		levels[current].pop();
        std::cout<<pNode->value<<" ";
		if (current){
			if (pNode->left != NULL)
				levels[next].push(pNode->left);
			if (pNode->right != NULL)
				levels[next].push(pNode->right);
		}
		else{
			if (pNode->right != NULL)
				levels[next].push(pNode->right);
			if (pNode->left != NULL)
				levels[next].push(pNode->left);

		}
		if (levels[current].empty()){
			std::cout << std::endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
	cout << endl;
}

void BST::mirrorBinaryTree(Node *pRoot){
	if (pRoot == NULL) return;
	else{
		if (pRoot->left != NULL || pRoot->right != NULL){
			Node *temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
			mirrorBinaryTree(pRoot->left);
			mirrorBinaryTree(pRoot->right);
		}
	}
}

void BST::BFS(){
	if (root == NULL) return;
	else{
		BFS(root);
	}
}

void BST::zigzagPrint(){
	if (root == NULL) return;
	else{
		zigzagPrint(root);
	}
}

void BST::mirrorBinaryTree(){
	if (root == NULL) return;
	else{
		mirrorBinaryTree(root);
	}
}

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
	cout << "BFS print is:" << endl;
	BT1.BFS();
	
	cout << "zigzag print is:" << endl;
	BT1.zigzagPrint();

	BT1.mirrorBinaryTree();
	cout << "mirrored BST BSF print is:" << endl;
	BT1.BFS();

	getchar();
	return 0;
}