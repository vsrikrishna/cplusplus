/*
Fibonacci Series
@author Sri Krishna Vijayapuri 07182013
*/

#include "iostream"
using namespace std;

//recursive algorithm
long long int fib(long long int n){
   if(n<=1) return n;
   else{
	   return (fib(n-1)+fib(n-2));
   }
}
//dynamic programming
long long int fastFib(long long int n){
   long long int fib1, fib2, fib3;
   fib1 = 0;
   fib2 = 1;
   if(n<=1) 
      return n;
   else{
      for(int i=2; i<=n; i++){
         fib3 = fib1 + fib2;
		 fib1 = fib2;
		 fib2 = fib3;
      }
	  return fib3;
   }
}
void main(){
   long long int n, term;
   cout << "Enter the nth fibonacci term to search"<< endl;
   cin >> n;
   term = fastFib(n);
   cout << n <<"th fibonacci term is" << term << endl;
}