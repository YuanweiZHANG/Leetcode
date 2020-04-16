## 107. [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

> Easy

Given a binary tree, return the *bottom-up level order* traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its bottom-up level order traversal as:

```
[
  [15,7],
  [9,20],
  [3]
]
```



**Solutions:**

Use stack to store every level.

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> results;
		if (!root)
			return results;
		stack<vector<int>> stk;
		vector<queue<TreeNode*>> que(2);
		que[0].push(root);
		while (!que[0].empty() || !que[1].empty()) {
			for (int i = 0; i < 2; ++i) {
				if (!que[i].empty()) {
					vector<int> level;
					while (!que[i].empty()) {
						TreeNode* curr = que[i].front();
						level.push_back(curr->val);
						if (curr->left)
							que[1 - i].push(curr->left);
						if (curr->right)
							que[1 - i].push(curr->right);
						que[i].pop();
					}
					stk.push(level);
				}
			}
		}
		while (!stk.empty()) {
			results.push_back(stk.top());
			stk.pop();
		}
		return results;
	}
};
```

