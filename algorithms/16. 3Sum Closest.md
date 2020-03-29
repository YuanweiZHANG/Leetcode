## 16. [3Sum Closest](https://leetcode.com/problems/3sum-closest/)

> Medium

Given an array `nums` of *n* integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

**Example:**

```
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```



**Solutions:**

If we choose to use enumeration to find closet sum to target, the time complexity is $O(n^3)$. However, if we first sort the array, and fix the smallest number, then find the other two numbers, the **time complexity** is $O(n^2)$

For example, given array nums = [-1, 2, 1, -4] and target = 1. After sorting we have nums = [-4, -1, 1, 2]. Fix the smallest number, name it i1.  Then let i2 = i1 + 1, i3 = nums.size() - 1. Calculate the sum of i1, i2, i3 and update the closest. Then add 1 to i2 and minus 1 to i3 until i2 >= i3. At that moment, all conditions under fix i1 have been calculated. Then add 1 to i1 and continue this process.

Here is my solution class:

```
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) return 0;
		sort(nums.begin(), nums.end());
		int sum = 0, i2 = 0, i3 = 0;
		int diff = INT_MAX, result = 0, curr_diff = 0;
		
		for (int i1 = 0; i1 < n - 2; ++i1) {
			sum = nums[i1] + nums[i1 + 1] + nums[i1 + 2];
			if (sum > target) {
				curr_diff = sum - target;
				if (curr_diff < diff) {
					diff = curr_diff;
					result = sum;
				}
				continue;
			}
			sum = nums[i1] + nums[n - 1] + nums[n - 2];
			if (sum < target) {
				curr_diff = target - sum;
				if (curr_diff < diff) {
					diff = curr_diff;
					result = sum;
				}
				continue;
			}
			i2 = i1 + 1;
			i3 = n - 1;
			while (i2 < i3) {
				sum = nums[i1] + nums[i2] + nums[i3];
				if (sum == target) return sum;
				else if (sum < target) {
					i2++;
					curr_diff = target - sum;
					if (curr_diff < diff) {
						diff = curr_diff;
						result = sum;
					}
				}
				else {
					i3--;
					curr_diff = sum - target;
					if (curr_diff < diff) {
						diff = curr_diff;
						result = sum;
					}
				}
			}
		}
		return result;
	}
};
```

