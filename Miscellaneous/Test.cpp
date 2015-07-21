// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <ctype.h>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
	int sol = -1;
	bool flag = false;
	int count = 0;
	int maxcount = -1;
	for (int i = 0; i< S.length(); i++){
		int letter = S[i];
		cout << "letter is " << letter << endl;
		cout << "count is" << count << endl;
		//if (isdigit(letter)){
	    if (48 <=letter <= 57){
			count = 0;
		}
		//else if (isupper(letter)){
		else if (65 <= letter <=90){
			flag = true;
			count++;
		}
		//else if (islower(letter)){
		else if (97 <= letter <= 122){
			count++;
		}
		if (count>maxcount){
			maxcount = count;
		}
	}
	if (flag) sol = maxcount;
	return sol;
}

int main(){
	string temp = "a0Ab";
	int i = solution(temp);
	cout << "The answer is: " << i << endl;
	cin.clear();
	getchar();
	return 0;

}