/*
Ascending order sort using heaps.
Min heap techique used to find minimum number in a set
First gotcha: 
Keeping the top minimum element and moving the counter to next element to find the minimum in the set.  
The problem with this is, the resulting elements position does not start at position 0
Second gotcha:
Using arrays instead of vector. With vector very easy to debug(dont have to use memory monitor) and deleting top element is easy
Next step is to do the same using arrays and doing a descending order sort

//Things to help remember this algorithm
1) Where to start this problem, with the realization that 2*index is left child and 2*index+1 is right child
2) Then we should solve the problem from middle. Determine middle is easy by taking the (high-low)/2
3) Then exchange the minimum element with the minimum children elements. 
4) After exchange make sure the minimal property of the tree is maintained. Run findMinimum if the node has children
5) Do this till you reach the first element in the array
6) After i=0 reached, the minimum element is in the root of the tree
7) Print this out, remove the element from tree(Very Important)
8) Again start over from the middle by passing vector, low, high to Step 1
9) Repeat this process till vector is empty

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
	if (low * 2 >= high)
		return;
	int mid = low + (high -low) / 2;
	int swapId = mid;
	while (mid>=0){
		int leftChild = (mid * 2) + 1;
		int rightChild = leftChild + 1;
		if ((leftChild <= high) && (vec[swapId] > vec[leftChild])){
			swapId = leftChild;
		}
		if ((rightChild <= high) && (vec[swapId] > vec[rightChild])){
			swapId = rightChild;
		}
		if (mid != swapId){
			swap(vec[mid], vec[swapId]);
		}
		mid--;
	}
}

void heapSort(vector<int> &vec, int low, int high){
    findMinimun(vec,low,high);
    int index = high-1;
	while (!vec.empty()){
      cout << vec[0] << " ";
      vec.erase(vec.begin()); //remove top minimum element
      findMinimun(vec, low, vec.size() - 1);
	}
    cout << endl;
}
int main(){
    //Test Case 1
	vector<int> v = { 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	cout << "The sorted array is: ";
	heapSort(v, 0, v.size()-1);

	//Test Case 2
	vector<int> v2 = { 1,1,1,1,1,1,1};
	cout << "The sorted array is: ";
	heapSort(v2, 0, v2.size() - 1);

	getchar();
	return 0;
}