/*
Binary Search Method
This acts as a place holder for all binary search related algorithms
1) Regular Binary Search
2) Reduced Comparison Binary Search
3) Finding duplicate element in sorted array 
4) Lower Bound, Upper Bound
5) Finding minimal element in rotated array
07/30/2015
*/
#include <iostream>
using namespace std;

/*
Question:
   How do we know that the element in array is captured in mid
Answer:   
   The catch in this particular algorithm is:
   When the l & r pointers move towards each other, they will converge on 
   one element eventually. When that happens, if that is key, it is returned
   in first check
   Time Complexity: O(log n)
*/

int binarySearch(int* arr, int l, int r, int key){
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (key == arr[mid])
			return mid;
		else if (key < arr[mid])
			r = mid-1;
		else
			l = mid+1;
	}
	return -1;
}

/*
The idea in this algorithm is to reduce the comparisons in while loop
So the comparison is moved out and the key element is converged on and searched outside
This technique will optimize the search 
1) when key cannot be found in first few iterations
2) when the array is large power of 2
Loop Termmination Condition: l==r
Time Complexity: O(log n)
The advantage of this search over previous one is:
The comparison is reduced in the while loop
*/
int reducedComparisonBinarySearch(int *arr, int l, int r, int key){
	while (r-l>1){
     	int mid = l + (r - l) / 2;
    	if (key < arr[mid])
    		r = mid - 1;
    	else
    		l = mid;
    }
	if (arr[l] == key)
		return l;
	else
		return -1;
}

/*
Find indicies for a number
Lower and upper bound index
*/
int findCount(int *arr, int low, int high, int key){
	int lowIndex = -1;
	int highIndex = -1;
	int upperLow = low;
	int upperHigh = high;

	//lower-bound
	while (low <= high){
		int mid = low + (high - low) / 2;
		if (arr[mid]>key){
			high = mid - 1;
	    }
		else if (arr[mid] == key){
		   high = mid - 1;
		   lowIndex = mid;
	    }
		else{
			low = mid + 1;
		}
	}

	//upper bound
	while (upperLow <= upperHigh){
		int mid = upperLow + (upperHigh-upperLow) / 2;
		if (arr[mid] < key){
			upperLow = mid + 1;
		}
		else if (arr[mid] == key){
			upperLow = mid + 1;
			highIndex = mid;
		}
		else{
			upperHigh = mid - 1;
		}
	}

	if (lowIndex != -1 && highIndex != -1){
		return (highIndex - lowIndex + 1);
	}
	else
		return 0;
}

/*
Complextiy: O(log n) if the element can be found in array
Runs sequential search if binary does not work
*/
int findLowest(int *arr, int low, int high){
	if (arr[low] < arr[high]){
		return arr[low];
	}
	while (low<=high){
		if (low == high) return arr[low];
		int mid = low + (high - low) / 2;
		if (arr[low] == arr[mid] && arr[mid] == arr[high]){
			cout << "Cannot use this method for search" << endl;
			cout << "Please try sequential search for this set" << endl;
			return -1;
		}
		if (arr[mid]<arr[high]){
			high = mid;
		}
		else{
			low = mid + 1;
		}
	}
	return -1;//could not find the element
}

/*
Turning number problem
*/
int turningNum(int *arr, int low, int high){
	while (low <= high){
		int mid = low + (high - low) / 2;
		if (low == high) return arr[low];
		/*if (arr[mid] >= arr[low] && arr[high] >= arr[mid]){
			cout << "The array is sorted and there is no turning element" << endl;
			return -1;
		}*/
		if (arr[mid]<arr[high]){
			low = mid + 1;
		}
		else{
			high = mid;
		}
	}
	return -1;//could not find the element
}

int main(){
	int arr1[] = {1,2,2,3,4,5};
	int position = binarySearch(arr1,0,sizeof(arr1)/sizeof(int),4);
	cout << "The position of arr1 key element is: " << position << endl;
	
	int arr2[] = {1,2,2,3,4,5};
    position = reducedComparisonBinarySearch(arr2,0,sizeof(arr2)/sizeof(int),1);
	cout << "The position of arr2 key element is: " << position << endl;

	int arr3[] = {1,1,1,2,2,3,3,4,4,4,5};
	int count = findCount(arr3,0,sizeof(arr3)/sizeof(int),1);
	cout << "The number of occurrences of 1 is: " << count << endl;

	count = findCount(arr3, 0, sizeof(arr3) / sizeof(int), 2);
	cout << "The number of occurrences of 2 is: " << count << endl;

	count = findCount(arr3, 0, sizeof(arr3) / sizeof(int), 6);
	cout << "The number of occurrences of 6 is: " << count << endl;

	int low[] = {3,4,5,2};
	int lowest = findLowest(low,0,(sizeof(low)/sizeof(int)-1));
	cout << "The lowest element in set is: " << lowest << endl;

	int turn[] = {1,2,3,8,7,6,5,4};
	int turning = turningNum(turn, 0, (sizeof(turn) / sizeof(int)-1));
	cout << "The turning element in set is: " << turning << endl;

	int turn2[] = { 1, 2, 7, 6, 5, 4, 3};
	int turning2 = turningNum(turn2, 0, (sizeof(turn2) / sizeof(int)-1));
	cout << "The turning element in set is: " << turning2 << endl;

	getchar();
	return 0;
} 