##678. [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/) 

> Medium

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string.
5. An empty string is also valid.

**Example 1:**

```
Input: "()"
Output: True
```

**Example 2:**

```
Input: "(*)"
Output: True
```

**Example 3:**

```
Input: "(*))"
Output: True
```

**Note:**

1. The string size will be in the range [1, 100].



**Solutions:**

Dynamic planning.

Define `dp[i][j] == true` if and only if `s.substr(i, j - i + 1)` is validate parenthesis string. 

Initiate:

`dp[i][i + 1] == true` if and only if `s[i] == '*' || s[i + 1] == '*' || (s[i] == '(' && s[i + 1] == ')'`.

`k >= 2` and `dp[i][i + k] == true` if and only if `s[i] == '*' && dp[i + 1][i + k] == true` or `(s[i] == '(' || s[i] == '*')` and we can find `j` between `i + 1` and `i + k` so than `(s[j] == ')' || s[j] == '*') && dp[i + 1][j - 1] == true && dp[j + 1][i + k] == true`.

Here is my solution class:

```c++
class Solution {
public:
	bool checkValidString(string s) {
		if (s == "")
			return true;
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i) {
			if (s[i] == '*')
				dp[i][i] = true;
			if (i < n - 1 && (s[i] == '(' || s[i] == '*') && (s[i + 1] == ')' || s[i + 1] == '*'))
				dp[i][i + 1] = true;
		}
		for (int k = 2; k < n; ++k) {
			for (int i = 0; i < n - k; ++i) {
				if (s[i] == '*' && dp[i + 1][i + k])
					dp[i][i + k] = true;
				else if (s[i] == '(' || s[i] == '*') {
					for (int j = i + 1; j <= i + k; ++j) {
						if (s[j] == ')' || s[j] == '*') {
							if (j == i + 1) {
								if (dp[j + 1][i + k])
									dp[i][i + k] = true;
							}
							else if (j == i + k) {
								if (dp[i + 1][j - 1])
									dp[i][i + k] = true;
							}
							else {
								if (dp[i + 1][j - 1] && dp[j + 1][i + k])
									dp[i][i + k] = true;
							}
						}
					}
				}
			}
		}
		return dp[0][n - 1];
	}
};
```

