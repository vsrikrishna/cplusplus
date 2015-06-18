/*
Algorithm to find unique character

ASSUMPTIONS:
1) Ascii characters in the input
2) Input from a file
3) Assuming inputs are case sensitive


COMPLEXITY:
Time Complexity: O(n)
Space Complexity:O(1) - Here I am considering a constant array of 256 chars to represent ascii set. This length will not change with input(n) size 
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void findUnique(string in){
	int a[256] = {};
	//fill_n(a, 256, -1);
	int temp;
	bool found = false;
	for (auto i : in){
		a[(int)i]++;
	}
	for (auto j:in){
		if (a[(int)j] == 1){
			cout << j << endl;
			found = true;
			break;
		}
	}
	if (!found) cout << "#" << endl;
	
}
int main(){
	ifstream inFile;
	int noOfTests;
	string word;
/*	inFile.open("uniqueChar.txt");
	if (inFile.is_open()){
		inFile >> noOfTests;
		while (noOfTests){
			inFile >> word;
			findUnique(word);
			noOfTests--;
		}
	}
*/
	cin >> noOfTests;
	while (noOfTests){
		cin >> word;
		findUnique(word);
		noOfTests--;
	}
	cin.ignore();
	cin.clear();
	getchar();
	return 0;
}