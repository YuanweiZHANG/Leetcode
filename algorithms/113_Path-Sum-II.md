## 113. [Path Sum II](https://leetcode.com/problems/path-sum-ii/)

> Medium

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
```

Return:

```
[
   [5,4,11,2],
   [5,8,4,5]
]
```



**Solutions:**

Similar as Problem No.113.

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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> results;
		vector<int> curr;
		if (!root)
			return results;
		pathSumCore(results, root, sum, curr);
		return results;
	}
	void pathSumCore(vector<vector<int>>& results, TreeNode* root, int& sum, vector<int>& curr) {
		if (!root->left && !root->right && sum == root->val) {
			curr.push_back(root->val);
			results.push_back(curr);
			curr.pop_back();
			return;
		}
		sum -= root->val;
		curr.push_back(root->val);
		if (root->left)
			pathSumCore(results, root->left, sum, curr);
		if (root->right)
			pathSumCore(results, root->right, sum, curr);
		curr.pop_back();
		sum += root->val;
	}
};
```

