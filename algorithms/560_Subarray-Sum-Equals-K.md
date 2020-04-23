## 560. [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

> Medium

Given an array of integers and an integer **k**, you need to find the total number of continuous subarrays whose sum equals to **k**.

**Example 1:**

```
Input:nums = [1,1,1], k = 2
Output: 2
```

**Note:**

1. The length of the array is in range [1, 20,000].
2. The range of numbers in the array is [-1000, 1000] and the range of the integer **k** is [-1e7, 1e7].



**Solutions:**

Sum of `[i, j]` equals sum of `[0, j]` minus sum of `[0, i]`. 

Here is my solution class:

```c++
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		int result = 0, sum = 0;
		map<int/*sum*/, int/*subarray numbers*/> mp;
		mp[0]++;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			result += mp[sum - k];
			mp[sum]++;
		}
		return result;
	}
};
```

