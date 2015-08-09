/*
Quick Sort Implementation 1
Basic implementation of quick sort algorithm
July 21 2013 
3 hours
*/

#include "iostream"
#include "vector"
using namespace std;

void swap(int *first, int* second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

int partition(int first, int last, int* arr){
   int up,down,buffer,pivot;
   up = first;
   down = last-1;
   pivot = arr[last];

   while(up<=down){
      while(arr[up] < pivot)
         up++;
	  while(arr[down] > pivot)
         down--;
	  if(up<=down){
		  swap(arr[up], arr[down]);
		  up++; down--; //this will be useful during sorted repeated number array
	  }
   }
   swap(arr[up], arr[last]);
   return up;
}

void quickSort(int low, int high, int* arr)
{     
   if(low<high)
   {
      int pivot =  partition(low,high,arr);
      quickSort(low,pivot-1,arr);
      quickSort(pivot+1,high, arr);
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
	quickSort(0,size1-1,arr1);
	print(arr1,size1);

	//Test 2
	int arr2[] = { 0,1,2,3,4,7,6,5 };
	int size2 = sizeof(arr2) / sizeof(int);
	quickSort(0, size2-1, arr2);
	print(arr2, size2);

	//Test 3
	int arr3[] = {1,1,1,1,1,1,1};
	int size3 = sizeof(arr3) / sizeof(int);
	quickSort(0, size3 - 1, arr3);
	print(arr3, size3);

	getchar();
	return 0;
}
