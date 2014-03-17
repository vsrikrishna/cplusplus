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
 * Expected output:
 *    1
 *    3 5
 *    2 4 7
 *    9 8
 *    ==========
 */

#include "iostream"
#include "conio.h"
#include "queue"
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

};

void BST::BFS(){
   if(root == NULL) return;
   else{
      BFS(root);
   }
}
void BST::BFS(Node* root){
   queue<Node*> q;
   q.push(root);
   vector<int> values;
   bool duplicate = false;

   while(!q.empty()){
      Node* n1 = q.front();

	  for(vector<int>::iterator it = values.begin(); it!=values.end();it++){
		  if(*it == n1->value){
			  duplicate = true;
		  }
	  }

	  if(!duplicate){
	     values.push_back(n1->value);
         cout <<"::"<<n1->value;
	  }
      q.pop();

	  if(n1->left!=NULL){
         q.push(n1->left);
      }
      if(n1->right!=NULL){
         q.push(n1->right);
      }
   }
}

void BST::insertData(int key){
	if(root == NULL){
		return;
	}
    else{
      insertData(key, root);
   }
}

void BST::insertData(int key, Node* root){
   if(key < root->value){
      if(root->left == NULL){
	     root->left = new Node;
		 root->left->value = key;
		 root->left->left = NULL;
		 root->left->right = NULL;
	  }
	  else{
         insertData(key, root->left);
	  }
   }

   if(key >= root->value){
      if(root->right == NULL){
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
BST BT1(7);
BT1.insertData(3);
BT1.insertData(5);
BT1.insertData(2);
BT1.insertData(4);
BT1.insertData(9);
BT1.insertData(3);
BT1.insertData(8);
BT1.BFS();
getch();
return 0;
}