/*
Amazon problem
Say you have a keypad that has keys for the numbers 0 through 9 and the correct code is some sequence of 5 digits.
This keypad does *not* reset after entering an incorrect sequence of 5 digits.ie.If the correct sequence is 12345, 
entering 7512345 will succeed in opening it because it ends in the correct sequence.If the keypad actually 
resets after every 5 digits pressed, then it would not succeed b / c it would interpret the above sequence as "75123" then "45".

1. Write an algorithm that will try to find the correct code for this keypad.
Assume you have an API similar to KeyPad.pressKey(int n) where you pass in a number(0...9) 
and it returns true if the keypad unlocks and false if it's still locked. 

Note that you could easily enter all digits of all numbers 00000 through 99999 resulting in 5 * 100000 key presses, 
but remember that the panel does not reset after every sequence of 5 digits, so find a way to do this more efficiently.
Notice for example that entering the stream 3791283780 will test the length 5 sequences 37912, 79128, 91283, 12837, 
28378, 83780; not only the two disjoint sequences 37912 and 83780.

Think of this keypad as remembering the last 4 keys pressed(and the order pressed); when the next key is pressed, 
if the last 4 keys + the current key equal the correct code, the keypad will unlock. Assume the keypad does all 
this internally, so you can just keep feeding it keypresses and it will eventually unlock if the last 5 
keypresses entered is the correct code.

2. Generalize your algorithm to work for a keypad where you don't know the length of the correct sequence in advance.
06/13/2015
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string keyPressed(int num){
	stringstream ss;
	string key = "12345";
	string test;
	ss << num;
	string str;
	ss >> str;
	for (int i = 0; i <= str.length() - key.length(); i++){
		test = str.substr(i, key.length());
		if (test == key){
			return "worked";
		}
	}
	return "failed";
}
int main(){
	cout << "The keypad unlocking " << keyPressed(6712345) << endl;
	getchar();
	return 0;
}
