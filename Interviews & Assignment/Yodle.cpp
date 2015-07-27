/*
By starting at the top of the triangle and moving to adjacent numbers on the row below, the maximum total from top to bottom is 27.
5
9  6
4   6  8
0   7  1   5
I.e. 5 + 9 + 6 + 7 = 27.

Write a program in a language of your choice to find the maximum total from top to bottom in triangle.txt, a text file
containing a triangle with 100 rows. Send your solution and resume to [123456 AT yodle dot com], replacing 123456 with the maximum
sum for the triangle.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


int main() {
	string in;
	ifstream inFile("input.txt");
	int val,maxVal;
	long int maxSum=0;
	if (inFile.is_open()){
	   while (getline(inFile, in)){
	      istringstream sstr(in);
		  maxVal = 0;
	      while (sstr >> val){
			 if (val > maxVal){
				 maxVal = val;
			 }
	      }
		  cout << "Line maxValue is : " << maxVal << endl;
		  maxSum += maxVal;
	   }
	   fflush(stdin);
	   cin.clear();
	}
	inFile.close();

	cout << "maxSum is " << maxSum << endl;
	getchar();
    return 0;
}
