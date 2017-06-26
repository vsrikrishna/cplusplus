// C++ program to find length of the shortest chain
// transformation from source to target
//  word_ladder.cpp
//
//  Created by Sri Krishna Vijayapuri on 6/24/17.
//  Copyright © 2017 test. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const double pi = 3.141592653589793;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }


// A queue item to store word and minimum chain length
// to reach the word.
struct QItem
{
  string word;
  int len;
};

// Returns length of shortest chain to reach 'target' from 'start'
// using minimum number of adjacent moves.  D is dictionary
int shortestChainLen(string& start, string& target, set<string> &D)
{
  if(start==target) return 0;
  // Create a queue for BFS and insert 'start' as source vertex
  queue<QItem> Q;
  QItem item = {start, 0};  // Chain length for start word is 1
  Q.push(item);
  
  // While queue is not empty
  while (!Q.empty())
  {
    // Take the front word
    QItem curr = Q.front();
    Q.pop();
    
    string temp = curr.word;
    int cnt = curr.len;
    if(temp==target){
      return cnt;
    }
    for(int i=0;i<temp.length();i++){
      temp=curr.word;
      for(char a='a';a<='z';a++){
        temp[i]=a;
        if(D.find(temp) != D.end()){
          QItem item={temp,cnt+1};
          Q.push(item);
          D.erase(D.find(temp));
        }
      }
    }
  }
  return 0;
}

// Driver program
int main()
{
  // make dictionary
  set<string> D;
  D.insert("poon");
  //D.insert("plon");
  //D.insert("plen");
  D.insert("plee");
  D.insert("same");
  D.insert("poie");
  D.insert("plie");
  D.insert("poin");
  D.insert("plea");
  string start = "poon";
  string target = "plee";
  cout << "Length of shortest chain is: "<< shortestChainLen(start, target, D)<<endl;
  return 0;
}
