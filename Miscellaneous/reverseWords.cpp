/*
* Reverse words in a string
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  std::string str;
  std::cout << "Enter the string"<<endl;
  getline (std::cin, str);
  cout<<"str is: "<<str<<endl;
  reverse(str.begin(),str.end());
  
  size_t pos=str.find(" ");
  size_t start,pos2;
  start=pos2=0;
  while(pos){
    //cout<<"Inside while loop"<<endl;  
    reverse(str.begin()+start,str.begin()+pos);
    start=pos+1;
    size_t pos2 = str.find(" ",pos+1);
    if(pos==str.size()) break;
    if(pos2 != string::npos){
      pos=pos2;
    }else{
      pos=str.size();
    }
    //cout<<"start:"<<start<<",pos:"<<pos<<",pos2:"<<pos2<<endl;
  }
  cout<<"str reversed:"<<str<<endl;
}

