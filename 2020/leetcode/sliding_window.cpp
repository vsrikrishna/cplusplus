/* Sliding window problem

1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

class Solution {
  public:
    int numberOfSubstrings(string s) {
	int n = s.size(), i=0, ans = 0;
    string s2;
	unordered_map<char,int> um;
	for(int j=0; j<n; j++){
        cout<<"j:"<<j<<endl;
        s2+=s[j];
		um[s[j]]++;
        cout<<"s2:"<<s2<<endl;
		while(um['a'] && um['b'] && um['c']){
			um[s[i]]--;
			i++;
            string s3=s.substr(i,j-i+1);
            cout<<"i:"<<i<<", ans:"<<ans<<", s3:"<<s3<<endl;
		}
		ans += i;
        cout<<"ans out:"<<ans<<endl;
	}
	return ans;
}
};

