## 97. [Interleaving String](https://leetcode.com/problems/interleaving-string/)

> Hard

Given *s1*, *s2*, *s3*, find whether *s3* is formed by the interleaving of *s1* and *s2*.

**Example 1:**

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
```

**Example 2:**

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
```



**Solutions:**

Recursion can lead to `Time Limit Exceeded`.

Here is my recursion solution class:

```c++
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size())
			return false;
		return isInterleaveCore(s1, s2, s3);
	}
	bool isInterleaveCore(string s1, string s2, string s3) {
		if (s1 == "" && s2 == "" && s3 == "")
			return true;
		if (s1 != "") {
			if (s3[0] == s1[0])
				if (isInterleaveCore(s1.substr(1), s2, s3.substr(1)))
					return true;
		}
		if (s2 != "")
			if (s3[0] == s2[0])
				if (isInterleaveCore(s1, s2.substr(1), s3.substr(1)))
					return true;
		return false;
	}
};
```

Dynamic planning:

`dp[i + 1][j + 1] == true` means `s3.substr(0, i + j + 1)` is formed by the interleaving of `s1.substr(0, i + 1)` and `s2.substr(0, j + 1)`.  `dp[s1.size()][s2.size()]` is the answer. 

`dp[i + 1][j + 1]` is true if and only if `dp[i][j + 1] == true` and `s1[i] == s3[i + j + 1]`, or `dp[i + 1][j] == true` and `s2[j] == s3[i + j + 1]`. 

```c++
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size())
			return false;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		
		dp[0][0] = true;

		for (int i = 0; i < s1.size(); ++i)
			dp[i + 1][0] = dp[i][0] && (s1[i] == s3[i]);

		for (int i = 0; i < s2.size(); ++i)
			dp[0][i + 1] = dp[0][i] && (s2[i] == s3[i]);

		for (int i = 0; i < s1.size(); ++i) {
			for (int j = 0; j < s2.size(); ++j) {
				dp[i + 1][j + 1] = ((dp[i][j + 1] && (s1[i] == s3[i + j + 1])) || (dp[i + 1][j] && (s2[j] == s3[i + j + 1])));
			}
		}
		return dp[s1.size()][s2.size()];
	}
	
};
```

