## 31. [Next Permutation](https://leetcode.com/problems/next-permutation/)

> Medium

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be **in-place** and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

`1,2,3` → `1,3,2`
`3,2,1` → `1,2,3`
`1,1,5` → `1,5,1`



**Solutions:**

Write some cases in your paper, then you will find the law.

Start from the right side, find the first element `nums[i]` that is smaller than `nums[i-1]`. Then swap `nums[i-1]` and the first element `nums[j]` from the right side which is bigger than `nums[i-1]`. At that moment, we find the correct number to place in `i-1`. Between `i` and `len-1`, the number is in descending order. The final step we need to do is reverse subarray $[i, len-1]$.

If we cannot find element `nums[i]` which means `nums` is totally in descending order. Therefore, reverse the entire array.

Test cases:

`1,2,3` → `1,3,2`

`3,2,1` → `1,2,3`

`1,2,3,4` → `1,2,4,3`

`4,3,2,1` → `1,2,3,4`

`1,5,1` → `5,1,1`

`1,1,5,2,1` → `1,5,1,1,2`

Here is my solution class:

```c++
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) 
			return;
		for (int i = len - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) {
				for (int j = len - 1; j >= i; --j) {
					// Necessary because nums may have some same numbers
					if (nums[j] > nums[i - 1]) {
						swap(nums[j], nums[i - 1]);
						break;
					}
				}
				for (int j = 0; j < (len - i) / 2; ++j) {
					swap(nums[i + j], nums[len - 1 - j]);
				}
				return;
			}
		}
		for (int i = 0; i < len / 2; ++i) {
			swap(nums[i], nums[len - 1 - i]);
		}
		return;
	}
};
```

