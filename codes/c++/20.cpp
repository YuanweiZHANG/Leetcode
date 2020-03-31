#include <iostream>
#include <string>
#include <stack>
using namespace std;

/**
 * 2020-03-30
 * Veronica
 */
class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		int len = s.size();
		bool valid = false;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				stk.push(s[i]);
			else if (s[i] == ')') {
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else
					stk.push(s[i]);
			}
			else if (s[i] == '}') {
				if (!stk.empty() && stk.top() == '{')
					stk.pop();
				else
					stk.push(s[i]);
			}
			else if (s[i] == ']') {
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else
					stk.push(s[i]);
			}
			else
				stk.push(s[i]);
		}
		if (stk.empty())
			return true;
		else
			return false;
	}
};

int main() {
	Solution solution;

	string s = "]";
	cout << solution.isValid(s);

	return 0;
}
