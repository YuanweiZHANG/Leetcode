#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-05-10
* Veronica
*/
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty())
			return 0;
		stack<int> stk;
		int num1 = 0, num2 = 0;
		for (auto s : tokens) {
			if (s == "+" || s=="-"||s=="*"||s=="/") {
				num2 = stk.top();
				stk.pop();
				num1 = stk.top();
				stk.pop();
				if (s == "+")
					stk.push(num1 + num2);
				else if (s == "-")
					stk.push(num1 - num2);
				else if (s == "*")
					stk.push(num1 * num2);
				else
					stk.push(num1 / num2);
			}
			else {
				stk.push(atoi(s.c_str()));
			}
		}
		return stk.top();
	}
};

int main() {
	Solution solution;

	vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	cout << solution.evalRPN(tokens) << endl;

	return 0;
}