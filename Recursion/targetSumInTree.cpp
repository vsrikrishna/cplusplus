/* Uber problem
Given a binary tree, find paths which sum to a given target.
For example:
5->4->3->2->1 is a tree and a target is 9
Ans should be (4,3,2) and (5,4)
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const double pi = 3.141592653589793;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }

struct node{
  int val;
  node *left,*right;
  node(int x){
    val=x;
    left=NULL;right=NULL;
  }
};
vector< vector<int> > pathSum;

void popTree(node*& root){
  root=new node(5);
  root->left=new node(4);
  root->left->left=new node(3);
  root->left->left->left=new node(2);
  root->left->left->left->left=new node(1);
}

void printPathSums(node *root, int targ, int currSum, string result){
  if(root==NULL) return;
  int newSum=currSum+root->val;
  stringstream newRes;
  newRes<<result;newRes<<" ";newRes<<root->val;
  if(newSum==targ){
    cout<<result<<" "<<root->val<<endl;
  }
  printPathSums(root->left,targ,newSum,newRes.str());
  printPathSums(root->right,targ,newSum,newRes.str());
  printPathSums(root->left,targ,0,"");
  printPathSums(root->right,targ,0,"");
}


int main()
{
  node* root;
  popTree(root);
  int sum=9;
  printPathSums(root,sum,0,"");
  //cout<<"Hello"<<endl;
  return 0;
}
 

