##525. [Contiguous Array](https://leetcode.com/problems/contiguous-array/) 

> Medium

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

**Example 1:**

```
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
```

**Example 2:**

```
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```



**Solutions:**

`mp[sum] = index` shows from `0` to `index`, the sum of those numbers is `sum`. Therefore, when `sum` shows again, the length is `i - index`. Before traversal, `mp[0] = -1`.

Here is my solution class:

```c++
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int sum = 0;
		int maxLength = 0;
		map<int/*sum*/, int/*index*/> mp;
		mp[0] = -1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0)
				sum--;
			else
				sum++;
			if (mp.find(sum) != mp.end()) {
				maxLength = max(maxLength, i - mp[sum]);
			}
			else
				mp[sum] = i;
		}
		return maxLength;
	}
};
```

