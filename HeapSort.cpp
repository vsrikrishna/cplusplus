#include "iostream"
using namespace std;

void print(int *input, int n)
{
	for (int i = 0; i < n; i++)
		cout << input[i] << " ";
}

void shiftRight(int* arr, int low, int high)
{
	int root = low;
	while ((root * 2) + 1 <= high)
	{
		int leftChild = (root * 2) + 1;
		int rightChild = leftChild + 1;
		int swapIdx = root;
		/*Check if root is less than left child*/
		if (arr[swapIdx] < arr[leftChild])
		{
			swapIdx = leftChild;
		}
		/*If right child exists check if it is less than current root*/
		if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
		{
			swapIdx = rightChild;
		}
		/*Make the biggest element of root, left and right child the root*/
		if (swapIdx != root)
		{
			int tmp = arr[root];
			arr[root] = arr[swapIdx];
			arr[swapIdx] = tmp;
			/*Keep shifting right and ensure that swapIdx satisfies
			heap property aka left and right child of it is smaller than
			itself*/
			root = swapIdx;
		}
		else
		{
			break;
		}
	}
}
void heapify(int* arr, int low, int high)
{
	/*Start with middle element. Middle element is chosen in
	such a way that the last element of array is either its
	left child or right child*/
	int midIdx = (high - low - 1) / 2;
	while (midIdx >= 0)
	{
		shiftRight(arr, midIdx, high);
		--midIdx;
	}
}
void heapSort(int* arr, int size)
{
	/*This will put max element in the index 0*/
	heapify(arr, 0, size - 1);
	int high = size - 1;
	while (high > 0)
	{
		/*Swap max element with high index in the array*/
		int tmp = arr[high];
		arr[high] = arr[0];
		arr[0] = tmp;
		--high;
		/*Ensure heap property on remaining elements*/
		shiftRight(arr, 0, high);
	}
}

int main(){
	int input[10] = { 143, 123, 222, 186, 235, 9, 905, 428, 543, 373 };
	cout << "Input: ";
	print(input, 10);
	heapSort(input, 10);
	cout << "\nOutput: ";
	print(input, 10);
	cout << "\n";
	getchar();
	return 0;
}