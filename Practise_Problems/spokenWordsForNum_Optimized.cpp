#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

void spokenWord(int num, string& in){
	stringstream ss;
	if (num / 1000000){
		cout << "Inside Million" << endl;
		spokenWord(num / 1000000, in);
		in+= "Million ";
		num %= 1000000;
	}
	if (num / 1000){
		spokenWord(num / 1000, in);
		in += "Thousand ";
		num %= 1000;
	}
	if (num / 100){
		spokenWord(num / 100, in);
		in += "Hundred ";
		num %= 100;
	}
	if(num>0){
		string units[20] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
		string tens[10] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninty " };
		if (num < 20){
		   in += units[num];
		}
		else{
			int a = num / 10;
			int b = num % 10;
			in += tens[a];
			in += units[b];
		}
	}
}

int main(){
	int num;
	string out = "";
	cout << "Enter the number" << endl;
	cin >> num;
	spokenWord(num, out);
	cout << "spokenWord is " << out << endl;
	cin.clear();
	cin.ignore();
	getchar();
	return 0;
}