## 844. [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)

> Easy

Given two strings `S` and `T`, return if they are equal when both are typed into empty text editors. `#` means a backspace character.

**Example 1:**

```
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
```

**Example 2:**

```
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
```

**Example 3:**

```
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
```

**Example 4:**

```
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
```

**Note**:

1. `1 <= S.length <= 200`
2. `1 <= T.length <= 200`
3. `S` and `T` only contain lowercase letters and `'#'` characters.

**Follow up:**

- Can you solve it in `O(N)` time and `O(1)` space?



**Solutions:**

`curr_s` and `curr_t` show the final size of `S` and `T`. If `curr_s != curr_t`, obviously return `false`. If `S[i] != T[i]`, the result is `false`, too.

Here is my solution class:

```c++
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int len_s = S.size(), len_t = T.size();
		int curr_s = 0, curr_t = 0;
		for (int i = 0; i < len_s; ++i) {
			if (S[i] != '#') {
				S[curr_s++] = S[i];
			}
			else {
				if (curr_s != 0) {
					curr_s--;
				}
			}
		}
		for (int i = 0; i < len_t; ++i) {
			if (T[i] != '#') {
				T[curr_t++] = T[i];
			}
			else {
				if (curr_t != 0) {
					curr_t--;
				}
			}
		}
		if (curr_s != curr_t)
			return false;
		else {
			for (int i = 0; i < curr_s; ++i) {
				if (S[i] != T[i])
					return false;
			}
			return true;
		}
	}
};
```

