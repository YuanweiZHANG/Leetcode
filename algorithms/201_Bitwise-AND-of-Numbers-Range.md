## 201. [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

> Medium

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

**Example 1:**

```
Input: [5,7]
Output: 4
```

**Example 2:**

```
Input: [0,1]
Output: 0
```



**Solutions:**

Recursion.

Here is my solution class:

```c++
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m < n)
			return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
		else
			return m;
	}
};
```

