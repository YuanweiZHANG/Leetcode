## 53. [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

> Easy

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example:**

```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Follow up:**

If you have figured out the O(*n*) solution, try coding another solution using the divide and conquer approach, which is more subtle.



**Solutions:**

Dynamic Planning. Set `nums[i]` as the maximum sum of subarrays ending with index `i`.

Here is my solution class:

```c++
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) return 0;

		int max_sum = nums[0];
		for (int i = 1; i < len; ++i) {
			nums[i] = max(nums[i], nums[i] + nums[i - 1]);
			max_sum = max(max_sum, nums[i]);
		}
		return max_sum;
	}
};
```

