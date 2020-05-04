## 137. [Single Number II](https://leetcode.com/problems/single-number-ii/)

> Medium

Given a **non-empty** array of integers, every element appears *three* times except for one, which appears exactly once. Find that single one.

**Note:**

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**Example 1:**

```
Input: [2,2,3,2]
Output: 3
```

**Example 2:**

```
Input: [0,1,0,1,0,1,99]
Output: 99
```



**Solutions:**

Firstly, we can use map to solve this problem.

Here is my solution class:

```c++
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int/*num*/, int/*times*/> mp;
		for (auto num : nums)
			mp[num]++;
		for (auto it : mp)
			if (it.second == 1)
				return it.first;
		return -1;
	}
};
```

Then, similar to Problem No.136, there's also a bit operation method.

Define `once` and `twice` representing numbers exist once and twice. We all know that `a ^ a = 0` which means `a` shows twice. Therefore, when first `a` shows, `once = ~0 & (0 ^ a) = a` and `twice = ~a & (0 ^ a) = 0`; when the second `a` shows, `once = ~0 & (a ^ a) = 0` and `twice = ~0 & (0 ^ a) = a`; then the third `a` shows, `once = ~a & (0 ^ a) = 0` and `twice = ~0 & (a ^ a) = 0`.

After operate all numbers in `nums`, `once = the only single number`.

```c++
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int once = 0, twice = 0;
		for (auto num : nums) {
			once = ~twice & (once ^ num);
			twice = ~once & (twice ^ num);
		}
		return once;
	}
};
```

