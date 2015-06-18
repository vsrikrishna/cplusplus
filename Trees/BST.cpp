/*
Binary Search Tree(BST)
06/27/2013
*/
#include "iostream"
#include "vector"
#include "conio.h"
using namespace std;

struct node{
   int data;
   node* ltree;
   node* rtree;
};

class BST{
   node* root;
   void insert(int key, node* root);
   bool isBST(node* tree);
   void destroy_tree(node* root);
   void printTreePreOrder(node* root);
   void printTreeInOrder(node* root);
   void printTreePostOrder(node* root);
   bool search_tree(node* root, int key);

public:
   BST(){
      root = NULL;
   }
   ~BST(){
      destroy_tree();
   }
   void insert(int key);
   bool isBST();
   void destroy_tree();
   void printTreePreOrder();
   void printTreeInOrder();
   void printTreePostOrder();
   bool search_tree(int key);

};

void BST::insert(int key){
   if(root != NULL){
      insert(key, root);
   }
   else{
      root = new node;
	  root->data = key;
	  root->ltree = NULL;
	  root->rtree = NULL;
   }
}

void BST::insert(int key, node* leaf){
   if(key <= leaf->data){
	  if(leaf->ltree == NULL){
		 leaf->ltree = new node;
		 leaf->ltree->data = key;
	     leaf->ltree->ltree = NULL;
         leaf->ltree->rtree = NULL;
      }
	  else{
         insert(key, leaf->ltree);     
	  }
   }
   else if(key > leaf->data){
	  if(leaf->rtree == NULL){
		 leaf->rtree = new node;
		 leaf->rtree->data = key;
	     leaf->rtree->ltree = NULL;
         leaf->rtree->rtree = NULL;
      }
	  else{
         insert(key, leaf->rtree);     
	  }
   }
}

bool BST::isBST(){
   if(root!=NULL){
      return isBST(root);
   }
   else{
      cout << "No elements in the tree"<<endl;
	  return false;
   }
}

bool BST::isBST(node *leaf){
   if(leaf == NULL)
	   return true;
   else{
	   if ((leaf->ltree != NULL)&&(leaf->data < leaf->ltree->data)){
          return false;
	   }
	   if((leaf->rtree != NULL)&&(leaf->data > leaf->rtree->data)){
          return false;
	   }
	   if(!isBST(leaf->ltree) || !isBST(leaf->rtree)){
	      return false;
	   }
       return true;
   }
}

void BST::destroy_tree(){
   destroy_tree(root);
}
void BST::destroy_tree(node* leaf){
   if(leaf!=NULL){
      destroy_tree(leaf->ltree);
	  destroy_tree(leaf->rtree);
	  delete leaf;
   }
}

void BST::printTreePreOrder(){
   if(root == NULL){
      cerr << "No elements entered into tree" << endl;
   }
   else{
      printTreePreOrder(root);
   }
}

void BST::printTreeInOrder(){
   if(root == NULL){
      cerr << "No elements entered into tree" << endl;
   }
   else{
      printTreeInOrder(root);
   }
}

void BST::printTreePostOrder(){
   if(root == NULL){
      cerr << "No elements entered into tree" << endl;
   }
   else{
      printTreePostOrder(root);
   }
}

void BST::printTreePreOrder(node* leaf){
   cout<<"Print tree elmenets in pre-order" << endl;
   if(leaf!=NULL){
      cout<<"Data at this node is: "<< leaf->data << endl;
      printTreePreOrder(leaf->ltree);
	  printTreePreOrder(leaf->rtree);
   }
}

void BST::printTreeInOrder(node* leaf){
   cout<<"Print tree elmenets in in-order" << endl;
	if(leaf!=NULL){
      printTreeInOrder(leaf->ltree);
      cout<<"Data at this node is: "<< leaf->data << endl;
	  printTreeInOrder(leaf->rtree);
   }
}

void BST::printTreePostOrder(node* leaf){
 //  cout<<"Print tree elmenets in post-order" << endl;
	if(leaf!=NULL){
      printTreePostOrder(leaf->ltree);
	  printTreePostOrder(leaf->rtree);
      cout<<"Data at this node is: "<< leaf->data << endl;
   }
}

bool BST::search_tree(int key){
   if(root == NULL){
      cerr << "No elements to search in an empty tree" << endl;
	  return false;
   }
   else{
      return search_tree(root, key);
   }
}
bool BST::search_tree(node* leaf, int key){
   if(leaf==NULL){
      return false;
   }
   else{
	  if(key == leaf->data){
         return true;
	  }
	  else if(key < leaf->data){
	     return search_tree(leaf->ltree, key);
	  }
	  else if(key > leaf->data){
         return search_tree(leaf->rtree, key);
	  }
   }
}
int main(){
BST BT1;
BT1.insert(4);
BT1.insert(5);
BT1.insert(1);
//BT1.insert(2);
BT1.insert(0);
BT1.insert(3);
BT1.insert(2);
bool result = BT1.isBST();

if(result){
   cout << "The binary treee is BST" << endl;
}
else{
   cout << "The binary treee is not a BST" << endl;
}

BT1.printTreePostOrder();
bool keyExists = false;
keyExists = BT1.search_tree(3);
cout << "Search for element 3 returned " << keyExists << endl;
keyExists = BT1.search_tree(6);
cout << "Search for element 6 returned " << keyExists << endl;

getch();
return 0;
}