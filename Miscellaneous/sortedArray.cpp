// Example program
#include <iostream>
#include <string>
using namespace std;

bool findInt(int arr[],int key, int size){
  cout<<"Inside findInt"<<endl;
  int start,end,mid;
  start=0;
  end=size-1;
  mid = start+(end-start)/2;

  while(start<=end){
    cout<<"start:"<<start<<",mid:"<<mid<<",end:"<<end<<endl;
    mid = start+(end-start)/2;
    if(arr[mid]==key) return true;
    if(arr[start]<=arr[mid]){
      if(key>=arr[start] && key<=arr[mid]){
        end=mid-1;    
      }else{
        start=mid+1;
      }
    }
    else{
      if(key>=arr[mid] && key<=arr[end]){
        start = mid+1;
      }else{
        end =mid-1;
      }
    }
  }
  return false;
}

int main()
{
  int n;
  int arr[]={4,5,1,1,3};
  cout<<"Enter the element to search"<<endl;
  cin >>n;
  cout<<"The element was found:"<<findInt(arr,n,sizeof(arr)/sizeof(arr[0]))<<endl;
  r
