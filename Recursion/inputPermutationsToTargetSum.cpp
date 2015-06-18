/*
Amazon Problem - Example for recursion
Write a function that takes two arguments one array of integers that ranges between 0 and 9 and second the target sum(again integer).It produces all permutations strings of the input digits that equals the target sum.
For example, if input is array 2, 3, 5 and target sum is 10, then the output should be :
22222 because 2 + 2 + 2 + 2 + 2 = , 10
2323 as 2 + 3 + 2 + 3 = 10
3232
55
2233
3322
532
235
352
etc.,
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> out;
stringstream oss;
void printPermutations(){
	cout << "The different output strings are:" << endl;
	for (auto &i : out){
		cout << i << endl;
	}
}
void recurPermutations(vector<int> &arr, int sum, string str){
	if (sum == 0){
		out.push_back(str);
	}
	if (sum <= 0){
		return;
	}
	for (int i = 0; i < arr.size(); i++){
		oss.clear();
		oss.str(std::string());
		oss << str << arr[i];
		recurPermutations(arr, sum - arr[i], oss.str());
	}
}
int main(){
	vector<int> arr = { 2, 3, 5 };
	int sum = 10;
	recurPermutations(arr, sum, "");
	printPermutations();
	getchar();
	return 0;
}