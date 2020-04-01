## 29. [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

> Medium

Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing `dividend` by `divisor`.

The integer division should truncate toward zero, which means losing its fractional part. For example, `truncate(8.345) = 8` and `truncate(-2.7335) = -2`.

**Example 1:**

```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
```

**Example 2:**

```
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
```

**Note:**

- Both dividend and divisor will be 32-bit signed integers.
- The divisor will never be 0.
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−$2^{31}$,  $2^{31}$ − 1]. For the purpose of this problem, assume that your function **returns $2^{31}$ − 1 when the division result overflows**.



**Solutions:**

Use bit operation to replace division. I also use subtraction. If subtraction is not allowed, you can use `^`.

Here is my solution class:

```c++
class Solution {
public:
	int divide(int dividend, int divisor) {
		bool negative = false;
		if (dividend < 0) negative = !negative;
		if (divisor < 0) negative = !negative;
		long long dividend_ = abs((long long)dividend);
		long long divisor_ = abs((long long)divisor);
		long long result = 0;
		int index = 0;
		while (dividend_ >= divisor_) { // >=
			divisor_ <<= 1;
			index++;
		}
		divisor_ >>= 1;
		index--;
		while (dividend_ > 0 && index >= 0) {
			if (dividend_ >= divisor_) { // >=
				dividend_ -= divisor_;
				divisor_ >>= 1;
				result += ((long long)1 << index);
				index--;
			}
			else {
				divisor_ >>= 1;
				index--;
			}
		}
		if (negative)
			result = -result;
		if (result > INT_MAX || result < INT_MIN)
			return INT_MAX;
		else return (int)result;
	}
};
```

