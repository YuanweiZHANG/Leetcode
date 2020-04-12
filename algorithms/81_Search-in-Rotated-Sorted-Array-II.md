##81. [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) 

> Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,0,1,2,2,5,6]` might become `[2,5,6,0,0,1,2]`).

You are given a target value to search. If found in the array return `true`, otherwise return `false`.

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Follow up:**

- This is a follow up problem to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/), where `nums` may contain duplicates.
- Would this affect the run-time complexity? How and why?



**Solutions:**

When `nums` has duplicates, we cannot easily decide whether target is in the left part or the right part. Therefore, we need to separately deal with the condition that `nums[mid] == nums[left]`.

Here is my solution class:

```c++
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
				return true;
			else if (nums[mid] > nums[left]) { // left part
				if (nums[mid] > target && target >= nums[left]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else if (nums[mid] < nums[left]) { // right part
				if (nums[mid] < target && target < nums[left]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			else { // nums[mid] == nums[left]: target can appear in both sides
				left++;
				while (left < nums.size() - 1 && nums[left - 1] == nums[left])
					left++;
			}
		}
		return false;
	}
};
```

