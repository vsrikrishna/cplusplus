/**
Ternary Tree implementation
07/20/2014
*/
#include "iostream"
#include "string"
#include "ctype.h"  //used for converting to upper case 

using namespace std;

struct Node{
	char value;
	unsigned int stringEnd;
	Node* equal;
	Node* left;
	Node* right;
};

Node* createNode(char *word){
	Node *N1 = new Node;
	N1->value = *word;
	N1->left = N1->right = N1->equal = NULL;
	N1->stringEnd = 0;
	return N1;
}
void addWord(Node*& leaf, char* word){
	if (leaf == NULL){
		leaf = createNode(word);
	}
    if (leaf->value == *word){
        if (*(word + 1)){
            addWord(leaf->equal,word+1);
        }
        else{
            leaf->stringEnd = 1;
        }
    }
    else if (*word < leaf->value){
        addWord(leaf->left, word);
    }
    else if (*word > leaf->value){
        addWord(leaf->right, word);
    }
}

void traverseTSTUtil(Node* leaf,char* buffer ,int position){
    if (leaf){
		traverseTSTUtil(leaf->left, buffer, position);
		buffer[position] = leaf->value;
		if (leaf->stringEnd){
			buffer[position + 1] = '\0';
			cout << buffer << endl;
		}
		traverseTSTUtil(leaf->equal,buffer,position+1);
		traverseTSTUtil(leaf->right, buffer, position);
    }
}

void traverseTST(Node* leaf){
	char buffer[50];
	traverseTSTUtil(leaf, buffer, 0);
}
int main(){
	Node *root = NULL;
	addWord(root, "cat");
	addWord(root, "dogs");
	addWord(root, "bugz");
	addWord(root, "sheep");
	traverseTST(root);
	getchar();
	return 0;
}