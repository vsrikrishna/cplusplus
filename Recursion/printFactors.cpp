/*
Write all the possible numbers which multiply to given number. 
Eg : 12 can be written as 12*1, 2*6,3*4,2*2*4. 
Dont include 6*2 again or 4*3 as its duplication of 2*6 and 3*4 resp.
*/
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

void printFactors(string prev, int num){
   if(num<2) return;  
   int target = ceil(sqrt(num));
   for(int i=2;i<=target;i++){
     if(num%i==0){
       int quo = num/i;
       if(quo>i){ //to avoid repetition
         stringstream ss;
         ss<<prev<<i<<"*";
         cout<<ss.str()<<quo<<endl;
         printFactors(ss.str(),quo);
       }
     }
   }  
}

int main(){
  int num;  
  cout<<"Enter the number to print the factors"<<endl;
  cin>>num;
  cout<<"1*"<<num<<endl;
  printFactors("",num);
  
  return 0;
}
