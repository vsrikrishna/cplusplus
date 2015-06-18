/*
Quick Sort Implementation 1
Basic implementation of quick sort algorithm
July 21 2013
3 hours
*/

#include <iostream>
#include <vector>
using namespace std;

int partition(int first, int last, vector<int>& myVector){
	int up, down, buffer, pivot;
	up = first;
	down = last;
	pivot = myVector[last];

	while (true){
		while ((myVector[up] < pivot) && (up<down)){
			up++;
		}
		do{
			down--;
		} while ((myVector[down] > pivot) && (up<down));

		if (up >= down){
			buffer = myVector[up];
			myVector[up] = myVector[last];
			myVector[last] = buffer;
			return up;
		}
		buffer = myVector[down];
		myVector[down] = myVector[up];
		myVector[up] = buffer;
	}
}

void quick_sort(int low, int high, vector<int>& myVector)
{
	if (low<high)
	{
		int pivot = partition(low, high, myVector);
		quick_sort(low, pivot - 1, myVector);
		quick_sort(pivot + 1, high, myVector);
	}
}
void quick_sort_descending(int low, int high, vector<int>& myVector){

	vector<int> vectorOutput;
	vectorOutput.resize(myVector.size());
	for (int i = 0; i < myVector.size(); i++){
		vectorOutput[i] = myVector[i];
	}

	quick_sort(low, high, vectorOutput);

	for (int i = 0, j = myVector.size() - 1; j >= 0; j--){
		myVector[i++] = vectorOutput[j];
	}
}

int main()
{
	int userInput;
	int size;
	cout << "Enter the size of myVector" << endl;
	cin >> size;
	cin.clear();
	vector<int> myVector;

	for (int j = 0; j< size; j++){
		cout << "Enter the numbers into myVector" << endl;
		cin >> userInput;
		cin.clear();
		myVector.push_back(userInput);
	}
	quick_sort_descending(0, myVector.size() - 1, myVector);
	cout << "Sorted elements are:" << endl;
	for (int i = 0; i < myVector.size(); i++){
		cout<< myVector[i]<<endl;
	}
	getchar();
	return 0;
}
