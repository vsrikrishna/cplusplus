/*
Given a binary tree and a target number, return whether or not there exist a path that can create target number. 
All inputs are integers. Target is not a string. 

NOTE:: this is not path sums to target number 
ex: 
3 
4 5 
6 7 8 9 

359 = return true 
38 = return false 
47 = return true 
6 = return true
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct node{
  int val;
  node *left,*right;  
};

node* addNode(int val){
  node* new = new node;
  new->val=val;
  new->left=new->right=NULL;
};

bool existsPath(node* root, string path, int target){
  int value;
  stringstream ss(path),ss2;
  ss2<<root->val;
  ss<<root->val;
  ss>>value;
  if(value==target) return true;
  if(root==NULL) return false;
  return (existsPath(root->left,ss.str())||
          existsPath(root->right,ss.str())||
          existsPath(root->left,ss2.str())||
          existsPath(root->left,ss2.str()));
}

int main(){
  node* root = new node(3);
  root->left = new node(4);
  root->right = new node(5);
  root->left->left = new node(6);
  root->left->right = new node(7);
  root->right->left = new node(8);
  root->right->right = new node(9);
  
  int target;
  cout<<"Enter target number"<<endl;
  cin>>target;
  cout<<"Path exists for target is "<<existsPath(root,target); 
  return 0;
}
