## 16. [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/>/)

> Medium

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

**Example:**

```
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

**Note:**

Although the above answer is in lexicographical order, your answer could be in any order you want.



**Solutions:**

It's a DFS problem. I used stack to replace the recursion.

Here is my solution class:

```c++
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int len = digits.size();
		vector<string> results;
		string result;
		stack<pair<char, int>> stk;
		for (int i = 0; i < len; ++i) {
			char letter = nextLetter(digits[i] - '0', '\0');
			stk.push(make_pair(letter, i));
			result.push_back(letter);
		}
		while (!stk.empty()) {
			pair<char, int> p = stk.top();
			char next = 0;
			if (p.second == len - 1) {
				results.push_back(result);
				stk.pop();
				result.pop_back();
				next = nextLetter(p.second, p.first);
				while (next == '\0') {
					if (p.second == 0) {
						return results;
					}
					p = stk.top();
					stk.pop();
					result.pop_back();
					next = nextLetter(p.second, p.first);
				}
				stk.push(make_pair(next, p.second));
				result.push_back(next);
			}
			else {
				next = nextLetter(digits[p.second + 1] - '0', '\0');
				stk.push(make_pair(next, p.second + 1));
				result.push_back(next);
			}
		}
		return results;
	}
	char nextLetter(int digit, char curr_letter) {
		if (curr_letter == '\0') {
			switch (digit) {
			case 2:
				return 'a';
			case 3:
				return 'd';
			case 4:
				return 'g';
			case 5:
				return 'j';
			case 6:
				return 'm';
			case 7:
				return 'p';
			case 8:
				return 't';
			case 9:
				return 'w';
			}
		}
		switch (curr_letter) {
		case 'c':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'v':
		case 'z':
			return '\0';
		default:
			return curr_letter + 1;
		}
	}
};
```

