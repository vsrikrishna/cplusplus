// Example program 1 09/01/2019
//Printing stair case function
/*
+
++
+++
++++
+++++
*/

#include <iostream>
#include <string>
using namespace std;

void printStairs(int num){
 for (int i=1; i<=num; i++){
   for(int j=1;j<=i;j++){
     cout<<"+";
   }
   cout<<endl;
 }
 for (int i=num; i>0; i--){
   for(int j=1;j<=i;j++){
     cout<<"+";
   }
   cout<<endl;
 }
}
int main()
{
  int num1;    
  cout<<"Enter the height of staircase"<<endl;
  cin>>num1;
  printStairs(num1);
}

