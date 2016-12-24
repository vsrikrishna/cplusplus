/* Compacting the score problem:
  Given a set of scores in a tree format, imagine the root of tree as ceo and each level as employee of the parent(manager) node. 
  The employee score cannot be greater than the manager node. The input is given in the form of score and rank. 
  Where score is score for that level and rank is the node which is parent of current node. 
  Print the sum of scores at each level
  
  Input:
  10
  10000 -1
  203 4
  1000 0
  202 4
  200 7
  1001 2
  50 7
  20 0
  10 7
  30 7
  
  Output: 12130
  
  Input:
  4
  5 -1
  4 2
  3 3
  6 0
  
  Output: 16
*/
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
  ll n,scoreInt,rankInt;
  vector<ll> score;
  vector<ll> rank;
  queue<ll> qou;
  
  cin>>n;
  while(n){
    cin>>scoreInt>>rankInt;
    score.push_back(scoreInt);
    rank.push_back(rankInt);
    n--;
  }
  qou.push(0);
  while(!qou.empty()){
    ll tmp = qou.front();
    qou.pop();

    for(auto a=rank.begin();a != rank.end();a++){
      if(*a==tmp){
        ll index=a-rank.begin();
        score[index] = min(score[tmp],score[index]);
        cout<<"index is:"<<index<<",score is:"<<score[index]<<endl;
        qou.push(index);
      }
    }
  }
  cout<<"updated scores are:"<<endl;
  for(auto a:score){
    cout<<a<<endl;
  }
  return 0;
}

