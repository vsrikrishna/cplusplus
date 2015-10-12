#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

string units[11] = { "","One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten " };
string teens[10] = { "","Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
string tens[10] = { "","", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninty " };

void getDivisorString(int divisor, string &in){
	switch (divisor){
	   case 1000: 
		  in += "Thousand ";
		  break;
	   case 100:
		   in += "Hundred ";
		   break;
	   default:
		   break;
	}
}
void getNumWord(int quotient, int divisor, string &in){
//5,15,25,35,99...
	cout << "quotient is " << quotient << endl;
    if (quotient <= 10){
	   cout << "quotient is less than 10" << endl;
       in += units[quotient];
    }
    else if (quotient > 10 && quotient < 20){
	  cout << "quotient is b/w 10 & 20" << endl;
	  in += teens[quotient % 10];
    }
    else{
	  cout << "quotient is >20" << endl;
	  int num2 = quotient;
	  int quotient2 = num2 / 10;
	  int remainder2 = num2 % 10;
	  in += tens[quotient2];
	  in += units[remainder2];
    }
	if (divisor > 10){
		getDivisorString(divisor, in);
	}
}

bool spokenWord(int num, string& in){
	if (num > 99999){
		cout << "Number too big to be handled"<<endl;
		return false;
	}
   int quotient = 0, divisor = 1000;
   bool tenFlag = false;
   while (num && !tenFlag){
	   if (divisor ==10 && num > 10){
	      quotient = num;
		  tenFlag = true;
	   }
	   else{
		   quotient = num/divisor;
	   }
	  cout << "quotient is " << quotient << " ,num is " << num << " ,divisor is " << divisor << endl;
      if(quotient){
		  getNumWord(quotient, divisor, in);
		  cout << "string is " << in << endl;
      }
	  num = num % divisor;
	  divisor = divisor / 10;
   }
   return true;
}

int main(){
	int num;
	string out = "";
	cout << "Enter the number" << endl;
	cin >> num;
	bool result = spokenWord(num, out);
	if (result)
		cout << "spokenWord is " << out << endl;
	else
		cout << "spokenWord not found" << endl;
	cin.clear();
	cin.ignore();
	getchar();
	return 0;
}