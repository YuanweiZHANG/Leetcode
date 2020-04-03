## 33. [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

> Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

You are given a target value to search. If found in the array return its index, otherwise return `-1`.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of *O*(log *n*).

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```



**Solutions:**

Binary search. Locate the target into left part or right part.

Here is my solution class:

```c++
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) return -1;
		return binarySearch(nums, target, 0, len - 1);
	}
	int binarySearch(vector<int> & nums, int target, int left, int right) {
		if (left > right) return -1;
		
		int mid = (left + right) >> 1;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < nums[right]) {
			if (nums[mid] < target && target <= nums[right])
				return binarySearch(nums, target, mid + 1, right);
			else
				return binarySearch(nums, target, left, mid - 1);
		}
		else {
			if (nums[left] <= target && target < nums[mid]) {
				return binarySearch(nums, target, left, mid - 1);
			}
			else 
				return binarySearch(nums, target, mid + 1, right);
		}
	}
};
```

