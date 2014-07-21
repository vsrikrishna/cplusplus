#include<iostream>
#include<fstream>
#include<string>
using namespace std;
 
int found=0;

struct node{
    char info;
    string Word;
    node* ptrs[256];
};

void insertword(string word,int pos, node*& root){
	if (root == NULL){
		root = new node;
		for (int i = 0; i<256; i++){
			root->ptrs[i] = NULL;
		}
		root->info = NULL;
		root->Word = "";
	}
	if(word.length()==pos){
        root->Word=word;
        return;
    }
    if( root-> ptrs[word[pos]]==NULL ){
        node *newnode;
        newnode= new node;
        newnode->info=word[pos];
		for (int i = 0; i<256; i++){
			newnode->ptrs[i] = NULL;
		}
        root->ptrs[word[pos]]=newnode;
        insertword(word,pos+1,root->ptrs[word[pos]]);
    }
    else

		insertword(word,pos+1,root->ptrs[word[pos]]);
}
 
void find(string key,int pos,node * root){
    if((key != root->Word) && (root->ptrs[key[pos]] != NULL))
        find(key,pos+1,root->ptrs[key[pos]]);
    else if(key==root->Word){
        cout<<"The spelling of the word '"<<root->Word<<"' is correct"<<endl;
        found=1;
    }
}
 
void printall(node * root){
    for(int i=0;i<256;i++)
        if(root->ptrs[i]!=NULL){
            printall(root->ptrs[i]);
        }
    if(root->Word != "")
        cout<<" -> "<<root->Word<<endl;
}
 
void suggest(string key,int pos, node * root){
    if((key != root->Word) && (root->ptrs[key[pos]] != NULL)){
            suggest(key,pos+1,root->ptrs[key[pos]]);
    }
    else{
            printall(root);
    }
}
 
int main(){
    ifstream in("wordlist.txt");
    string word,current="",key;
     node* root = NULL;
    while(!in.eof()){
        getline(in,word);
        insertword(word,0,root);
    }
    in.close();
    cout<<endl<<"Trie Construction Successful"<<endl;
    printall(root);
    cout<<"Enter the word to be searched for : ";
    getline(std::cin,key);
    find(key,0,root);
    if(!found){
        cout<<endl<<"The spelling is incorrect, Possible suggestions are :"<<endl;
        suggest(key,0,root);
    }
	cin.clear();
	getchar();
    return 0;
}

