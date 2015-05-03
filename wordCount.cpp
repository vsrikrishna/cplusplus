/*
** Read words from the file and store the word in a map(string,int)
(int,string)
Array to hold the count value and sort it
Come back and print the map values based on array sorting

ASSUMPTIONS:
1) Only Aplphanumeric values(a-z,A-Z,0-9) are inserted
2) The characters are considered case insensitive. 2 words, differing by their case, are considered the same
3) The output is displayed in ascending order of frequency
4) Only english words are considered

Complexity:
Time: logarthmic
Space: O(N) //where N is number of elements
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

template <typename A, typename B>
multimap<B, A> reverse_map(map<A, B> &src){
	multimap<B, A> dst;
	for (auto &i : src){
		dst.insert(pair<B, A>(i.second, i.first));//logarthmic
	}
	return dst;
}

int main(){
	string word;
	map<string, int> myMap;

	ifstream reader;
	reader.open("wordCount.txt");
	if (reader.is_open()){
		while (!reader.eof()){
			reader>>word;
			transform(word.begin(), word.end(), word.begin(), ::tolower); //linear complexity
			if (myMap.find(word) == myMap.end()){//logarthmic complexity(red-black tree)
				myMap[word] = 1; //logarthmic
			}
			else{
				myMap[word]=myMap[word]+ 1; //logarthmic
			}
		}
	}
	multimap<int,string>revMap = reverse_map(myMap);//logarthmic
	for (auto &rMap : revMap){
		cout << rMap.second << " => " << rMap.first << endl;
	}
	cin.clear();
	getchar();
	return 0;
}