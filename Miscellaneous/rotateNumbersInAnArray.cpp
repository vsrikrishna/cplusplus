/*
* Rotate numbers in an array
* 05/30/2015
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
Method 1 - Brute Force - Store first d numbers in temp location and move elements by d
Time Complexity:  O(n)
Space Complexity: O(d)
*/
void rotateNumbersMethod1(int *arr,int size, const int d){
	vector<int> temp;
	for (int i = 0; i < d; i++){
		temp.push_back(arr[i]);
	}
	for (int i = 0; i < (size - d); i++){
		arr[i] = arr[i + 2];
	}
	for (int i = size - d, j = 0; i < size; i++,j++){
		arr[i] = temp[j];
	}
	cout << "The array after rotating using first method is:" << endl;
	for (int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}
	cout << endl;
}

/*
Method 2(Optimized): Using deque
Time Complexity: O(n)
Space Complexity: O(1)
*/

void rotateNumbersMethod2(int *arr, int size, int d){
	deque<int> q1;
	int temp;
	for (int i = 0; i < size; i++){
		q1.push_back(arr[i]);
	}
	cout << "The queue before rotating is:" << endl;
	for (int i = 0; i < size; i++){
		cout << q1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d; i++){
		temp=q1.front();
		q1.pop_front();
		q1.push_back(temp);
	}
	cout << "The queue after rotating is:" << endl;
	for (int i = 0; i < size; i++){
		cout << q1[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	rotateNumbersMethod1(arr, 8, 2);
	rotateNumbersMethod2(arr, 8, 2);
	cin.ignore();
	getchar();
	return 0;

}