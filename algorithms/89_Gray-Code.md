##89. [Gray Code](https://leetcode.com/problems/gray-code/) 

> Medium

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer *n* representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

**Example 1:**

```
Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
```

**Example 2:**

```
Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].
```



**Solutions:**

Gray codes appears in a principle: every bit circles in 0 1 1 0.

Here is my solution class:

```c++
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> grayNumber(1, 0);
		for (int i = 1; i < (1 << n); ++i) {
			int x = i;
			int gray = 0, index = 0;
			while (x) {
				if (x % 4 == 1 || x % 4 == 2) {
					gray |= (1 << index);
				}
				x = x >> 1;
				index++;	
			}
			grayNumber.push_back(gray);
		}
		return grayNumber;
	}
};
```

Additionally, there is another law of gray code: symmetry.

For example:

```
Input: n = 4
Output:
0000
0001
----
0011
0010
---
0110
0111
0101
0100
--
1100
1101
1111
1110
1010
1011
1001
1000
```

