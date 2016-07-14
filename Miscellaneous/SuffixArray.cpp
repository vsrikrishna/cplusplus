/*
* Implement suffix array to print the maximum suffix substring in a string
* Algorithm:
* Build a suffix tree and find the lowest node with multiple children
*
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctype.h>

//using namespace std;

struct node{
	char ch;
	node* next[26];
	int treeHeight;
	int childCount;
	int end = 0;
};

bool checkEmptyVector(node * leaf){
	for (int i = 0; i < 26; i++){
		if (leaf->next[i] != NULL){
			return false;
		}
	}
	return true;
}

int countChildren(node * leaf){
	int count = 0;
	for (int i = 0; i < 26; i++){
		if (leaf->next[i] != NULL){
			count++;
		}
	}
	if (leaf->end) count++;
	return count;
}

void findMaxRepeatedString(node* root, std::string& result, int& maxChild, int& lowestHeight, std::string str){
	if (checkEmptyVector(root)){
		return;
	}
	for (int i = 0; i<26; i++){
		if (root->next[i]){
			str += root->next[i]->ch;
			if (root->next[i]->childCount >= maxChild &&
				root->next[i]->treeHeight > lowestHeight){
				std::cout << "maxChild: " << maxChild << ", lowestHeight:" << lowestHeight << ", result is " << result << std::endl;
				maxChild = root->next[i]->childCount;
				lowestHeight = root->next[i]->treeHeight;
				result = str;
				std::cout<<"maxChild: "<<maxChild<<", lowestHeight:"<<lowestHeight<<", result is "<<result<<std::endl;
			}
     	    findMaxRepeatedString(root->next[i],result,maxChild,lowestHeight,str);
			str = "";
		}
	}
}

void insertSuffixIntoTree(node* root, std::string suffix){
   if (suffix.size() == 0){
	  root->childCount = countChildren(root);  
      return;
   }
   char c = suffix[0];
   int index = tolower(c) - 'a';
   if (root->next[index] == NULL){
     root->next[index] = new node();
	 for (int k = 0; k < 26; k++){
        root->next[index]->next[k] = NULL;
	 }
	 root->next[index]->ch = tolower(c);
	 root->next[index]->treeHeight = root->treeHeight + 1;
	 if (suffix.size() == 1){
	    root->next[index]->end = 1;
     }
   }
   suffix.erase(suffix.begin());
   root->childCount = countChildren(root);
   insertSuffixIntoTree(root->next[index], suffix);
}

void buildSuffixTree(node* root, std::string str){
	for (int i = str.size() - 1; i >= 0; i--){
		std::string suffix = str.substr(i);
		std::cout << "suffix is " << suffix << std::endl;
		insertSuffixIntoTree(root, suffix);
	}
}

void printSuffixTree(node* root, std::string str){
	if (root->end){
		std::cout << str <<": "<<root->childCount<<" : "<<root->treeHeight<<std::endl;
	}
	if (checkEmptyVector(root)){
		return;
	}
	for (int i = 0; i<26; i++){
		//cout << "inside for loop, i is " << i << endl;
		while (root->next[i]){			
			str += root->next[i]->ch;
			printSuffixTree(root->next[i],str);
			str = "";
			break;
		}
	}
}

int main() {
	std::string str;
	node* suffixRoot = new node();
	suffixRoot->ch = ' ';
	suffixRoot->treeHeight = 0;
	for (int i = 0; i < 26; i++){
		suffixRoot->next[i] = NULL;
	}
	std::cout << "enter the string" << std::endl;
	std::cin >> str;
	buildSuffixTree(suffixRoot, str);
	std::string result="", str2="";
	int zero = 0,zero2 = 0;
	findMaxRepeatedString(suffixRoot,result,zero,zero2,str2);
	std::cout << "max repeated string is " << result << std::endl;
	str = "";
	printSuffixTree(suffixRoot,str2);
	getchar();
	return 0;
}