## 50. [Pow(x, n)](https://leetcode.com/problems/powx-n/)

> Medium

Implement [pow(*x*, *n*)](http://www.cplusplus.com/reference/valarray/pow/), which calculates *x* raised to the power *n* (xn).

**Example 1:**

```
Input: 2.00000, 10
Output: 1024.00000
```

**Example 2:**

```
Input: 2.10000, 3
Output: 9.26100
```

**Example 3:**

```
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

**Note:**

- -100.0 < *x* < 100.0
- *n* is a 32-bit signed integer, within the range [−231, 231 − 1]



**Solutions:**

Regard `n` as bit view. For example, `10` is `1010`.  $x^{10} = (((1^2 * x)^2)^2 * x)^2$. From highest bit to lowest bit, when bit `i` is `1`, `result = result * result * x`; when bit `i` is `0`, `result = result * result`. This process can avoid recursion and short the time complexity from $O(n)$ to $O(logn)$.

**When dealing with negative `n`, be cautious about `INT_MIN`.** 

Here is my solution class:

```c++
class Solution {
public:
	double myPow(double x, int n) {
		bool fraction = false;
		long long absn = n;
		if (n < 0) {
			fraction = true;
			absn = abs(absn);
		}
		else if (absn == 0)
			return 1.0;

		long long temp = absn;
		int highest = 0;
		while (temp) {
			highest++;
			temp >>= 1;
		}

		double result = 1;
		while (highest >= 0) {
			result *= result;
			if (absn & ((long long)1 << highest)) {
				result *= x;
			}
			highest--;
		}
		if (fraction) {
			result = 1.0 / result;
		}
		return result;
	}
};
```

