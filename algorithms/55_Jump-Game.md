## 55. [Jump Game](https://leetcode.com/problems/jump-game/)

> Medium

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

**Example 1:**

```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```



**Solutions:**

Mark when stepping into the `i`th, the farthest place we can jump is `farthest`. When `farthest` can reach `len - 1`, `return true`; when `farthest` trap into itself, `return false`.

Here is my solution class:

```c++
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int farthest = 0, len = nums.size();
		for (int i = 0; i < len; ++i) {
			farthest = max(farthest, nums[i] + i);
			if (farthest >= len - 1)
				return true;
			if (farthest <= i)
				return false;
		}
		return true;
	}
};
```

