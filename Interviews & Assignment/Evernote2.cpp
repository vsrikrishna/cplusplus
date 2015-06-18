/*
Evernote 2 Challenge problem
Frequency Counting of Words / Top N words in a document.
Given N terms, your task is to find the k most frequent terms from given N terms.

Input format
First line of input contains N, denoting the number of terms to add.
In each of the next N lines, each contains a term.
Next line contains k, most frequent terms.

Output format
Print the k most frequent terms in descending order of their frequency. If two terms have same frequency print them in lexicographical order.

Sample input
14
Fee
Fi
Fo
Fum
Fee
Fo
Fee
Fee
Fo
Fi
Fi
Fo
Fum
Fee
3

Sample output
Fee
Fo
Fi

Constraint
0 < N < 300000
0 < term length < 25.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

 
bool descendingOrder(pair<string, int> elem1, pair<string, int> elem2)
{
    return elem1.second > elem2.second;
}
int main(){
   int N, frequentTerms;
   string str;
   std::map<string, int> frequentMap;
   std::map<string, int>::iterator iter;
   std::vector<pair<string, int> >::iterator vecIter;

   cin >> N;
   for(int i=0;i<N;i++){
      cin>>str;
      iter = frequentMap.find(str);
	  if(iter == frequentMap.end()){
          frequentMap.insert(std::pair<string,int>(str,1));
	  }
	  else{
		  iter = frequentMap.find(str);
		  iter->second++;
	  }
   }

   cin >> frequentTerms;
   vector<pair<string, int> > termsVec(frequentMap.begin(), frequentMap.end());

   stable_sort(termsVec.begin(), termsVec.end(), descendingOrder);

   int count =0;
   for (vecIter=termsVec.begin(); vecIter!=termsVec.end(); ++vecIter){
      if(count < frequentTerms){
         cout << vecIter->first << endl;
		 count++;
	  }
   }
   return 0;
}