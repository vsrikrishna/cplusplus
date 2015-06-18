/*
Evernote 4
Given an unordered list of N elements, write a function to find the top four elements of the given list. Make sure your function runs in linear time O(N).
 
Input format :
 
First line of input contains N , number of elements in list.
Next N line , each contains a element.
 
Output format :
 
Print the top four elements of list.
 
Sample input :
 
8
6930886
-1692777
4636915
7747793
-4238335
9885386
9760492
6516649
 
Sample ouput :
 
9885386
9760492
7747793
6930886
 
Constraint :
 
N < 1000000.
all numbers will fit  in 32-bit integer.
*/

#include <iostream>
using namespace std;

struct node{
	node* lnode;
	node* rnode;
	int value;
};

class tree{
	node* root;
    void addNode(node* leaf, int value);
    void printNode(node* leaf, int noOfTerms);

public:
	tree(){
       root = NULL;
	}
    void addNode(int value);
	void printNode(int noOfTerms);
};

void tree::addNode(int value){
    if(root == NULL){
        root = new node;
		root->lnode = NULL;
		root->rnode = NULL;
		root->value = value;
	}
	else
        addNode(root, value);
}

void tree::printNode(int value){
    printNode(root, value);
}
void tree::addNode(node* leaf, int value){
	if(value <= leaf->value){
		if(leaf->lnode == NULL){
			leaf->lnode = new node;
			leaf->lnode->lnode = NULL;
			leaf->lnode->rnode = NULL;
			leaf->lnode->value = value;
		}
		else
			addNode(leaf->lnode, value);
	}
	else if(value > leaf->value){
		if(leaf->rnode == NULL){
			leaf->rnode = new node;
			leaf->rnode->lnode = NULL;
			leaf->rnode->rnode = NULL;
			leaf->rnode->value = value;
		}
		else
			addNode(leaf->rnode, value);
	}
}

void tree::printNode(node* leaf, int noOfTerms){
	static int count = 0;
	if(leaf==NULL){
		return;
	}
    printNode(leaf->rnode, noOfTerms);

	if(count == noOfTerms) return;

	cout << leaf->value << endl;
	count++;
    printNode(leaf->lnode, noOfTerms);
}

int main(){
    int elements;
	long int num;
	cin >> elements;
	tree* t1 = new tree;

	for(int i =0; i < elements; i++){
        cin >> num;
		t1->addNode(num);
	}

	t1->printNode(4);
	return 0;
}