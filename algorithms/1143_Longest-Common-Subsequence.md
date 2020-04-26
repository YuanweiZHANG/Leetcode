## 1143. [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

> Medium

Given two strings `text1` and `text2`, return the length of their longest common subsequence.

A *subsequence* of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A *common subsequence* of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

**Example 1:**

```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

**Example 2:**

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

**Example 3:**

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

 

**Constraints:**

- `1 <= text1.length <= 1000`
- `1 <= text2.length <= 1000`
- The input strings consist of lowercase English characters only.



**Solutions:**

Dynamic Planning:

Define `dp[i][j]` as the longest common subsequence of `text1[0 ... i]` and `text2[0 ... j]`. If `text1[i] == text2[j]`, `dp[i][j] = dp[i-1][j-1]+1`; otherwise `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.

Here is my solution class:

```c++
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		if (text1 == "" || text2 == "")
			return 0;
		int len1 = text1.size(), len2 = text2.size();
		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		dp[0][0] = (text1[0] == text2[0]);
		for (int i = 1; i < len1; ++i) {
			if (text1[i] == text2[0])
				dp[i][0] = 1;
			else
				dp[i][0] = max(dp[i - 1][0], 0);
		}
		for (int i = 1; i < len2; ++i) {
			if (text1[0] == text2[i])
				dp[0][i] = 1;
			else
				dp[0][i] = max(dp[0][i - 1], 0);
		}
		for (int i = 1; i < len1; ++i) {
			for (int j = 1; j < len2; ++j) {
				if (text1[i] == text2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[len1 - 1][len2 - 1];
	}
};
```

