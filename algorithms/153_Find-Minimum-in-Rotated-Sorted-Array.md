## 153. [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

> Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,1,2,4,5,6,7]` might become  `[4,5,6,7,0,1,2]`).

Find the minimum element.

You may assume no duplicate exists in the array.

**Example 1:**

```
Input: [3,4,5,1,2] 
Output: 1
```

**Example 2:**

```
Input: [4,5,6,7,0,1,2]
Output: 0
```



**Solutions:**

Binary Search.

Here is my solution class:

```c++
class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left <= right) {
			if (nums[left] < nums[right])
				return nums[left];
			else if (nums[left] == nums[right]) // exists 1 element
				return nums[left];
			int mid = (left + right) >> 1;
			if (nums[mid] >= nums[left])
				left = mid + 1;
			else if (nums[mid] < nums[right]) {
				if (nums[mid] < nums[mid - 1])
					return nums[mid];
				else
					right = mid - 1;
			}
			else
				return nums[right];
		}
		return 0;
	}
};
```

