## 150. [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

> Medium

Evaluate the value of an arithmetic expression in [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, `/`. Each operand may be an integer or another expression.

**Note:**

- Division between two integers should truncate toward zero.
- The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

**Example 1:**

```
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**Example 2:**

```
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

**Example 3:**

```
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```



**Solutions:**

Use `stack` to store all the numbers in Reverse Polish Notation. Be careful the order of `num1` and `num2`.

Here is my solution class:

```c++
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
```

