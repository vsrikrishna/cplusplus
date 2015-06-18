/*
Insertion Sort 
July 29 2013
*/
#include "conio.h"
#include "iostream"
#include "vector"
using namespace std;

void insertion_sort(vector<int>& numbers){
   int i,key;
   for(size_t j=1; j<(numbers.size()); j++){
      i=j-1;
	  key = numbers[j];
	  while(i>=0 && numbers[i]> key){
         numbers[i+1] = numbers[i];
		 i--;
	  }
	  numbers[i+1]= key;
   }
}
int main(){
   int length,num;
   vector<int> numbers;
   cout << "Enter number of elements" << endl;
   cin>> length; 
   for(int i=0; i<length;i++){
      cout << "Enter the elements to be sorted"<< endl;
	  cin>>num;
	  numbers.push_back(num);
   }
   insertion_sort(numbers);
   return 0;
}