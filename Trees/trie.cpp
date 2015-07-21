#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
 
struct node{
	char info; // to store the pos character of Word 
    string Word; // to store the entire word after last letter
    node* ptrs[26]; // to store pointers to next character
};

/*
For n words of average length m the complexities are:
Time Complexity: O(m) since we have to insert each letter into the trie
Space Complexity: O(mn) since we have to store each m letter for n words
*/
void insertword(string word,int pos, node* root){
	if (root == NULL){
		root = new node;
		for (int i = 0; i<26; i++){
			root->ptrs[i] = NULL;
		}
		root->info = NULL;
		root->Word = "";
	}
	if(word.length()==pos){
        root->Word=word;
        return;
    }
    if( root-> ptrs[word[pos]-'a']==NULL ){
        node *newnode;
        newnode= new node;
        newnode->info=word[pos];
		for (int i = 0; i<26; i++){
			newnode->ptrs[i] = NULL;
		}
        root->ptrs[word[pos]-'a']=newnode;
    }
	insertword(word,pos+1,root->ptrs[word[pos]-'a']);
}

/*
Time Complexity: O(m) since we have to search for m letters in a word
Space Complexity: No space complexity for search operation as such*/
int find(string key, int pos, node * root){
	if ((key != root->Word) && (root->ptrs[key[pos]-'a'] != NULL))
		return find(key, pos + 1, root->ptrs[key[pos]-'a']);
	else if (key == root->Word){
		cout << "The spelling of the word '" << root->Word << "' is correct" << endl;
		//found = 1;
		return true;
	}
	else{
		return false;
	}
}

/*
Very important concept in this method is the entire word is stored after the last letter as last node of each word
The Word string at the end of each word will re-store the entire word which is returned back in the print methods
This could mean a lot of space complexity for large word sets*/
void printall(node * root){
	if (root == NULL) return;
	for(int i=0;i<26;i++)
        if(root->ptrs[i]!=NULL){
            printall(root->ptrs[i]);
        }
    if(root->Word != "")
        cout<<" -> "<<root->Word<<endl;
}
 
/*
Because the words are stored in entirity, at the end of each word, we can retrieve them to print it
Time Complexity: O(mn) worst case
*/
void suggest(string key,int pos, node * root){
    if((key != root->Word) && (root->ptrs[key[pos]-'a'] != NULL)){
            suggest(key,pos+1,root->ptrs[key[pos]-'a']);
    }
    else{
            printall(root);
    }
}
 
int main(){
    ifstream in("wordlist.txt");
    string word,current="",key;
     node* root = NULL;
    while(getline(in,word)){
		transform(word.begin(), word.end(), word.begin(), tolower);
        insertword(word,0,root);
    }
    in.close();
    cout<<endl<<"Trie Construction Successful"<<endl;
    printall(root);
    cout<<"Enter the word to be searched for : ";
    getline(std::cin,key);
    if (!find(key, 0, root)){
        cout<<endl<<"The spelling is incorrect, Possible suggestions are :"<<endl;
        suggest(key,0,root);
    }
	cin.clear();
	getchar();
    return 0;
}

