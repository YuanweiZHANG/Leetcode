##69. [Sqrt(x)](https://leetcode.com/problems/sqrtx/) 

> Easy

Implement `int sqrt(int x)`.

Compute and return the square root of *x*, where *x* is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

**Example 1:**

```
Input: 4
Output: 2
```

**Example 2:**

```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```



**Solutions:**

Sometimes `i*i>INT_MAX`. Therefore define `i` as `long long`. **When doing additions, subtractions, multiplications, and divisions, there are some cases could lead to overflow.**

Here is my solution class:

```c++
class Solution {
public:
	int mySqrt(int x) {
		long long i = 1;
		while (i*i <= x) {
			i++;
		}

		return i - 1;
	}
};
```

Also, we can binary search `i`

```c++
class Solution {
public:
	int mySqrt(int x) {
		long long start = 1, end = x;
		while (start <= end) {
			int mid = (start + end) >> 1;
			if (mid < x / mid) {
				start = mid + 1;
			}
			else if (mid > x / mid) {
				if ((mid - 1) < x / (mid - 1)) {
					return mid - 1;
				}
				else {
					end = mid - 1;
				}
			}
			else {
				return mid;
			}
		}
		return 0;
	}
};
```

