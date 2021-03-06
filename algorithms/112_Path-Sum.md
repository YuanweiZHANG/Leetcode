## 112. [Path Sum](https://leetcode.com/problems/path-sum/)

> Easy

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```

return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.



**Solutions:**

Recursion. Be careful the definition of leaf. Additionally, the `TreeNode->val` can be negative.

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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;
		return hasPathSumCore(root, sum);
	}
	bool hasPathSumCore(TreeNode* root, int& sum) {
		if (!root->left && !root->right && sum == root->val)
			return true;
		sum -= root->val;
		int flag = false;
		if (root->left)
			flag = flag || hasPathSumCore(root->left, sum);
		if (root->right)
			flag = flag || hasPathSumCore(root->right, sum);
		sum += root->val;
		return flag;
	}
};
```

