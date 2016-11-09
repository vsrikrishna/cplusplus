nclude <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
It was not clear from the question if an array element is equal to target sum, should we return true or false.
I am using a macro to enable/disable considering array element as a target sum. 
If target sum is one of the elements in the array, we can set this macro to 1 to not consider it 
*/
#define NO_ARR_ELEM_AS_SUM 0

bool checkTarget(vector<int> arr, int target){
  int start=0,end=0,intSum=0;
  while(end<arr.size()){
    if(intSum+arr[end]<=target){
      intSum+=arr[end];
      end++;
    }else{
      intSum-=arr[start];
      start++;
    }
    cout<<"start:"<<start<<", end:"<<end<<", intSum:"<<intSum<<endl;
    #if NO_ARR_ELEM_AS_SUM
      if(intSum==target && (end-start)>1){
    #else      
      if(intSum==target){
    #endif    
        return true;
    }
    if(start>end){
      intSum = 0;
      end = start;
    }
  }
  return false;
}

int main()
{
  vector<int> arr={1,2,3,6};
  bool res = checkTarget(arr,6);
  cout<<"res:"<<res<<endl;
  return 0;
}
