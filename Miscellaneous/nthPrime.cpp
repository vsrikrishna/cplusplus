#include <iostream>
#include <cmath>
using namespace std;

int nthPrime(int n){
	int num;
	int i = 2;
	bool isPrime;
	if (n == 1){
	   return 2;
	}
	if (n == 2){
	   return 3;
	}
	int count = 2;
	i = 4;
	while (count != n){
		i++;
		isPrime = true;
		for (int j = 2; j <= ceil(sqrt(i)); j++){
			if (i %j == 0){
				isPrime = false;
			}
		}
		if (isPrime == true){
			count++;
		}		
	}
	if (count == n) return i;

}

int main(){
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	cout << nthPrime(n) << endl;
	cin.clear();
	getchar();
	return 0;
}