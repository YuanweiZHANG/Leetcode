## 22. [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

> Medium

Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given *n* = 3, a solution set is:

```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```



**Solutions:**

I think LeetCode isn't as strict as POJ, so this time I use recursion instead of stack. It's a complete enumeration problem. Add `'()'` and if the number of `'()'` is bigger than the number of `')'`, add `')'`. When both of them reach the `n`, signal the `curr` string.

Here is my solution class:

```c++
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> results;
		string curr;
		generateParenthesisCore(results, 0, 0, n, curr);
		return results;
	}
	void generateParenthesisCore(vector<string> &results, int left, int right, int n, string & curr) {
		if (left == n && right == n) {
			results.push_back(curr);
			return;
		}
		if (left < n) {
			curr.push_back('(');
			generateParenthesisCore(results, left + 1, right, n, curr);
			curr.pop_back();
		}
		if (left > right) {
			curr.push_back(')');
			generateParenthesisCore(results, left, right + 1, n, curr);
			curr.pop_back();
		}
		return;

	}
};
```

