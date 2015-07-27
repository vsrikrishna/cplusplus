/**
BigInteger implementation
This question was raised in Amazon Web Service(AWS) interview
Did not get the correct answer  :(
July 31 2013 - Finished on Aug 12 2013
Got help from cplusplus.com

Steps/Tricks to remember this algorithm:
1) string input is initialized to zero only in consturctor 
2) inserter algorithm, which is part of iterator library is used here
3) transform algorithm from algorithm library is used for parsing string into digits stored in vector
4) Ascii2int function used for converting character number to int
4a) Note the function does not take any input parameter, it is passed by the function directly
5) I have to consider where the result will be stored and normalize that data. 
5a) digits.size should be resized to max size to hold the result
6) operator<< overloading should be a friend function
6a) Error if it is not a friend function because it is printing out private variable
7) operator overloading in most cases returns references. Reason it avoids making a copy of the results 
8) operator + returns object because a new object would be copied to lhs in the syntax
9) vector.swap does swap on all the digits at once
10) Note: If constant object is used for iterator, then the iterator should be const_iterator. This is used in operator<< overloading below
*/

#include "conio.h"
#include "iostream"
#include "algorithm"
#include "vector"
#include "iterator" //std::back_inserter
using namespace std;

class BigInt{
   vector<int> digits;
public:
   BigInt(const BigInt& a);
   BigInt(string num="0");
   BigInt operator+(const BigInt& a);
   BigInt& operator+=(const BigInt& a);
   BigInt& operator=(BigInt& a);
   friend std::ostream& operator<<(std::ostream& out,const BigInt& a);
};

int Ascii2Int(int c){ return c - '0'; };

BigInt::BigInt(const BigInt& other):digits(other.digits){}

BigInt& BigInt::operator=(BigInt& a){
	digits.swap(a.digits);
    return *this;
}

BigInt::BigInt(string num){
   transform(num.rbegin(), num.rend(), inserter(digits,digits.begin()),Ascii2Int);
}
BigInt& BigInt::operator +=(const BigInt& a)
{
   unsigned int maxSize;
   unsigned int num = 0;
   unsigned int carry = 0;
 
   //size for output variable
   if(digits.size()<a.digits.size()){
	   maxSize = a.digits.size();
	   digits.resize(a.digits.size());
   }
   else{
	   maxSize = digits.size();
   }

   for (unsigned int i = 0; i <maxSize; i++)
   {
	   if(i<a.digits.size())
          num=digits[i]+a.digits[i]+carry;
	   else 
          num=digits[i]+carry;

      if(num >= 10)
      {
          num = num - 10;
          carry = 1;
      }
      else{
         carry = 0;
      }
      
	  digits[i] = num;
   }
   if (carry){
	   digits.push_back(1);
   }
   
   return *this;
}

BigInt BigInt::operator +(const BigInt& a) 
{
     return BigInt(*this) += a;
	 
}

std::ostream& operator <<(std::ostream& out,const BigInt& a)
{
	for (vector<int>::const_reverse_iterator it = a.digits.rbegin(); it != a.digits.rend(); it++){
      out << *it;
   }
   return out;
}

int main(){
   BigInt B1("981654321");
   BigInt B2("98431");
   BigInt B3;
   B3 = B1+B2;
   cout << "B1+B2 is" << B3 << endl;
   BigInt B4;
   B4+=B1;
   B4+=B2;
   B4+=B3;
   cout << "B4 is"<< B4 << endl;
   cin.clear();
   getchar();
   return 0;
}