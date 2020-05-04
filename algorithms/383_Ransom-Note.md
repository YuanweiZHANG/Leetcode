## 383. [Ransom Note](https://leetcode.com/problems/ransom-note/)

> Easy

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

**Note:**
You may assume that both strings contain only lowercase letters.

```
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
```



**Solutions:**

Use a hashmap `letters` to store the letters' numbers in `magazine`. Then minus every letters in `ransomNote`. If the letter in `ransomNote` doesn't exist in `letters`, return `false`, or return `true`.

Here is my solution class:

```c++
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> letters(26, 0);
		for (auto letter : magazine) {
			letters[letter - 'a']++;
		}
		for (auto letter : ransomNote) {
			if (letters[letter - 'a']-- == 0)
				return false;
		}
		return true;
	}
};
```

