/**
Power Set 1:
If the input string is (abcd). Print all possible combinations using this
i.e - a,b,c,d,ab,ac,ad,bc,bd,abc,acd,bcd,abcd
11/08/2015
*/

#include <iostream> // for cout
#include <string>
using namespace std;


void recurse(string s, string o, int start)
{
	cout << "start is " << start << endl;
	for (int i = start; i < s.length(); i++)
	{
		cout << "start inside is " << start << endl;
		cout << "o is " << o << endl;
		cout << "i is " << i << endl;
		o = o + s[i];
		cout << o <<endl;		
		recurse(s, o, i + 1);
		o = o.erase(o.length() - 1);
	}
}


// now our main function:
int main()
{
	string s = "abcd";
	string o = "";
	recurse(s,o,0);
	cin.clear();
	getchar();
}