#include "iostream"
using namespace std;

void print(int *input, int n)
{
	for (int i = 0; i < n; i++)
		cout << input[i] << " ";
}

void shiftRight(int* arr, int low, int high)
{
   if ((low * 2) > high) return;
   int mid = low + (high - low) / 2;
   int swapIdx = mid;
   int leftChild, rightChild;
   while (mid >= 0){
	   leftChild = (2*mid);
	   rightChild = leftChild + 1;
	   /*Check if root is less than left child*/
	   if ((leftChild <= high) && arr[swapIdx] < arr[leftChild])
	   {
		   swapIdx = leftChild;
	   }
	   /*If right child exists check if it is less than current root*/
	   if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
	   {
		   swapIdx = rightChild;
	   }
	   /*Make the biggest element of root, left and right child the root*/
	   if (swapIdx != low)
	   {
		   int tmp = arr[low];
		   arr[low] = arr[swapIdx];
		   arr[swapIdx] = tmp;
	   }
	   mid--;
   }
}
void heapSort(int* arr, int size)
{
	/*This will put max element in the index 0*/
	int high = size - 1;
	shiftRight(arr, 0, high);	
	while (high > 0)
	{
		/*Swap max element with high index in the array*/
		int tmp = arr[high];
		arr[high] = arr[0];
		arr[0] = tmp;
		high--;
		/*Ensure heap property on remaining elements*/
		shiftRight(arr, 0, high);
	}
}

int main(){
	int input[9] = {0,1,2,3,4,5,6,7,8};
	int input2[7] = {1,1,1,1,1,1,1};
	cout << "Input: ";
	print(input, 9);
	heapSort(input, 9);
	cout << "\nOutput: ";
	print(input, 9);
	cout << "\n";
	cout << "Input: ";
	print(input2, 7);
	heapSort(input2, 7);
	cout << "\nOutput: ";
	print(input2, 7);
	cout << "\n";
	getchar();
	return 0;
}