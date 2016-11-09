nclude <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;

int smallestSubArray(int arr[], int target, int n){
  int start=0,end=0,sum=0,intStart=0,intEnd=0,count=INT_MAX;
  while(end<n){  
    if(sum+arr[end]<=target){
      sum+=arr[end++];
    }else{
     sum+=arr[end++];
     while(sum-arr[start]>target && start<end){
       sum-=arr[start++];
     }
    }    
    if(sum>target){
      if((end-start)<count){
        count = end -start;
        intStart = start;
        intEnd = end;
      }
    }
    
    if(start>end){
      end=start;
      sum=0;
    }
  }
  cout<<"start:"<<intStart<<", end:"<<intEnd<<", count:"<<count<<endl;
  return count;
}
int main()
{
  int arr[]={1,4,45,6,51,19};
  int target;
  cout<<"Enter the number to be checked"<<endl;
  cin>>target;
  cout<<"Smallest subarray size is: "<<smallestSubArray(arr,target,sizeof(arr)/sizeof(arr[0]))<<endl;
  return 0;
}
