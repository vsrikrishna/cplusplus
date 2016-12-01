/*
Write a function which takes in an array of integers and find maximum product of 3 integers 
in an array. No sorting. 
*/
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int maxProduct(int arr[],int size){
  int maxa,maxb,maxc,mina,minb;
  maxa=maxb=maxc=INT_MIN;
  mina=minb=INT_MAX;
  for(int i=0;i<size;i++){
    if(arr[i]>maxa){
      maxc=maxb;
      maxb=maxa;
      maxa=arr[i];
    }
    if(arr[i]<mina){
      mina=minb;
      minb=arr[i];
    }
  }
  cout <<"maxa:"<<maxa<<",maxb:"<<maxb<<",maxc:"<<maxc<<",mina:"<<mina<<",minb:"<<minb<<endl;
  return max(maxa*maxb*maxc, maxa*mina*minb);
}

int main()
{
int arr[]={0,1,3,100,-70,-5};
cout<<"Max product is "<<maxProduct(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
return 0;
}
