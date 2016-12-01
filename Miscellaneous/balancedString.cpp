/*
Given a string with only parenthesis. Check if the string is balanced. 
ex - 
1) "<({()})[]> is balanced 
2) "<({([)})[]> is not balanced

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkBalanced(string str){
  unordered_map<char,int> hash;
  hash.insert(make_pair('{',0));
  hash.insert(make_pair('[',0));
  hash.insert(make_pair('(',0));
  for(int i=0; i<str.size();i++){
    if(str[i] == '(' ||
       str[i] == '{' ||
       str[i] == '['){
      hash[str[i]]++;
    }
    else if(str[i] == ')'){
      hash['(']--;
    }
    else if(str[i] == '}'){
      hash['{']--;
    }
    else if(str[i] == ']'){
      hash['[']--;
    }
  }
  cout<<"The map values are"<<endl;
  for(auto a:hash){
    cout<<a.first<<"->"<<a.second<<endl;
  }
  if(hash['{']==0 && hash['(']==0 && hash['[']==0){
      return true;
  }
  return false;
}

int main()
{
  string str;
  cout<<"Enter the string"<<endl;
  getline(cin,str);
  cout<<"The string is balanced:"<<checkBalanced(str);  
  return 0;
}

