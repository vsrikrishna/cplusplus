// Given infinite number of quarters(25 cents), dimes(10 cents), nickels(5 cents) and pennies(1 cent), 
// write code to calculate number of ways of representing n cents. 
#include <iostream>
#include <string>
using namespace std;

int makeChange(int num, int denom[], int index){
	if (num == 0){
		cout << "num is " << num << ", index is " << index << endl;
	}
	if (denom[index] == 1){
		if (num <= 0){ cout << "Inside return 1" << endl; }
		return 1;
	}
	int denomination = denom[index];
	int count = 0;
	for (int i = 0; (i*denomination) <= num; i++){
		int numRemaining = num - (i*denomination);
		count += makeChange(numRemaining, denom, index + 1);
	}
	//if(count ==0){ cout <<"count is 0"<<endl;}
	return count;
}
int main()
{
	int num;
	int denom[] = { 25, 10, 5, 1 };
	cout << "Enter the number" << endl;
	cin >> num;
	cout << "Total permutations is " << makeChange(num, denom, 0) << endl;
	return 0;
}
