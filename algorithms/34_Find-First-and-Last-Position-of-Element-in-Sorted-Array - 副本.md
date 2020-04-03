## 34. [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

> Medium

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

Your algorithm's runtime complexity must be in the order of *O*(log *n*).

If the target is not found in the array, return `[-1, -1]`.

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```



**Solutions:**

Binary search for left index and right index.

Here is my solution class:

```c++
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0)
			return { -1,-1 };
		return { binarySearchL(nums, target, 0,len - 1), binarySearchR(nums,target,0,len - 1) };
	}

	int binarySearchL(vector<int>& nums, int target, int left, int right) {
		if (left > right)
			return -1;
		int mid = (left + right) >> 1;
		if (nums[mid] == target) {
			if (mid == left)
				return mid;
			else {
				if (nums[mid - 1] == target)
					return binarySearchL(nums, target, left, mid - 1);
				else
					return mid;
			}
		}
		else if (nums[mid] < target)
			return binarySearchL(nums, target, mid + 1, right);
		else 
			return binarySearchL(nums, target, left, mid - 1);
	}

	int binarySearchR(vector<int>& nums, int target, int left, int right) {
		if (left > right)
			return -1;
		int mid = (left + right) >> 1;
		if (nums[mid] == target) {
			if (mid == right)
				return mid;
			else {
				if (nums[mid + 1] == target)
					return binarySearchR(nums, target, mid + 1, right);
				else
					return mid;
			}
		}
		else if (nums[mid] < target)
			return binarySearchR(nums, target, mid + 1, right);
		else
			return binarySearchR(nums, target, left, mid - 1);
	}
};
```

