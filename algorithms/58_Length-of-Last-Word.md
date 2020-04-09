## 58. [Length of Last Word](https://leetcode.com/problems/length-of-last-word/)

> Easy

Given a string *s* consists of upper/lower-case alphabets and empty space characters `' '`, return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

**Note:** A word is defined as a **maximal substring** consisting of non-space characters only.

**Example:**

```
Input: "Hello World"
Output: 5
```



**Solutions:**

From the end of string `s` to start, count the number of none `' '`.

Here is my solution class:

```c++
class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		int length_last = 0;
		for (int i = len - 1; i >= 0; --i) {
			if (s[i] == ' ') {
				if (length_last == 0)
					continue;
				else break;
			}
			length_last++;
		}
		return length_last;
	}
};
```

