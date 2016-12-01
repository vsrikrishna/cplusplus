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

unordered_map<unsigned int,bool> cache;



bool play(int target, unsigned int used, int size){
        cout<<"inside play, used:"<<used<<",target:"<<target<<endl;
        if(cache.find(used) != cache.end()) return cache[used];
        //exist available integer >= target, return true
        if(target-1<size && (used > (1<<target-1))){
            cache[used] = true;
            return true;
        }
        int bit = 1;
        for(int i = 0; i<size; i++,bit <<=1){
            if((used & bit)== 0) continue; // the (i+1)th bit is '0', means (i+1) is used
            used ^= bit;
            if(!play(target-i-1,used,size)){
                used |= bit;
                cache[used] = true;
                return true;
            }
            used |= bit;
        }
        cache[used] =  false;
        return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger>=desiredTotal) return true;
        //the sum of all available numbers are less than desireTotal, which means it cannot reach the desireTotal
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        unsigned int used = (1<<maxChoosableInteger)-1; // use bit to record which number has been used (bit '1' means available, bit '0' means used)
        return play(desiredTotal,used,maxChoosableInteger);
}
int main()
{
  int max=10,target=12;
  cout<<"player one can win is:"<<canIWin(max,target);  
  return 0;
}

