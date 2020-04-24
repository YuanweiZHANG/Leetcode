## 124. [Binary Tree Maximum Sum]

> Hard

Given a **non-empty** binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain **at least one node** and does not need to go through the root.

**Example 1:**

```
Input: [1,2,3]

       1
      / \
     2   3

Output: 6
```

**Example 2:**

```
Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
```



**Solutions:**

DFS to traversal the whole tree. Define `maxSum` as the max path sum. `maxPathSumCore` returns the max sum from root to its leaves. Therefore, `maxSum` should equal to `max(max(root->left's maxPathSumCore, root->right's maxPathSumCore), 0) + root->val`

**Be careful when root's left or right children has positive sum. At this situation, we should not add either left children's sum or right children's.**

Here is my solution class:

```c++
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int maxPath = INT_MIN;
		maxPathSumCore(root, maxPath);
		return maxPath;
	}
	int maxPathSumCore(TreeNode* root, int& maxSum) {
		if (!root)
			return 0;
		int leftSum = maxPathSumCore(root->left, maxSum);
		int rightSum = maxPathSumCore(root->right, maxSum);
		int sum = root->val;
		if (leftSum > 0)
			sum += leftSum;
		if (rightSum > 0)
			sum += rightSum;
		maxSum = max(maxSum, sum);
		return max(root->val, max(leftSum, rightSum) + root->val);
	}
};
```

