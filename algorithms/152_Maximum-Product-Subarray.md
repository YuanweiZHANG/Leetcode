##152. [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) 

> Medium

Given an integer array `nums`, find the contiguous subarray within an array (containing at least one number) which has the largest product.

**Example 1:**

```
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```



**Solutions:**

Use the trait of contiguous multiplication: $\sum_{i=1}^n a_i = \sum_{i=1}^{n-1} a_i\times a_n$.

Here is my solution class:

```c++
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<long long> products(n, 1);
		long long result = LLONG_MIN;
		for (int i = 0; i < n; ++i) {
			products[i] = nums[i];
			result = max(result, products[i]);
		}
		for (int k = 1; k < n; ++k) {
			for (int i = 0; i < n - k; ++i) {
				products[i] *= nums[i + k];
				result = max(result, products[i]);
			}
		}
		return result;
	}
};
```

However, this solution can lead to `Time Limit Exceeded`. We must find another faster way.

We notice that if all the elements in the `nums` are positive, the answer is multiplication of all numbers. If there exists one negative number, the answer is the maximum product of other subarrays except for the negative one. However, if there exist exactly two negative numbers, the answer becomes all numbers again. 

All cases discussed above don't include `0`. 

Whatever `nums` has negative numbers or not, maximum product of subarrays always shows up after current maximum product multiplies current number or current minimum product multiplies current number.

So, we can store `currMax` and `currMin` to get the answer.

```c++
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		else if (n == 1)
			return nums[0];
		int prevMax = nums[0], prevMin = nums[0], currMax = 0, currMin = 0;
		int result = nums[0];
		for (int i = 1; i < n; ++i) {
			currMax = max({ prevMax*nums[i], prevMin*nums[i], nums[i] });
			currMin = min({ prevMax*nums[i], prevMin*nums[i], nums[i] });
			result = max(result, currMax);

			prevMax = currMax;
			prevMin = currMin;
		}
		return result;
	}
};
```

