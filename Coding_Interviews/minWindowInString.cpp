// Example program
/*Given a string, find the substring with minimum length from it which contains exactly equal no of characters given in a hashmap
which contains key as character and values as count of character needed in substring. 

For example: 
String str ="abcrefbda"; 
map = {{"b"=1},{"d"=1"},{"a"=1}}; 

Output = "bda";
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

int main()
{
  string str="abcrefbda",ans="hi";
  int cnt=0,minCnt=INT_MAX,start=-1,end=0,size=0;
  
  unordered_map<char,int> needsToFind={{'b',1},{'d',1},{'a',1}}; 
  unordered_map<char,int> hasFound={{'b',0},{'d',0},{'a',0}};
  
  for(auto a:needsToFind){
    size+=a.second;
  }
  
  for(int i=0; i<str.length();i++){
    char c=str[i]; 
    
    if(needsToFind.find(c) != needsToFind.end()){
      if(start==-1){
          start=i;
          end=i;
      }
      else{
        end=i;
      }
      cnt++;
      hasFound[c]++;
    }
    
    char s=str[start];
    //cout<<"c:"<<c<<",s:"<<s<<",start:"<<start<<endl;
    while((hasFound[s]>needsToFind[s]) && start<end){
      start++;
      hasFound[s]--;
      cnt--;
      s=str[start];
      while(needsToFind.find(s)==needsToFind.end() && start<end){
        start++;
        s=str[start];
      }
    }
    cout<<"start:"<<start<<", end:"<<end<<",cnt:"<<cnt<<endl;
    if(cnt==size){
      int charCnt = (end-start)+1;    
      if(charCnt<minCnt){
        minCnt=charCnt;  
        cout<<"charCnt:"<<charCnt<<endl;
        ans=str.substr(start,charCnt);
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}

