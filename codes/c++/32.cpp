#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/**
* 2020-04-02
* Veronica
*/
class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		if (len == 0)
			return 0;
		stack<int> stk; // use int instead of char
		int longest = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '(') stk.push(i);
			else {
				if (!stk.empty() && s[stk.top()] == '(')
					stk.pop();
				else
					stk.push(i);
			}
		}
		if (stk.empty())
			longest = len;
		else {
			int end = len, start = 0;
			while (!stk.empty()) {
				start = stk.top();
				stk.pop();
				longest = max(longest, end - start - 1);
				end = start;
			}
			longest = max(longest, start);
		}
		return longest;
	}
};

int main() {
	Solution solution;

	string s = "()(";
	cout << solution.longestValidParentheses(s);

	return 0;
}