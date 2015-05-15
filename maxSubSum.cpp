/*
Write a program to find contigous max sub array from input numbers. You should return the sequence not the sum alone
Mention the time and space complexity.
Time Complexity: O(n) since all the elements are traversed only once
Space Complexity: O(1) since extra space is not used
Used Kadane's algorithm to solve this...
*/

#include <iostream>
using namespace std;

int maxSum(){

	int start, end, pos_sum, overall_sum, count, value;
	start = end = overall_sum = pos_sum = 0;
	cout << "Enter the number of elements" << endl;
	cin >> count;
	cout << "Enter the elements" << endl;
	int i = 0;
	while (i < count){
		cin >> value;
		if ((pos_sum + value) > 0)
			pos_sum += value;
		else
			pos_sum = 0;

		if (pos_sum > overall_sum)
			overall_sum = pos_sum;
		i++;
	}	
	return overall_sum;
}
int main(){
	//int a[] = { 2, -5, 4, 3, 2, -2, -7, 9, 5 };
	cout << "Maximum Subsum is: " << maxSum();
	cin.ignore();
	getchar();
	return 0;
}