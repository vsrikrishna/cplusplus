#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
 
struct node{
	char val; // to store the pos character of Word 
    node* ptrs[26]; // to store pointers to next character
	bool isEnd;
};

/*
For n words of average length m the complexities are:
Time Complexity: O(mn) since we have to insert each letter into the trie
Space Complexity: O(mn*alphabet_size) since we have to store each m letter for n words
*/
void insertword(string word,int pos, node*& root){
	if (root == NULL){
		root = new node;
		for (int i = 0; i<26; i++){
			root->ptrs[i] = NULL;
		}
		root->val = NULL;
		root->isEnd = false;
	}
	if(word.length()==pos){
		root->isEnd = true;
        return;
    }
    if( root-> ptrs[word[pos]-'a']==NULL ){
        node *newnode;
        newnode= new node;
        newnode->val=word[pos];
		newnode->isEnd = false;
		for (int i = 0; i<26; i++){
			newnode->ptrs[i] = NULL;
		}
        root->ptrs[word[pos]-'a']=newnode;
    }
	insertword(word,pos+1,root->ptrs[word[pos]-'a']);
}

/*
Time Complexity: O(m) since we have to search for m letters in a word
Space Complexity: No space complexity for search operation as such
*/
int find(string key, int pos, node * root){
	if (root->isEnd && pos == key.length()) return true;
	else if (root->ptrs[key[pos] - 'a'] && (root->ptrs[key[pos] - 'a']->val == key[pos]))
		return find(key, pos + 1, root->ptrs[key[pos]-'a']);
	else
		return false;
}

/*
This uses a nice concept of string prefix concatenation and deletion
The string is built till end of the word in a trie and printed out
Once the word is printed, the letter is removed and other paths are traced
Time Complexity: O(mn) since all the n words with m average letter should be built
Space Complexity: O(mn) worst case complexity
*/
void printall(string& prefix, node * root){
	if (root == NULL) return;
	for (int i = 0; i < 26; i++){
		if (root->ptrs[i] != NULL){
			prefix.push_back(root->ptrs[i]->val);
			printall(prefix, root->ptrs[i]);
			prefix.pop_back();
		}
	}
	if (root->isEnd)
        cout<<" -> "<<prefix<<endl;
}
 
/*
Here we start with the prefix value equal to the string we are able to match
Then the remaining words are printed as suggestions
Time Complexity: O(mn) worst case assuming none of the strings in trie match
If prefix length is l, and number of words prefix matches is k
then average time complexity is O(m-l)(k)
*/
void suggest(string key,int pos,node * root,string& prefix){
    if(root->ptrs[key[pos]-'a'] && root->ptrs[key[pos]-'a']->val==key[pos]){
		prefix += key[pos];
		suggest(key,pos+1,root->ptrs[key[pos]-'a'],prefix);
    }
    else{
            printall(prefix,root);
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
	string null = "";
    printall(null,root);
    cout<<"Enter the word to be searched for : ";
    getline(std::cin,key);
    if (!find(key, 0, root)){
        cout<<endl<<"The spelling is incorrect, Possible suggestions are :"<<endl;
        suggest(key,0,root,null);
    }
  
	cin.clear();
	getchar();
    return 0;
}

