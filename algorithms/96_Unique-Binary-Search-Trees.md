## 96. [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)

> Medium

Given *n*, how many structurally unique **BST's** (binary search trees) that store values 1 ... *n*?

**Example:**

```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```



**Solutions:**

When the root is `i`, there has totally `numTrees[i-1] * numTrees[n - i]` numbers of binary search trees. Because the root `i`'s left children tree has `i - 1` nodes and right children tree has `n - i` nodes. Therefore, the number of left children tree is the same as `numTrees[i - 1]`.

Here is my solution class:

```c++
class Solution {
public:
	int numTrees(int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		vector<int> nums(n + 1, 0);
		nums[0] = 1, nums[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				nums[i] += nums[j] * nums[i - 1 - j];
			}
		}
		return nums[n];
	}
};
```

