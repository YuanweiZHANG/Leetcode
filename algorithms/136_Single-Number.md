## 136. [Single Number](https://leetcode.com/problems/single-number/)

> Easy

Given a **non-empty** array of integers, every element appears *twice* except for one. Find that single one.

**Note:**

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**Example 1:**

```
Input: [2,2,1]
Output: 1
```

**Example 2:**

```
Input: [4,1,2,1,2]
Output: 4
```



**Solutions:**

`a ^ a = 0`. Therefore, exclusive or every elements in `nums`, the result is the single number.

Here is my solution class:

```c++
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (auto num : nums) {
			result ^= num;
		}
		return result;
	}
};
```

