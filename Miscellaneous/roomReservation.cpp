/*
Write a function which returns true or false. The input to function is number of rooms and the interval of stay of customers in the hotel. If 
the number of rooms is not sufficient for the intervals then we return a false, else we return a true
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Interval{
  int begin;
  int end;
};

bool comp(Interval I1, Interval I2){
  return I1.begin<I2.begin;
}

bool mergeIntervals(vector<Interval>& I, int rooms){
  queue<Interval> q;
  for(auto a:I){
    if(q.empty()){
      q.push(a);
    }else{
      if(a.begin < q.back().end){
        //insert into queue
        if(q.size()==rooms){
          return false; //already reached max
        }
        q.push(a);
      }else{
        q.pop();
        q.push(a);
      }
    }
  }
  return true;
}

int main()
{
  int num,n;
  vector<Interval> arr={{2,5},{1,3},{5,6}};
  n = sizeof(arr)/sizeof(arr[0]);
  sort(arr.begin(),arr.end(),comp);
  /*cout<<"The array elements are"<<endl;
  for(int i=0; i<n;i++){
    cout<<arr[i].begin<<" "<<arr[i].end<<endl;
  }*/
  cout<<"Enter number of rooms"<<endl;
  cin >>num;
  cout<<"The result is:"<<mergeIntervals(arr,num)<<endl;
  return 0;
}

