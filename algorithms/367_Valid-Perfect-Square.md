## 367. [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)

> Easy

Given a positive integer *num*, write a function which returns True if *num* is a perfect square else False.

**Note:** **Do not** use any built-in library function such as `sqrt`.

**Example 1:**

```
Input: 16
Output: true
```

**Example 2:**

```
Input: 14
Output: false
```



**Solutions:**

Binary search to find the square root.

Here is my solution class:

```c++
class Solution {
public:
	bool isPerfectSquare(int num) {
		long long left = 1, right = num;
		while (left <= right) {
			long long mid = (left + right) >> 1;
			long long mul = mid * mid;
			if (mul == num)
				return true;
			else if (mul < num)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return false;
	}
};
```

