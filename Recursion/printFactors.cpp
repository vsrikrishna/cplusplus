/*prime facctors for a number
C++ program that takes a positive integer and prints out all ways to multiply smaller integers that equal the original number, without repeating sets of factors.  
In other words, if your output contains 4 * 3, you should not print out 3 * 4 again as that would be a repeating set.  
Note that this is not asking for prime factorization only.
07/09/2014
*/
#include "iostream"
#include "math.h"
#include "string"
#include "sstream"
using namespace std;

/**
 * @Method printFactors: Method to print factors for an input number
 * @Input Parameters: 
 *         prevString - previous multiplication string passed to the function 
 *         num - number to be factorized
 */
void printFactors(string prevString, int num){
	if (num < 2) return;//return to calling function if number is less than 2

	stringstream ss;
	int maxDivisor = (int)ceil(sqrt((double)num)); //calculate max divisor number to find the factors

	for (int i = 2; i <= maxDivisor; i++){
		if (num%i == 0){ //Check to see if i is a factor of number
			int quo = num / i; //Checking quo is for avoiding previous factors
			if (quo >= i){
			    cout << prevString << i << "*" << quo << endl;
				ss.clear();
				ss.str("");
				ss << prevString << i << "*"; //Build string for finding factors
				printFactors(ss.str(), quo); //recursive call to print factors for the quotient
			}
		}
	}
}

int main(){
	int num;
	cout << "Enter the number to print factors: ";
	cin >> num;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << "1*" << num << endl; //printing the first factor of number * 1
	printFactors("", num);
	getchar();
	return 0;
}