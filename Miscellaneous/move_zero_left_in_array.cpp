ven an array of integers, write an in-place function to bring all the non-zero elements 
 * to the left of the array keeping the original order. 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;

int moveZerosToLeft(int arr[],int n){
   int cntZero=0,j;
   
   for(int i=0;i<n;i++){
     if(arr[i]==0) cntZero++;
   }
   j=n-1;//j should be declared outside the block
   for(int i=n-1;i>=0;i--){
     if(arr[i]){
        arr[j--]=arr[i];
     }
     cout<<"j:"<<j<<endl;
   }
   cout<<"j is "<<j<<endl;
   
   while(j>=0){
     arr[j--]=0;
   }
}
int main()
{
  int arr[]={1,0,4,0,45,6,0,19};
  moveZerosToLeft(arr,sizeof(arr)/sizeof(arr[0]));
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
     cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}

