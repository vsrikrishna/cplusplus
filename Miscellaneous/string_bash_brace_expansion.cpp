/*
Bash Brace Expansion
Copied and refined it from career cup
Basically 2 vector strings are used alternatively to store the words 
Recursion is obviously used here.
Hint: Look at res and parsed strings and track their progress
08/14/2015
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<std::string>
parse_bash(const std::string& s, int& p) {
	std::vector<std::string> parsed;
	std::vector<std::string> res;
	res.push_back("");

	while (p < s.length()) {
		if (s[p] == '(') {
			p++;
			std::vector<std::string> substrings = parse_bash(s, p);
			std::vector<std::string> newres;
			for (std::string ss : substrings) {
				for (std::string r : res) {
					newres.push_back(r + ss);
				}
			}

			res = newres;
		}
		else if (s[p] == ',') {
			parsed.insert(parsed.end(), res.begin(), res.end());
			res.clear();
			res.push_back("");
			p++;
		}
		else if (s[p] == ')') {
			p++;
			parsed.insert(parsed.end(), res.begin(), res.end());
			return parsed;
		}
		else {
			for (int i = 0; i < res.size(); ++i) {
				res[i] += s[p];
			}

			p++;
		}
	}

	return res;
}

int main() {
    int p = 0;
	string str;
	cout << "Enter the string" << endl;
	cin >> str;
	std::vector<std::string> res = parse_bash(str, p);
	for (std::string s : res) {
		std::cout << s << std::endl;
	}
	cin.ignore();
	getchar();
	return 0;
}