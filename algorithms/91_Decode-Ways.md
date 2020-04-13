##91. [Decode Ways](https://leetcode.com/problems/decode-ways/) 

> Medium

A message containing letters from `A-Z` is being encoded to numbers using the following mapping:

```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

Given a **non-empty** string containing only digits, determine the total number of ways to decode it.

**Example 1:**

```
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
```

**Example 2:**

```
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```



**Solutions:**

Similar as Fibonacci. When judging whether `s[i-1] s[i]` can decode, you cannot use `atoi` because `'01'` is invalid. 

Here is my solution class:

```c++
class Solution {
public:
	int numDecodings(string s) {
		if (s == "")
			return 0;
		vector<int> ways(s.size(), 0);
		if (s[0] >= '1' && s[0]<='9')
			ways[0] = 1;
		for (int i = 1; i < s.size(); ++i) {
			if (ways[i - 1] == 0) {
				ways[i] = 0;
				continue;
			}
			bool oneDigit = validOneDigit(s[i]);
			bool twoDigit = validTwoDigit(s[i - 1], s[i]);
			if (oneDigit) {
				ways[i] = ways[i - 1];
				if (twoDigit) {
					if (i == 1)
						ways[i] += 1;
					else
						ways[i] += ways[i - 2];
				}
			}
			else {
				if (twoDigit) {
					if (i == 1)
						ways[i] += 1;
					else
						ways[i] += ways[i - 2];
				}
			}
		}
		return ways[s.size() - 1];
	}

	bool validOneDigit(char a) {
		if (a >= '1'&& a <= '9')
			return true;
		else
			return false;
	}

	bool validTwoDigit(char a, char b) {
		if (a == '0' || a > '2')
			return false;
		if (a == '2'&& b > '6')
			return false;
		return true;
	}
};
```

