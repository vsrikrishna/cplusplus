/*
Given a tree node and integer number, write a method that returns true/false if any path from that node sums up to that number.
*/
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

struct node{
  int val;
  node *left;
  node *right;
};

node* newNode(int val){
  node *root = new node;
  root->val=val;
  root->left=root->right=NULL;
  return root;
}

bool findTotal(node *n1,int val){
  if(n1==NULL) return false;
  if(n1->val==val) return true;
  return(findTotal(n1->left,val-(n1->val)) || findTotal(n1->right,val-(n1->val)));
}
int main(){
  int num;  
  cout<<"Enter the total to be found"<<endl;
  cin>>num;
  cout<<"Constructing the tree"<<endl;
  node *root=newNode(5);
  root->left=newNode(3);
  root->left->left=newNode(1);
  root->left->right=newNode(4);
  root->right=newNode(7);
  root->right->left=newNode(6);
  root->right->right=newNode(8);
  bool result=findTotal(root,num);
  cout<<"The total is present as sum of path:"<<result<<endl;
  return 0;
}
