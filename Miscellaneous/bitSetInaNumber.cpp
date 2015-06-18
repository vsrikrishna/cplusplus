/**
05/28/2015
Count number of bits set in a integer
Time Complexity - Theta(log n)
As n increases it is propotional to log n.

Brian Kerningan Method Count
Just count the number of bit sets instead of going through all the bits
Time Complexity - O(logn)
As n increases it is atmost propotional to log n.
Input 5 - Output 2
Input 3 - Output 2
Input 7 - Output 3
*/
#include <iostream>
using namespace std;

int bitCount(int num1){
	int temp = num1;
	int one = 1;
	int count = 0;
	while (temp){
		if (temp & one){
			count++;
		}
		temp = temp >> 1;
	}
	return count;
}

int brianKerninganCount(int num){
	int temp = num;
	int count = 0;
	while (temp){
        temp = temp & (temp - 1);
		count++;
	}
	return count;
}

int main(){
	int num;
	cout << "Enter the number to check bits set" << endl;
	cin >> num;
	cout << "Number of bits set is: " << bitCount(num) << endl;
	cout << "Number of bits set is: " << brianKerninganCount(num) << endl;
	cin.ignore();
	getchar();
}
