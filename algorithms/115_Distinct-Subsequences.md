## 115. [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

> Hard

Given a string **S** and a string **T**, count the number of distinct subsequences of **S** which equals **T**.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

It's guaranteed the answer fits on a 32-bit signed integer.

**Example 1:**

```
Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
```

**Example 2:**

```
Input: S = "babgbag", T = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
```



**Solutions:**

Recursion version: `Time Limit Exceeded`

Here is my solution class:

```c++
class Solution {
public:
	int numDistinct(string s, string t) {
		if (s == "" || t == "")
			return 0;
		return numDistinctCore(s.c_str(), t.c_str());
	}
	int numDistinctCore(const char* s, const char* t) {
		if (*t == '\0')
			return 1;
		int result = 0;
		while (*s != '\0') {
			if (*s == *t) {
				result += numDistinctCore(s + 1, t + 1);
			}
			++s;
		}
		return result;
	}
};
```

Dynamic Planning:

Let `nums[j][i]` be distinct subsequences numbers of `s.substr(0, i + 1)`  which equals to `t.substr(0, j + 1)`. `nums[lenT - 1][lenS - 1]` is the answer. 

When `t[j] == s[i]`, `nums[j][i] = nums[j-1][i-1]+nums[j][i-1]`. This means `s[0, i]` and `t[0, j]` has `s[0, i-1]` and `t[0, j-1]` more than `s[0, i-1]` and `t[0, j]`.

```c++
class Solution {
public:
	int numDistinct(string s, string t) {
		if (s == "" || t == "")
			return 0;
		int lenS = s.size(), lenT = t.size();
		vector<vector<unsigned int>> nums(lenT, vector<unsigned int>(lenS, 0));
		if (t[0] == s[0])
			nums[0][0] = 1;
		for (int i = 1; i < lenS; ++i) {
			if (t[0] == s[i])
				nums[0][i] = nums[0][i - 1] + 1;
			else
				nums[0][i] = nums[0][i - 1];
		}
		for (int j = 1; j < lenT; ++j) {
			for (int i = 1; i < lenS; ++i) {
				if (t[j] == s[i]) {
					nums[j][i] = nums[j - 1][i - 1] + nums[j][i - 1];
				}
				else
					nums[j][i] = nums[j][i - 1];
			}
		}
		return nums[lenT - 1][lenS - 1];
	}
};
```

