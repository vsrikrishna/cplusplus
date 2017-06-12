/*
Amazon Problem
 Given an array input of N number of strings. [ cat, tac, pot, top, meow, act ]
 Return the output : [[act,cat,act], [pot,top], [meow]]
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const double pi = 3.141592653589793;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }


int main()
{
  vector<string> in = {"cat","tac","act","top","pot","meow","abu"};
  unordered_map<string,vector<string> > hashMap;
  //int size = in.size();
  for(int i=0;i<in.size();i++){
    string tmp=in[i];
    transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
    string sortStr = tmp;
    sort(sortStr.begin(),sortStr.end());
    if(hashMap.find(sortStr) != hashMap.end()){
      hashMap[sortStr].push_back(tmp);
    }else{
      vector<string> strVec;
      strVec.push_back(tmp);
      hashMap.insert(make_pair(sortStr,strVec));
    }
  }
  for(const auto& a:hashMap){
    //cout<<a.first<<" -> "<<a.second<<endl;
    for(auto b:a.second){
      cout<<b<<" ";
    }cout<<endl;
  }
  
  return 0;
}

