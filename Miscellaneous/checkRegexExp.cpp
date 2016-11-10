 basic Regex engine implementing the "." (any character) and "*" (previous rule, 0 to many). 
* The function receives a string (letters only, no need for escaping) and a string pattern. 
* It returns a bool whether the string matches the pattern. For example, the pattern "AB.*E" should match both "ABCDE" and "ABEEE".   
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;

bool checkRegex(string pattern,string str){
  int si=0;
  for(int i=0;i<pattern.length();i++){
    if(pattern[i] != '.' && pattern[i] != '*' && pattern[i] != str[si]){
      return false;
    }else if(pattern[i] == '.' && pattern[i+1] == '*'){
      int pat_rem = pattern.length()-1-(i+1); //remaining length in pattern
      int str_rem = str.length()-1-i; //remaining length in string
      if(str_rem >pat_rem){
        si+=(str_rem-pat_rem)+1; //skip over one extra character for '.' substitution
      }else if(str_rem<pat_rem){
        //do nothing, since there is no pattern match to be done
      }
      else{
        si++;
      }
      cout<<"pat_rem:"<<pat_rem<<",str_rem:"<<str_rem<<",si:"<<si<<endl;
      i++;
    }else{
      si++; 
    }
  }
  return true;
}
int main()
{
  string str,pattern;    
  cout<<"Enter the regex pattern"<<endl;
  cin>>pattern;
  cout<<"Enter the string to be checked"<<endl;
  cin>>str;
  if(checkRegex(pattern,str)){
    cout<<"String "<<str<<" matches pattern "<<pattern<<endl;
  }else{
    cout<<"Pattern does not match the string"<<str<<endl;                                                                                                     
  }
  return 0;
}

