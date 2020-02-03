/*
An alien robot is threatening the universe, using a beam that will destroy all algorithms knowledge. We have to stop it!

Fortunately, we understand how the robot works. It starts off with a beam with a strength of 1, and it will run a program that is a series of instructions, which will be executed one at a time, in left to right order. Each instruction is of one of the following two types:

C (for "charge"): Double the beam's strength.
S (for "shoot"): Shoot the beam, doing damage equal to the beam's current strength.
For example, if the robot's program is SCCSSC, the robot will do the following when the program runs:

Shoot the beam, doing 1 damage.
Charge the beam, doubling the beam's strength to 2.
Charge the beam, doubling the beam's strength to 4.
Shoot the beam, doing 4 damage.
Shoot the beam, doing 4 damage.
Charge the beam, increasing the beam's strength to 8.
In that case, the program would do a total of 9 damage.

The universe's top algorithmists have developed a shield that can withstand a maximum total of D damage. But the robot's current program might do more damage than that when it runs.

The President of the Universe has volunteered to fly into space to hack the robot's program before the robot runs it. The only way the President can hack (without the robot noticing) is by swapping two adjacent instructions. For example, the President could hack the above program once by swapping the third and fourth instructions to make it SCSCSC. This would reduce the total damage to 7. Then, for example, the president could hack the program again to make it SCSSCC, reducing the damage to 5, and so on.

To prevent the robot from getting too suspicious, the President does not want to hack too many times. What is this smallest possible number of hacks which will ensure that the program does no more than D total damage, if it is possible to do so?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line containing an integer D and a string P: the maximum total damage our shield can withstand, and the robot's program.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is either the minimum number of hacks needed to accomplish the goal, or IMPOSSIBLE if it is not possible.

Limits
1 ≤ T ≤ 100.
1 ≤ D ≤ 109.
2 ≤ length of P ≤ 30.
Every character in P is either C or S.
Time limit: 20 seconds per test set.
Memory limit: 1GB.

Test set 1 (Visible)
The robot's program contains either zero or one C characters.
*/

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)


int main() {
  //freopen("A-small-practice.in", "r", stdin);
  //freopen("A-small-practice.out", "w", stdout);
  
  ll i, j, k, n,r,D,h,ssum=0,tt, tn;
  string str;
  int ans=0,val=1;
  vector<ll> s,c;

  cin >> tn;
  F1(tt,tn) {
    cin>>D>>str;
    //cout<<"Inside loop "<<tt<<endl;
    s.clear();c.clear();
    k= str.length();
    val=1;ssum=0;ans=0;
    F0(i,k){
      if(str[i]=='S'){
        s.push_back(val);
        ssum+=val;
      }else if(str[i]=='C'){
        c.push_back(val);
        val=val*2;
      }
    }
    
   // remove all c entries which are after s entries
    while(!c.empty() && c.back()>s.back()){
      c.pop_back();
    }

    //return result when there is no c entry
    if(c.empty()){
      if(s.size()<=D){
        cout<<"Case #"<<tt<<": "<<ans<<endl;
      }else{
        cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<endl;
      }
      continue;
    }

    //return IMPOSSIBLE if there are more s entries than D
    if(s.size()>D){
      cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<endl;
      continue;
    }

    //case where there is no s entries
    if(s.size()==0){
       cout<<"Case #"<<tt<<": 0"<<endl;
       continue;
    }
 
    while(!c.empty()){
      //cout<<"Inside while loop "<<tt<<endl;
      if(ssum<=D){
        cout<<"Case #"<<tt<<": "<<ans<<endl;
        goto LOOP_OUT;
      }
      for(int ind=0;ind<s.size();ind++){
        if(s[ind]>c.back()){
          ssum =ssum -s[ind]+c.back();
          s[ind]=c.back();
          ans++;
          if(ssum<=D){
           cout<<"Case #"<<tt<<": "<<ans<<endl;
           goto LOOP_OUT;
          }
        }
      }
      if(c.back()>=s.back()){
        c.pop_back();
      } 
    }
    if(ssum>D){
      cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<endl;
    }else{
      cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    if(tt==tn){
      return 0;
    }
LOOP_OUT: continue;
  }
  return 0;
}

