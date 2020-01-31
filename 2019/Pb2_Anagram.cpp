/*
Check if 2 strings are anagram without using anagram
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int checkAnagram(string str1, string str2){
  if (str1.length() != str2.length()){
    cout <<"Not an anagram" << endl;
    return 0;
  }
  else{
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    for (int i=0; i<str1.length();i++){
      if(str1[i] != str2[i]){
        cout<<"Not an anagram" <<endl;
        return 0;
        break;
      }
    }
    cout <<"The strings are an anagram"<<endl;
    return 1;
  }
}

int checkAnagram2(string str1, string str2){
   if (str1.length() != str2.length()){
    cout <<"Length different: Not an anagram" << endl;
    return 0;
  }    
  unordered_map<char, int> CharCount;
  for(int i=0; i<str1.length();i++){
    char ch = str1[i];  
    if(CharCount.find(ch) == CharCount.end()){
      CharCount[ch]= 1;
    }else{
      int val = CharCount[ch];
      CharCount[ch]=val+1;
    }
  }
  for(int i=0;i<str2.length();i++){
    char ch = str2[i];
    if(CharCount.find(ch) == CharCount.end()){
      cout <<"Not an anagram, Ch is " <<ch << endl;
      return 0;
    }else{
      int val = CharCount[ch];
      if(val==1){
        CharCount.erase(ch);
      }else{
        val--;  
        CharCount[ch]=val;
      }
    }
  }
  
  if(CharCount.empty()){
    cout << "Strings are an anagram" <<endl;
  }else{
    cout << "Strings are not an anagram" << endl;
  }
  
  for (auto& x: CharCount) {
    std::cout << x.first << "-> " << x.second << std::endl;
  }

}


int main()
{
  string str1, str2;
  cout<<"Enter string1 and string 2"<<endl;
  cin>>str1>>str2;
  cout <<"String 1 is " << str1 <<endl;
  cout <<"String 2 is " << str2 <<endl;
  checkAnagram2(str1, str2);
}

