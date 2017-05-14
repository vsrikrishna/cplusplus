// Programming question in facebook interview
// Actual question: Given 2 inputs: 1) sorted rotated input array and an integer 
// Return true or false if an element exists in that array
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

bool findEle(int l, int r, int key, int arr[]){
  if(l>r) return false;
  int mid = (l+r)/2;
  if(arr[mid]==key){ return true;}
  else if(arr[l]<=arr[mid]){
    if(arr[l]<key && key<arr[mid]){
      return findEle(l,mid-1,key,arr);
    }
    return findEle(mid+1,r,key,arr);
  }else if(arr[mid]<=arr[r]){
    if(arr[mid]<key && key<arr[r]){
      return findEle(mid+1,r,key,arr);
    }
  }
  return findEle(l,mid-1,key,arr);
}

int main()
{
  int key=102;
  int arr[]={9,20,100,102,5};
  std::cout << "key found is " << findEle(0,(sizeof(arr)/sizeof(arr[0])-1),key,arr)<<endl;
}

