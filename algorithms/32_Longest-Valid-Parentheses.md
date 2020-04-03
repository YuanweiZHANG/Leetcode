## 32. [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)

> Hard

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

```
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
```

**Example 2:**

```
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
```



**Solutions:**

Stack is a perfect structure to solve valid parentheses. I use `stack<int>` to store indexes of `s`'s elements. For example, when input `)()())`, after push and pop, stack remains `0, 5`, which are exactly the unmatched parentheses' indexes. Then the longest substring is between those remaining indexes. 

Here is my solution class:

```c++
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
```

