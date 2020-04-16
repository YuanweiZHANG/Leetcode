## 102. [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

> Medium

Given a binary tree, return the *level order* traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its level order traversal as:

```
[
  [3],
  [9,20],
  [15,7]
]
```



**Solutions:**

Define two queues named `que1` and `que2`. Each queue stores a level of Binary Tree.

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> results;
		if (!root)
			return results;
		queue<TreeNode*> que1, que2;
		que1.push(root);
		while (!que1.empty() || !que2.empty()) {
			if (que2.empty()) {
				vector<int> level;
				while (!que1.empty()) {
					TreeNode* curr = que1.front();
					level.push_back(curr->val);
					if (curr->left)
						que2.push(curr->left);
					if (curr->right)
						que2.push(curr->right);
					que1.pop();
				}
				if (!level.empty()) 
					results.push_back(level);
			}
			if (que1.empty()) {
				vector<int> level;
				while (!que2.empty()) {
					TreeNode* curr = que2.front();
					level.push_back(curr->val);
					if (curr->left)
						que1.push(curr->left);
					if (curr->right)
						que1.push(curr->right);
					que2.pop();
				}
				if (!level.empty())
					results.push_back(level);
			}
		}
		return results;
	}
};
```

