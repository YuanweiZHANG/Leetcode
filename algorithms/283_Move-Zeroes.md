## 283. [Move Zeroes](https://leetcode.com/problems/move-zeroes/)

> Easy

Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Example:**

```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```

**Note**:

1. You must do this **in-place** without making a copy of the array.
2. Minimize the total number of operations.



**Solutions:**

`zero_index` means the index of the last non-zero.

Here is my solution class:

```c++
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return;
		int zero_index = 0;
		for (int i = 0; i < len; ++i) {
			if (nums[i] != 0) {
				nums[zero_index++] = nums[i];
			}
		}
		for (int i = zero_index; i < len; ++i) {
			nums[i] = 0;
		}
		return;
	}
};
```

