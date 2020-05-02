## 131. [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

> Medium

Given a string *s*, partition *s* such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of *s*.

**Example:**

```
Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
```



**Solutions:**

DFS.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> results;
		vector<string> curr;
		if (s.empty())
			return results;
		partitionCore(s, 0, results, curr);
		return results;
	}
	
	void partitionCore(string s, int start, vector<vector<string>>& results, vector<string>& curr) {
		if (start == s.size()) {
			results.push_back(curr);
			return;
		}
		for (int i = start; i < s.size(); ++i) {
			if (isPalindrome(s, start, i)) {
				curr.push_back(s.substr(start, i - start + 1));
				partitionCore(s, i + 1, results, curr);
				curr.pop_back();
			}
		}
	}

	bool isPalindrome(string s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};
```

