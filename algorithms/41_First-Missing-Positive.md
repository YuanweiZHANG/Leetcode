## 41. [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

> Hard

Given an unsorted integer array, find the smallest missing positive integer.

**Example 1:**

```
Input: [1,2,0]
Output: 3
```

**Example 2:**

```
Input: [3,4,-1,1]
Output: 2
```

**Example 3:**

```
Input: [7,8,9,11,12]
Output: 1
```

**Note:**

Your algorithm should run in *O*(*n*) time and uses constant extra space.



**Solutions:**

Put the right number to the right place. Ignore zero, negative numbers and numbers bigger than `nums.size()`. If every number is in right place, the answer is `nums.size() + 1`. Or, there must has a number doesn't exist before so ignoring numbers bigger than `nums.size()` doesn't influence the answer. After placing, the first `nums[i] != i+1` is the one we need. 

Here is my solution class:

```c++
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) 
			return 1;
		for (int i = 0; i < len; ++i) {
			while (nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < len; ++i) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return len + 1;
	}
};
```

