/*
Ascending order sort using heaps.
Min heap techique used to find minimum number in a set
First gotcha: 
Keeping the top minimum element and moving the counter to next element to find the minimum in the set.  
The problem with this is, the resulting elements position does not start at position 0
Second gotcha:
Using arrays instead of vector. With vector very easy to debug(dont have to use memory monitor) and deleting top element is easy
Next step is to do the same using arrays and doing a descending order sort

Time Complexity: O(nlogn) - We find minimum n times. finding minimum using trees is log n. So nlog n is 
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

void swap(int& num1, int& num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void findMinimun(vector<int> &vec, int low, int high){
	if (low * 2 + 1 >= high)
		return;
	int swapId = low;
	int leftChild = (low * 2) + 1;
	int rightChild = leftChild + 1;
	if (vec[swapId]>vec[leftChild] && leftChild <= high){
		swapId = leftChild;
	}
	if (rightChild <= high  && vec[swapId] > vec[rightChild]){
		swapId = rightChild;
	}
	if (low != swapId){
		swap(vec[low], vec[swapId]);
		findMinimun(vec, swapId, high);
	}
}
void minHeap(vector<int> &vec, int low, int high){
	int mid = (high - low - 1) / 2;
	while (mid >=low){
		findMinimun(vec, mid, high);
	  mid--;
	}
}
void heapSort(vector<int> &vec, int low, int high){
	minHeap(vec, low, high);
	int index = high-1;
	while (!vec.empty()){
	  cout << vec[0] << " ";
	  vec.erase(vec.begin()); //remove top minimum element
	  findMinimun(vec, low, vec.size() - 1);
	}
	cout << endl;
}
int main(){
	vector<int> v = { 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	cout << "The aorted array is: ";
	heapSort(v, 0, v.size()-1);
	getchar();
	return 0;
}