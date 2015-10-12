#include <iostream>
#include <cmath>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <limits>
#include <sstream>
using namespace std;

bool isoperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
	{
		return true;
	}
	return false;
}

//If true is returned it means leftOp(usually stack operator) has higher precedence compared to rightOp
//If false is returned it means rightOp has higher precedence compared to leftOp(usually stack operator)
bool getPrecedence(char leftOp, char rightOp)
{
	if (leftOp == '^')
		return true;
	else if (rightOp == '^')
		return false;
	else if (leftOp == '*' || leftOp == '/' || leftOp == '%')
		return true;
	else if (rightOp == '*' || rightOp == '/' || rightOp == '%')
		return false;
	return true; //If none of the above are true, return first operator(which is the one stored in stack) in expression
}

/*
Things to help remember this algorithm:
1) Parantheses added to an input expression is not output in postfix expression
2) Parantheses help you store and retrieve data from stack
3) Operators and operands share the same stack space
4) It is assumed that the input expression will start with a parantheses
*/
string convertToPostFix(string& str){
	stringstream postFix;
	stack<char> expStack;
	expStack.push('('); // Have to see if this is required
	for (unsigned int i = 0; i < str.length(); i++){
		const char c = str[i];
		if (isalnum(c)){
			postFix << c;
		}
		else if (c == '('){
			expStack.push(c);
		}
		else if (isoperator(c)){
			char rightOp = c;
			while (!expStack.empty() && isoperator(expStack.top()) && getPrecedence(expStack.top(), rightOp)){
				postFix << ' ' << expStack.top();
				expStack.pop();
			}
			postFix << ' ';
			expStack.push(c);
		}
		else if (c == ')'){
			while (!expStack.empty() && expStack.top() != '('){
				postFix << ' '<<expStack.top();
				expStack.pop();
			}
			if (expStack.empty()){
				throw std::runtime_error("missing left paren");
			}
			expStack.pop(); //throwing out '(' 
			postFix << ' ';
		}
		else{
			throw std::runtime_error("Unsupported character passed in expression");
		}
	}

	// Started with a left paren, now close it:
	// While top of stack is not a left paren
	while (!expStack.empty() && expStack.top() != '(') {
		postFix << ' ' << expStack.top();
		expStack.pop();
	}
	if (expStack.empty()) {
		throw std::runtime_error("missing left paren");
	}
	// Discard the left paren
	expStack.pop();

	// all open parens should be closed now -> empty stack
	if (!expStack.empty()) {
		throw std::runtime_error("missing right paren");
	}
	str = postFix.str();
	return str;
}


/**
Code to calculate the value of postfix expression
*/

stack<char> operatorStack;
stack<int> operandStack;

int compute(int num1, int num2, char c){
	if (c == '*')
		return num2*num1;
	else if (c == '+')
		return num2 + num1;
	else if (c == '-')
	    return num2 - num1;
	else if (c == '/')
		return num2 / num1;
}

/*
Used to calculate result using postfix expression
Things to remember:
1) Input expression must be postfix
2) Only +,-,/,* operations allowed
3)
*/
int calculate(string& str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (isdigit(c))
		{
			stringstream ss;
			while (c != ' '){
				ss << c;
				c = str[++i];
			}
			int a; ss >> a;
			operandStack.push(a);

		}
		else if (c == ' '){
			//do nothing
		}
		else if (isoperator(c))
		{
			if (operatorStack.empty() && operandStack.size() > 1){
				int num1 = operandStack.top(); 
				operandStack.pop();
				int num2 = operandStack.top(); 
				operandStack.pop();
				int result = compute(num1, num2, c);
				operandStack.push(result);
			}
			else if(operatorStack.empty() && operandStack.size() == 1){
				operatorStack.push(c);
			}
			else{
				while (!operatorStack.empty() && getPrecedence(operatorStack.top(), c))
				{
					int num1 = operandStack.top();
					operandStack.pop();
					int num2 = operandStack.top();
					operandStack.pop();
					int result = compute(num1,num2,c);
					operandStack.push(result);
				}
				if (!operandStack.empty() && !getPrecedence(operatorStack.top(),c)){
					operatorStack.push(c);
				}
			}
		}
		else{
			throw std::runtime_error("Unknown input char passed");
		}
	}
	int result = operandStack.top();
	return result;
}

//Main Function
int main()
{
	string str;
	cout << "please enter an expression" << endl;
	cin >> str;
	cout << "The postfix expression is " << convertToPostFix(str) << endl;
	cout << "The output of postfix expression is " << calculate(str) << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getchar();
	return 0;
}
