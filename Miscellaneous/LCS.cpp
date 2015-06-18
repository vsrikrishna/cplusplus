/*
 Least Common Subsequence(LCS)
 Find the common subsequence between 2 sequences
 Dynamic programming method
 Time Complexity: O(mn)
 Space Complexity: O(mn)
 */
#include <iostream>
#include <stack>
using namespace std;

void LCS(int *a1, int size1, int *a2, int size2){
	int out[100][100] = {};
	stack<int> S;
	for (int i = 0; i <= size1; i++){
		for (int j = 0; j <= size2; j++){
			if (i == 0 || j == 0)
				out[i][j] = 0;
			else{
				if (a1[i-1] == a2[j-1]){
					if (out[i][j - 1] > out[i - 1][j])
						out[i][j] = out[i][j - 1] + 1;
					else
						out[i][j] = out[i - 1][j] + 1;
				}
				else{
					if (out[i][j - 1] > out[i - 1][j])
						out[i][j] = out[i][j - 1];
					else
						out[i][j] = out[i - 1][j];
				}
			}
		}
	}

	//Backtracing to print the numbers
	int i = size1 - 1, j = size2 - 1;
	while (i >= 0 || j >= 0){
		if (a2[j] != a1[i]){
			if (out[i][j - 1] > out[i - 1][j])
				j--;
			else
				i--;
		}
		else{
			S.push(a2[j]);
			i--; j--;
		}
	}
	cout << "The least common subsequence is:" << endl;
	while (!S.empty()){
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
}

int main(){
	int arr1[] = {5,4,3,2,7,9};
	int arr2[] = {4,3,2,5,6};
	LCS(arr1,sizeof(arr1)/sizeof(int),arr2,sizeof(arr2)/sizeof(int));
	getchar();
	return 0;
}