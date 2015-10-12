/*
 * Summarize gaps in a list of integers. All integers are in the range 0 to 99.
e.g. input [0, 1, 2,50, 52, 75] should result in a output string "3-49,51,53-74" 
Test inputs for the same.
*/

#include "iostream"
#include <string>
#include <sstream>
using namespace std;

void missingNos(int arr[], int length){
   string outString;
   ostringstream oss;
   oss.clear();
   int startIndex, endIndex;  
   int i=0; 
   bool flag = false;
   cout << "Printing the array" << endl;
   for (int i = 0; i<length; i++){
	   cout << arr[i]<<" ";
   }
   cout << endl;
   
   for(int i=0;i<length;i++){
      if (i == 0 && arr[i]>1){
		  if (arr[i]>2){
			  oss << "1-" << arr[i] - 1<<",";
		  }
		  else{
			  oss << "1,";
		  }
      }
	  while (((arr[i + 1] - arr[i]) == 1)&&arr[i]<100){
		  i++;
	  }
	  startIndex = arr[i];
	  if (i + 1 == length){
         if (arr[i] < 100){
            endIndex = 100;
         }
		 else{
            continue;
         }
	  }
	  else{
		endIndex = arr[i+1];
	  }
	  	  
	  if (endIndex-startIndex > 1){
		  if (endIndex-startIndex == 2){
			  oss << startIndex+1 << ",";
		  }
		  else if (endIndex - startIndex > 2){
            oss << startIndex + 1 << "-" << endIndex - 1 << ",";
		  }
	  }else{
		     //Do Nothing		  

	  }

   }//end of for loop
   cout << "Printing output String" << endl;
   cout<<oss.str()<<endl;   
}

int main(){
    int arr1[] = {0,1,2,50,52,75};
	int arr2[] = {0,2,4,94,96,98};
	int arr3[] = {5,50,99};
	int arr4[] = {0,1,2,3,98};
    missingNos(arr1, (sizeof(arr1)/sizeof(int)));
	cout << endl;
	missingNos(arr2, sizeof(arr2) / sizeof(int)); 
	cout << endl;
	missingNos(arr3, sizeof(arr3) / sizeof(int));
	cout << endl;
	missingNos(arr4, sizeof(arr4) / sizeof(int));
	cout << endl;
	cin.ignore();
	getchar();
    return 0;
}