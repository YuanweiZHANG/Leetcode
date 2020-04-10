##67. [Add Binary](https://leetcode.com/problems/add-binary/) 

> Easy

Given two binary strings, return their sum (also a binary string).

The input strings are both **non-empty** and contains only characters `1` or `0`.

**Example 1:**

```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**

```
Input: a = "1010", b = "1011"
Output: "10101"
```

 

**Constraints:**

- Each string consists only of `'0'` or `'1'` characters.
- `1 <= a.length, b.length <= 10^4`
- Each string is either `"0"` or doesn't contain any leading zero.



**Solutions:**

**Be careful when `len_b < len_a`, swap both `a`, `b` and `len_a`, `len_b`.** 

Here is my solution class:

```c++
class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		string result;
		int len_a = a.size(), len_b = b.size();
		if (len_b > len_a) {
			swap(a, b);
			swap(len_a, len_b);
		}
		for (int i = 0; i < len_b; ++i) {
			a[i] += b[i] - '0';
		}
		for (int i = 0; i < len_a; ++i) {
			if (a[i] > '1') {
				a[i] -= 2;
				if (i < len_a - 1)
					a[i + 1] += 1;
				else
					a.push_back('1');
			}
		}
		reverse(a.begin(), a.end());
		return a;
	}
};
```

