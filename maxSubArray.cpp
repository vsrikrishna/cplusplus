/*
 Write a program to find contigous max sub array from input numbers. You should return the sequence not the sum alone
 Mention the time and space complexity. 
 Time Complexity: O(n) since all the elements are traversed only once
 Space Complexity: O(1) since extra space is not used
 Computed using Kadane's algorithm
*/

#include <iostream>
using namespace std;

int maxSum(int *arr, int count){
	int start, end,pos_sum,overall_sum;
	start=end=overall_sum=pos_sum = 0;

	for (int i = 0; i<count;i++){
		if ((pos_sum + arr[i]) > 0)
			pos_sum += arr[i];
		else
			pos_sum = 0;

		if (pos_sum > overall_sum)
			overall_sum = pos_sum;
	}
	return overall_sum;
}
int maxSumWithPos(int *arr, int count){
	int start, end, pos_sum, overall_sum,local_start,local_end;
	local_start=local_end=start = end = overall_sum = pos_sum = 0;

	for (int i = 0; i<count; i++){
		if ((pos_sum + arr[i]) > 0){
			if (pos_sum == 0){
				local_start = i;
			}
			pos_sum += arr[i];
			local_end = i;
		}
		else{
			pos_sum = 0;
		}
		if (pos_sum > overall_sum){
			overall_sum = pos_sum;
			start = local_start;
			end = local_end;
		}
	}
	cout << "The maxSubArray is: ";
	for (int i = start; i <= end; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return overall_sum;
}
int main(){
	int a[] = {2,-5,4,3,2,-2,-7,9,5};
	cout << "Maximum Subsum is: " << maxSum(a, sizeof(a) / sizeof(int));
	cout << "Maximum Subsum Array is: " << maxSumWithPos(a, sizeof(a) / sizeof(int));
	getchar();
	return 0;
}