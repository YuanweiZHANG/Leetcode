## 20. [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

> Easy

Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

**Example 1:**

```
Input: "()"
Output: true
```

**Example 2:**

```
Input: "()[]{}"
Output: true
```

**Example 3:**

```
Input: "(]"
Output: false
```

**Example 4:**

```
Input: "([)]"
Output: false
```

**Example 5:**

```
Input: "{[]}"
Output: true
```



**Solutions:**

Use stack to solve this problem. When we have `'('`. `'{'`, `'['`, push them into the stack. When we have `')'`. `'}'`, `']'`, if `stack.top()` matches them, pop the stack, otherwise push them into the stack.

After we travel all elements of the string, if the stack is empty, then the input is valid, or it's not.

**Be careful to use `stack.top()` when stack is empty.**

Here is my solution class:

```c++
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
```

