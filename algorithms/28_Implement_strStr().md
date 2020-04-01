## 28. [Implement strStr()](https://leetcode.com/problems/implement-strstr/)

> Easy

Implement [strStr()](http://www.cplusplus.com/reference/cstring/strstr/).

Return the index of the first occurrence of needle in haystack, or **-1** if needle is not part of haystack.

**Example 1:**

```
Input: haystack = "hello", needle = "ll"
Output: 2
```

**Example 2:**

```
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```

**Clarification:**

What should we return when `needle` is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when `needle` is an empty string. This is consistent to C's [strstr()](http://www.cplusplus.com/reference/cstring/strstr/) and Java's [indexOf()](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)).



**Solutions:**

It's a typical problem of string matching. Use KMP to solve this problem.

You should remember how to implement KMP algorithm.

Here is my solution class:

```c++
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")
			return 0;
		int len_haystack = haystack.size();
		int len_needle = needle.size();
		vector<int> next = getNext(needle);
		int i = 0, j = 0;
		while (i < len_haystack &&j < len_needle) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (j == len_needle) {
			return i - j;
		}
		else
			return -1;

	}
	vector<int> getNext(string needle) {
		int len = needle.size();
		vector<int> next(len);
		int i = 0, k = -1;
		next[0] = k;
		while (i < len - 1) {
			if (k == -1 || needle[i] == needle[k]) {
				i++;
				k++;
				next[i] = k;
			}
			else
				k = next[k];
		}
		return next;
	}
};
```

