#include "iostream"
#include "vector"
using namespace std;

void swap(int *first, int* second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

int partition(int* arr, int first, int last){
	int up, down, buffer, pivot;
	up = first;
	down = last - 1;
	pivot = arr[last];

	while (up <= down){
		while (arr[up] < pivot)
			up++;
		while (arr[down] > pivot)
			down--;
		if (up <= down){
			swap(arr[up], arr[down]);
			up++; down--; //this will be useful during sorted repeated number array
		}
	}
	swap(arr[up], arr[last]);
	return up;
}

/*
Things to help remember this algorithm:
1) YOU CAN"T USE SIZEOF on int arr[] input since compiler optimizes it to int*
2) Changing the pivot if it is not the required pivot. You should reposition high to pivot-1
*/
int ksmallestnumber(int arr[], int k, int size){
	if (k > size)
		return -1;
	int i = 0, low = 0, high = size - 1;
	while (i < size){
		int pivot = partition(arr, low, high);
		if (pivot == k - 1)
			return arr[pivot];
		if (pivot> k - 1)
			high = pivot-1;
	}
	return -1; //could not find element
}

void quickSort(int* arr, int low, int high)
{
	if (low<high)
	{
		int pivot = partition(arr,low,high);
		quickSort(arr,low,pivot - 1);
		quickSort(arr,pivot + 1, high);
	}
}

void print(int arr[], int n){
	for (int i = 0; i < n; i++)
		cout << arr[i];
	cout << endl;
}
int main()
{
	//Test 1
	int arr1[] = { 7, 6, 4, 3, 1, 2, 0 };
	int size1 = sizeof(arr1) / sizeof(int);
	cout << "3rd smallest element is: " << ksmallestnumber(arr1,3,size1)<<endl;
	cout << "2nd smallest element is: " << ksmallestnumber(arr1,2,size1)<<endl;
	cout << "5th smallest element is: " << ksmallestnumber(arr1,5,size1)<<endl;

	//Test 2
	int arr2[] = { 0 };
	int size2 = sizeof(arr2) / sizeof(int);
	cout << "1st smallest element is: " << ksmallestnumber(arr1, 1, size2) << endl;
	cout << "2nd smallest element is: " << ksmallestnumber(arr1, 2, size2) << endl;


	getchar();
	return 0;
}
