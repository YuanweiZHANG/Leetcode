##387. [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/) 

> Easy

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

**Examples:**

```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```



**Solutions:**

Use map to store every character in the string.

Here is my solution class:

```c++
class Solution {
public:
	int firstUniqChar(string s) {
		if (s == "")
			return -1;
		map<char, int> mp;
		for (auto c : s) {
			mp[c]++;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (mp[s[i]] == 1)
				return i;
		}
		return -1;
	}
};
```

Also, since the string contains only lowercase letters, we can limit the map into an array `letters[26]`.