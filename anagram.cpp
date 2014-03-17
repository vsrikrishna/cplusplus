#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isAnagram(const std::string str1, const std::string str2){
	std::string sortedstr1 = str1;
	std::string sortedstr2 = str2;
	std::sort(sortedstr1.begin(), sortedstr1.end());
	std::sort(sortedstr2.begin(), sortedstr2.end());
	if(sortedstr1.compare(sortedstr2) == 0)
		return true;
	else
		return false;
}
int main(){

   std::string str1, str2;
   cout << "Enter 2 strings to compare" << endl;
   cin >> str1 >> str2;
   cout <<isAnagram(str1, str2) << endl;
   return 0;
}