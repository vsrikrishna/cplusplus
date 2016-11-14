/*
* kth largest value in an array
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void swap(int &a, int &b){
  int temp;
  temp = a;
  a=b;
  b=temp;
}

int partition(int arr[],int low,int high,int index,int key,int n){
  cout<<"low:"<<low<<",high:"<<high<<",key:"<<key<<endl;
  if(low==key || high==key){
    return key;
  }
  while(low<=high){
    cout<<"arr[low]"<<arr[low]<<",arr[high]"<<arr[high]<<",arr[index]:"<<arr[index]<<endl;  
    cout<<"low:"<<low<<",high:"<<high<<",index:"<<index<<endl;
    while(arr[low]<arr[index]&&(low<=high)){
      low++;
    }
    while(arr[high]>arr[index]&&(low<=high)){
        high--;
    }
    cout<<"After while"<<endl;
    cout<<"arr[low]"<<arr[low]<<",arr[high]"<<arr[high]<<",arr[index]:"<<arr[index]<<endl;  
    cout<<"low:"<<low<<",high:"<<high<<",index:"<<index<<endl;    
    if(low<high){
      swap(arr[low++],arr[high--]);
    }
    cout<<"arr values are:"<<endl;
    for(int i=0; i<n;i++){
      cout<<arr[i];
    }
    cout<<endl;
  }
  swap(arr[high],arr[index]);
  return low; 
}
int main()
{
  int arr[]={5,3,9,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k, low,high,key=-1,index,count=0;
  cout<<"Enter value of k"<<endl;
  cin>>k;
  if(k>=n){
    cout<<"size of k should be within the array"<<endl;
    return 0;
  }
  k=n-k-1;
  index=0;
  low=1;
  high=n-1;
  partition(arr,low,high,index,-1,n);
  while(count<n){
    cout<<"arr values are:"<<endl;
    for(int i=0; i<n;i++){
      cout<<arr[i];
    }
    cout<<endl;
    key = partition(arr,low,high,index,k,n);
    if(key==k){
      break;
    }
    else if(key>k){
      high=key-1;
    }else if(key<k){
      low=key+1;
    }
    count++;
  }
  cout<<arr[key]<<endl;
  return 0;
}

