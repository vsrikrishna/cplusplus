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

 
bool descending_order(pair<string, int> i, pair<string, int> j)
{
    return j.second < i.second;
}
void sort(std::vector<pair<string,int> >::iterator itbeg, std::vector<pair<string,int> >::iterator itend, int size){    
   std::vector<pair<string,int> >::iterator max_element_iter;
   std::vector<pair<string,int> >::iterator itr1;
   std::vector<pair<string,int> >::iterator itr2;

   for( itr1 = itbeg ; itr1 != itend ; itr1++){
      max_element_iter = itr1;
	  for(itr2 = itr1 ; itr2 != itend ; itr2++){
             if(itr2->second > itr1->second){
                max_element_iter = itr2;
             }
      }
      itr1->swap(*max_element_iter);
   }
   
   for(itr1 = itbeg ; itr1 != itend ; itr1++){
      max_element_iter = itr1;
	  for(itr2 = itr1 ; itr2 != itend ; itr2++){
         if(itr2->second == itr1->second){
		    if(itr1->first.compare(itr2->first) > 0){
               itr1->swap(*itr2);
            }
         }
	  }
   }
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

   //sort(termsVec.begin(), termsVec.end(), termsVec.size());
   stable_sort(termsVec.begin(), termsVec.end(), descending_order);
   //cout << "Vector after sort contains:"<<endl;
   int count =0;
   for (vecIter=termsVec.begin(); vecIter!=termsVec.end(); ++vecIter){
      if(count < frequentTerms){
         cout << vecIter->first << endl;
		 count++;
	  }
   }
   return 0;
}